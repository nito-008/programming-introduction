// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/09a kameda[at]iit.tsukuba.ac.jp
// 08.03. OpenGLでの行列操作の実際

#include "ic2-CommonHeaders.h"

float rotate_total = 0;

// ***********************************************************************
// Rendering *************************************************************

// +++--------------------------------------------------
// スクリーンに描画する
// +++--------------------------------------------------

// +----------------------------------------------------
// １フレーム分の描画
// +----------------------------------------------------
void ic2_DrawFrame(void)
{
  // (1) 描画バッファの初期化
  // 以前にglClearColor()で指定した色で塗り潰す
  glClear(GL_COLOR_BUFFER_BIT);

  // (2) カメラの設定
  ic2_SetUpCamera_Ortho();

  // (3) 光源の設置

  // (4) 物体の描画
  ic2_ShowMATRIX("Before");
  glMatrixMode(GL_MODELVIEW);
  //-- 【TR】実装ここから
  glLoadIdentity();
  ic2_ShowMATRIX("After I is loaded");
  glRotatef(rotate_total, 0, 0, 1);
  ic2_ShowMATRIX("After +45 degree rotation around Z axis");
  glTranslatef(0.7, 0, 0);
  ic2_ShowMATRIX("After +0.7 along X axis");
  //-- 【TR】実装ここまで
  ic2_OpenGLLogo(logoscale);
  rotate_total += 2;

  // (5) 描画バッファの切替
  glutSwapBuffers();
}
