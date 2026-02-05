// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 07.05. イベントの追加（ロゴの拡大縮小）

#include "ic2-CommonHeaders.h"


// *********************************************************************** 
// Rendering *************************************************************

// +++--------------------------------------------------
// スクリーンに描画する
// +++--------------------------------------------------

// +----------------------------------------------------
// １フレーム分の描画
// +----------------------------------------------------
void ic2_DrawFrame (void) {
  // (1) 描画バッファの初期化
  // 以前にglClearColor()で指定した色で塗り潰す
  glClear(GL_COLOR_BUFFER_BIT);

  // (2) カメラの設定
  ic2_SetUpCamera_Ortho();

  // (3) 光源の設置

  // (4) 物体の描画
  ic2_OpenGLLogo(logoscale);

  // (5) 描画バッファの切替
  glutSwapBuffers();
}

