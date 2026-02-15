// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 07.05. イベントの追加（ロゴの拡大縮小）

#include "ic2-CommonHeaders.h"

// キー状態変数（押されている間は1、離されたら0）
int key_h_pressed = 0;
int key_j_pressed = 0;
int key_k_pressed = 0;
int key_l_pressed = 0;

// *********************************************************************** 
// Callback ************************************************************** 

// +++--------------------------------------------------
// GLUTでのイベント駆動型プログラミング
// +++--------------------------------------------------

// +----------------------------------------------------
// 「タイマー」で呼出し（繰り返すことで「一定間隔呼出し」化）
// +----------------------------------------------------
void ic2_timerhandler(int keynumber){
  glutPostRedisplay(); // OpenGLのmainloopに戻ったら再描画を頼む
  glutTimerFunc(16, ic2_timerhandler, 0); // 16[ms]後にまた呼び出す
}

// +----------------------------------------------------
// 「キー」で呼出し
// +----------------------------------------------------
void ic2_NormalKeyInput(unsigned char key, int x, int y){
  switch (key) {

  case 'q' : // 終了
    exit (0);
    break;

  case 's' : //　小さく
  	logoscale = 0.5;
  		break;

  case 'S' : // 大きく
   	logoscale = 0.95;
  		break;

  case 'h' : // 左回転
    key_h_pressed = 1;
    break;
  case 'j' : // 右回転
    key_j_pressed = 1;
    break;
  case 'k' : // 上回転
    key_k_pressed = 1;
    break;
  case 'l' : // 下回転
    key_l_pressed = 1;
    break;
  }
}

// +----------------------------------------------------
// 「キーリリース」で呼出し
// +----------------------------------------------------
void ic2_NormalKeyUp(unsigned char key, int x, int y){
  switch (key) {
  case 'h' :
    key_h_pressed = 0;
    break;
  case 'j' :
    key_j_pressed = 0;
    break;
  case 'k' :
    key_k_pressed = 0;
    break;
  case 'l' :
    key_l_pressed = 0;
    break;
  }
}
