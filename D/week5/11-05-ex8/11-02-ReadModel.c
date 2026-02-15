// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/19a kameda[at]iit.tsukuba.ac.jp
// 11.02. プログラム統合

#include "ic2-CommonHeaders.h"

// *********************************************************************** 
// ReadModel *************************************************************

// +++--------------------------------------------------
// ３DCGモデルを記述したファイルを読み込む
// +++--------------------------------------------------

// -----------------------------------------------------
// 三角形パッチ構造体(ic2PATCH)リストの表示
// -----------------------------------------------------
int ic2_PrintPATCHList (struct ic2PATCH *firstpatchptr) {
  struct ic2PATCH *p = NULL;
  int np = 0;

  for (p = firstpatchptr; p != NULL; p = p->next) {
    printf("PATCH %2d: "
           "(%5.2f, %5.2f, %5.2f), (%5.2f, %5.2f, %5.2f), (%5.2f, %5.2f, %5.2f), "
           "rgb=[%4.2f, %4.2f, %4.2f] \n",
           np,
           p->s.x, p->s.y, p->s.z,
           p->t.x, p->t.y, p->t.z,
           p->u.x, p->u.y, p->u.z,
           p->c.r, p->c.g, p->c.b);
    np++;
  }

  return np;
}


// +----------------------------------------------------
// 三角形パッチ１つ分のメモリ確保と読込
// +----------------------------------------------------
static int ic2_InsertPATCH (struct ic2PATCH **firstpatchptr, char *onelinedata) {
  // (1) 文字列へのポインタは存在するか
  // (2) メモリ確保/下請け
  // (3) 値の読み込み
  // (4) ic2PATCHリスト構造への組み込み
  struct ic2PATCH *newpatch = NULL; // 三角形パッチ構造体ヘのポインタ
  int number_of_element = 0;        // 読み込めた項目数

  // (1) 文字列へのポインタは存在するか
  if (onelinedata == NULL) return -1;

  // (2) メモリ確保
  newpatch = (struct ic2PATCH *)calloc(1, sizeof(struct ic2PATCH));
  if (newpatch == NULL) {
    printf("ic2_InsertPATCH: Memory allocation failed.\n");
    return -2;
  }

  // (3) 値の読み込み
  number_of_element = 
    sscanf(onelinedata, "%f %f %f  %f %f %f  %f %f %f  %f %f %f", 
           &newpatch->s.x, &newpatch->s.y, &newpatch->s.z,
           &newpatch->t.x, &newpatch->t.y, &newpatch->t.z,
           &newpatch->u.x, &newpatch->u.y, &newpatch->u.z,
           &newpatch->c.r, &newpatch->c.g, &newpatch->c.b);
  if (number_of_element != 12) {
    printf("ic2_InsertPATCH: format error (%d elements found)\n", number_of_element);
    printf("ic2_InsertPATCH: \"%s\"\n", onelinedata);
    free(newpatch);
    return -3;
  }

  // (4) パッチに関する追加属性の事前計算

  // (5) ic2PATCHリスト構造への組み込み
  // *newpatch を 三角形パッチ集合の先頭に挿入
  newpatch->next = *firstpatchptr;
  *firstpatchptr = newpatch;
  return 0;
}

// +----------------------------------------------------
// 3DCGモデルファイルのオープン・読込・クローズ
// +----------------------------------------------------
int ic2_ReadModel(char *filename, struct ic2PATCH **firstpatchptr) {
  FILE *filetoopen = NULL; // FILE構造体へのポインタ
  int  patchnumber = 0; // パッチ数
  char oneline[256]; // １行分のバッファ,固定長にしておくとsizeof()が利用可能
  char firstword[256]; // コメント行かどうかの判定用
  int  linenumber = 0; // ファイル中の行番号

  // Foolproof
  if (filename == NULL) { 
    printf("Error: You need to specify file name to open.\n");
    return -1;
  }

  // ファイルのオープン
  filetoopen = fopen(filename, "r");
  if (filetoopen == NULL) {
    printf("Error: Failed to open/read \"%s\".\n", filename);
    return -2;
  }
  // ファイル名を表示
  printf("Reading model from \"%s\"\n", filename);

  // １行ずつ読込して登録
  while (fgets(oneline, sizeof(oneline), filetoopen) != NULL) {
    linenumber++;

    // もし行内に１文字もなければ（１単語もなければ）次行へ
    if (sscanf(oneline, "%256s", firstword) < 1)
      continue;
    // もし先頭が#で始まっていれば次行へ
    if (firstword[0] == '#') 
      continue;
    if (ic2_InsertPATCH(firstpatchptr, oneline)) {
      printf("Model reading is interrupted.\n");
      break;
    }
    patchnumber++;
  }

  // ファイルのクローズ
  if (fclose(filetoopen) != 0) {
    printf("Error: Failed to close \"%s\".\n", filename);
    // error, but we get data anyway...
  }

  printf("Finish reading the model (%d patches).\n", patchnumber);
  ic2_PrintPATCHList (*firstpatchptr);
 
  return patchnumber;
}
