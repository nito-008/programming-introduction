// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/09a kameda[at]iit.tsukuba.ac.jp
// 08.01. OpenGLライブラリが使う行列

#include "ic2-CommonHeaders.h"

// *********************************************************************** 
// GLTools ***************************************************************


// +----------------------------------------------------
// MODELVIEW Matrix と PROJECTION を表示する
// +----------------------------------------------------
// 返値：なし（そもそもglGetFloatv()がvoid型）
// 引数sが有効な文字列であればその文字列をヘッダとして表示する
void ic2_ShowMATRIX (char *str) {
  GLfloat m[16]; // GL_MODELVIEW  matrix
  GLfloat p[16]; // GL_PROJECTION matrix

  glGetFloatv(GL_MODELVIEW_MATRIX , m); // MODELVIEWのスタックトップmatrixをmにコピー
  glGetFloatv(GL_PROJECTION_MATRIX, p); // PROJECTIONのスタックトップmatrixをpにコピー
  
  if (str != NULL) printf("<< %s >>\n", str);
  printf("MODELVIEW Matrix            PROJECTION Matrix\n");
  printf("%7.3f  %7.3f  %7.3f  %7.3f      %7.3f  %7.3f  %7.3f  %7.3f\n",
          m[ 0], m[ 4], m[ 8], m[12],     p[ 0], p[ 4], p[ 8], p[12]);
  printf("%7.3f  %7.3f  %7.3f  %7.3f      %7.3f  %7.3f  %7.3f  %7.3f\n", 
          m[ 1], m[ 5], m[ 9], m[13],     p[ 1], p[ 5], p[ 9], p[13]);
  printf("%7.3f  %7.3f  %7.3f  %7.3f      %7.3f  %7.3f  %7.3f  %7.3f\n", 
          m[ 2], m[ 6], m[10], m[14],     p[ 2], p[ 6], p[10], p[14]);
  printf("%7.3f  %7.3f  %7.3f  %7.3f      %7.3f  %7.3f  %7.3f  %7.3f\n", 
          m[ 3], m[ 7], m[11], m[15],     p[ 3], p[ 7], p[11], p[15]);
}
