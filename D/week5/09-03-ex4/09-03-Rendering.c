// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/19a kameda[at]iit.tsukuba.ac.jp
// 09.03. 透視投影下での回転と移動

#include "ic2-CommonHeaders.h"

#include <math.h>

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
  ic2_SetUpCamera_Perspective(); // 透視投影

  // (3) 光源の設置

  // (4) 物体の描画
  glMatrixMode(GL_MODELVIEW);
  {
    static float roty = 0.0; // Y軸回りの回転 [degree]
    static double offsetz = 0.0;
    glLoadIdentity();
    glTranslatef(0.0, 0.0, 1.0 * sin(offsetz) - 3.0); // 透視投影の描画範囲と対応必要
    glRotatef(roty, -1, 0, 0);                        // X軸回りの回転
    ic2_OpenGLLogo(logoscale);
    offsetz += 0.02;
    if (roty <= -360.0)
      roty += 360.0;
  }
  // (5) 描画バッファの切替
  glutSwapBuffers();
}
