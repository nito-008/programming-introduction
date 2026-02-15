// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/19a kameda[at]iit.tsukuba.ac.jp
// 11.04. ポリゴン表示

#include "ic2-CommonHeaders.h"


// *********************************************************************** 
// MainFunction ********************************************************** 

// +----------------------------------------------------
// 大域変数
// +----------------------------------------------------

float logoscale = 0.95;
struct ic2PATCH *firstpatchptr = NULL;

// +----------------------------------------------------
// Main Function
// +----------------------------------------------------
int main (int argc, char *argv[]) {
  char *modelfilenameptr = NULL;
  int numberofpatches = 0;

  // model ファイルの読み込み
  if (argc <= 1) {
    printf("Warning: no model file is specified, \"%s\" is assumed.\n", IC2DEFAULTMODEL);
    modelfilenameptr = IC2DEFAULTMODEL;
  } else {
        modelfilenameptr = argv[1];
  }
  numberofpatches = ic2_ReadModel(modelfilenameptr, &firstpatchptr);
  if (numberofpatches < 0) {
    printf("Error: invalid model \"%s\", reading failed.\n", modelfilenameptr);
    return 1;
  }
  printf("Number of Patches in the model = %d \n", numberofpatches);
 
  // glutライブラリによる引数の解釈
  glutInit(&argc, argv);

  // OpenGL Window の初期化
  ic2_BootWindow(argv[0]);

  // 無限ループの開始
  glutMainLoop();
  
  return 0;
}
