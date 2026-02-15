// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/19b kameda[at]iit.tsukuba.ac.jp
// 11.05. ポリゴン表示・Depth付

#include "ic2-CommonHeaders.h"

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
  // depth buffer 初期化
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // depth test 有効化
  glEnable(GL_DEPTH_TEST);

  // (2) カメラの設定
  ic2_SetUpCamera_Perspective(); // 透視投影

  // (3) 光源の設置

  // (4) 物体の描画
  glMatrixMode(GL_MODELVIEW);
  {
    static float roty = 0.0; // Y軸回りの回転 [degree]
    static float rotx = 0.0;
    const float rotSpeed = 2.0; // 回転速度

    // キー入力に応じて回転角度を更新
    if (key_h_pressed) roty -= rotSpeed; // 左回転
    if (key_j_pressed) roty += rotSpeed; // 右回転
    if (key_k_pressed) rotx -= rotSpeed; // 上回転
    if (key_l_pressed) rotx += rotSpeed; // 下回転

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0); // 透視投影の描画範囲と対応必要
    glRotatef(roty, 0, 1, 0); // Y軸回りの回転
    glRotatef(rotx, 1, 0, 0); // X軸回りの回転
    ic2_OpenGLLogo(logoscale);
    ic2_DrawModel();

    // 回転角度の正規化
    if (roty <= -360.0) roty += 360.0;
    if (roty >= +360.0) roty -= 360.0;
    if (rotx <= -360.0) rotx += 360.0;
    if (rotx >= +360.0) rotx -= 360.0;
  }
  // (5) 描画バッファの切替
  glutSwapBuffers();
}
