// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 11.04. ポリゴン表示

#include "ic2-CommonHeaders.h"


// *********************************************************************** 
// FileObjects ***********************************************************

// +++--------------------------------------------------
// ファイルから読み込んだ3DCGの描画
// +++--------------------------------------------------

// +----------------------------------------------------
// ファイルからの物体を表示
// +----------------------------------------------------
int ic2_DrawModel (void) {
  struct ic2PATCH  *p = NULL; // パッチ構造体へのポインタ

  // firstpatchptrは大域変数として与えられる
  for (p = firstpatchptr; p != NULL; p = p->next) {
    // 面の色要素
    glColor3f(p->c.r, p->c.g, p->c.b);
    
    // 面を構成する３頂点を指示
    glBegin(GL_TRIANGLES); {
      glVertex3f(p->s.x, p->s.y, p->s.z);
      glVertex3f(p->t.x, p->t.y, p->t.z);
      glVertex3f(p->u.x, p->u.y, p->u.z);
    } glEnd();
    
  }
  return 0;
}
