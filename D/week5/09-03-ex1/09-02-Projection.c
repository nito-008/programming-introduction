// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/19a kameda[at]iit.tsukuba.ac.jp
// 09.02. 透視投影の導入（正式）

#include "ic2-CommonHeaders.h"


// *********************************************************************** 
// Projection ************************************************************

// +++--------------------------------------------------
// カメラの投影行列を設定
// +++--------------------------------------------------

// +----------------------------------------------------
// 直交投影
// +----------------------------------------------------
void ic2_SetUpCamera_Ortho (void) {
  // OpenGLのPROJECTION行列スタックにアクセス
  glMatrixMode(GL_PROJECTION);

  // PROJECTION行列スタックトップを単位行列で初期化
  glLoadIdentity(); 

  // 直交投影行列を生成するサポート関数 glOrtho を呼び出す
  // glOrtho(左端, 右端, 下端, 上端, 近接側クリッピング面,  遠方側クリッピング面)
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 
}

// +----------------------------------------------------
// 透視投影
// +----------------------------------------------------
void ic2_SetUpCamera_Perspective (void) {
  // OpenGLのPROJECTION行列スタックにアクセス
  glMatrixMode(GL_PROJECTION);

  // PROJECTION行列スタックトップを単位行列で初期化
  glLoadIdentity(); // 毎フレーム再設定するのでPROJECTION行列スタックトップの初期化必要

  // 透視投影行列を生成するサポート関数 gluPerspective を呼び出す
  // gluPerspective(垂直画角[deg], アスペクト比, 近距離限界, 遠距離限界)
  // 各引数は正確に計算して求めておくことが必要
  gluPerspective(36.87, 1.0, 2.0, 4.0);
}


