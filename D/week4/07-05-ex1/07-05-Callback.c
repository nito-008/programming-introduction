// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 07.05. イベントの追加（ロゴの拡大縮小）

#include "ic2-CommonHeaders.h"

// ***********************************************************************
// Callback **************************************************************

// +++--------------------------------------------------
// GLUTでのイベント駆動型プログラミング
// +++--------------------------------------------------

// +----------------------------------------------------
// 「タイマー」で呼出し（繰り返すことで「一定間隔呼出し」化）
// +----------------------------------------------------
void ic2_timerhandler(int keynumber)
{
  glutPostRedisplay();                     // OpenGLのmainloopに戻ったら再描画を頼む
  glutTimerFunc(250, ic2_timerhandler, 0); // 250[ms]後にまた呼び出す
}

// +----------------------------------------------------
// 「キー」で呼出し
// +----------------------------------------------------
void ic2_NormalKeyInput(unsigned char key, int x, int y)
{
  switch (key)
  {

  case 'q': // 終了
    exit(0);
    break;

  case 's': // 　小さく
    logoscale = 0.5;
    break;

  case 'S': // 大きく
    logoscale = 0.95;
    break;

  case 'c': // 色を変更
    is_colored = 1;
    break;

  case 'C': // 元に戻す
    is_colored = 0;
    break;
  }
}
