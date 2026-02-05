// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 07.03. ファイル分割に伴う修正

#include "ic2-CommonHeaders.h"

// ***********************************************************************
// EmbededObjects ********************************************************

// +++--------------------------------------------------
// ソース内部でのCG物体の直接描画
// +++--------------------------------------------------

// +----------------------------------------------------
// OpenGL Logoを描く
// +----------------------------------------------------
// s はスケーリングファクタ（s=1.0 で 概ね -1.0 〜 1.0 の大きさ）
void ic2_OpenGLLogo(float s)
{
  // 光源によるシェーディング効果を切る（と色の指定が直接色になる）
  glDisable(GL_LIGHTING);

  // 線の幅（画素単位）
  glLineWidth(1.0);

  // (R, G, B) 値域は 0.0 - 1.0
  if (is_colored > 0)
  {
    glColor3f(1.0, 0.0, 0.0);
  }
  else
  {
    glColor3f(1.0, 1.0, 1.0);
  }

  // glBegin(GL_LINES); から glEnd(); までの間は、
  // 「始点・終点」ごとに線分が描画される
  glBegin(GL_LINES);
  glVertex3f(s * -0.8, s * 0.8, 0.0);
  glVertex3f(s * -0.8, s * 0.2, 0.0); // O
  glVertex3f(s * -0.8, s * 0.2, 0.0);
  glVertex3f(s * -0.4, s * 0.2, 0.0); // O
  glVertex3f(s * -0.4, s * 0.2, 0.0);
  glVertex3f(s * -0.4, s * 0.8, 0.0); // O
  glVertex3f(s * -0.4, s * 0.8, 0.0);
  glVertex3f(s * -0.8, s * 0.8, 0.0); // O

  glVertex3f(s * -0.2, s * 0.6, 0.0);
  glVertex3f(s * -0.2, s * 0.0, 0.0); // p
  glVertex3f(s * -0.2, s * 0.6, 0.0);
  glVertex3f(s * 0.0, s * 0.6, 0.0); // p
  glVertex3f(s * 0.0, s * 0.6, 0.0);
  glVertex3f(s * 0.0, s * 0.2, 0.0); // p
  glVertex3f(s * 0.0, s * 0.2, 0.0);
  glVertex3f(s * -0.2, s * 0.2, 0.0); // p

  glVertex3f(s * 0.2, s * 0.4, 0.0);
  glVertex3f(s * 0.4, s * 0.4, 0.0); // e
  glVertex3f(s * 0.4, s * 0.4, 0.0);
  glVertex3f(s * 0.4, s * 0.6, 0.0); // e
  glVertex3f(s * 0.4, s * 0.6, 0.0);
  glVertex3f(s * 0.2, s * 0.6, 0.0); // e
  glVertex3f(s * 0.2, s * 0.6, 0.0);
  glVertex3f(s * 0.2, s * 0.2, 0.0); // e
  glVertex3f(s * 0.2, s * 0.2, 0.0);
  glVertex3f(s * 0.4, s * 0.2, 0.0); // e

  glVertex3f(s * 0.6, s * 0.6, 0.0);
  glVertex3f(s * 0.6, s * 0.2, 0.0); // n
  glVertex3f(s * 0.6, s * 0.6, 0.0);
  glVertex3f(s * 0.8, s * 0.6, 0.0); // n
  glVertex3f(s * 0.8, s * 0.6, 0.0);
  glVertex3f(s * 0.8, s * 0.2, 0.0); // n

  glVertex3f(s * 0.0, s * -0.2, 0.0);
  glVertex3f(s * -0.6, s * -0.2, 0.0); // G
  glVertex3f(s * -0.6, s * -0.2, 0.0);
  glVertex3f(s * -0.6, s * -0.8, 0.0); // G
  glVertex3f(s * -0.6, s * -0.8, 0.0);
  glVertex3f(s * 0.0, s * -0.8, 0.0); // G
  glVertex3f(s * 0.0, s * -0.8, 0.0);
  glVertex3f(s * 0.0, s * -0.5, 0.0); // G
  glVertex3f(s * 0.0, s * -0.5, 0.0);
  glVertex3f(s * -0.3, s * -0.5, 0.0); // G

  glVertex3f(s * 0.2, s * -0.2, 0.0);
  glVertex3f(s * 0.2, s * -0.8, 0.0); // L
  glVertex3f(s * 0.2, s * -0.8, 0.0);
  glVertex3f(s * 0.8, s * -0.8, 0.0); // L
  glEnd();

  // glBegin(GL_LINE_LOOP); から glEnd(); までの間は、
  // 全ての頂点を使った閉じた線分が描画される

  // 左上隅
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(s * -1.0, s * 1.0, 0.0);
  glVertex3f(s * -0.8, s * 1.0, 0.0);
  glVertex3f(s * -1.0, s * 0.8, 0.0);
  glEnd();

  // 右上隅
  glColor3f(0.1, 1.0, 1.0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(s * 0.8, s * 1.0, 0.0);
  glVertex3f(s * 1.0, s * 1.0, 0.0);
  glVertex3f(s * 1.0, s * 0.8, 0.0);
  glEnd();

  // 左下隅
  glColor3f(1.0, 0.1, 1.0);
  glBegin(GL_LINE_LOOP);
  glVertex3f(s * -1.0, s * -0.8, 0.0);
  glVertex3f(s * -0.8, s * -1.0, 0.0);
  glVertex3f(s * -1.0, s * -1.0, 0.0);
  glEnd();

  // 右下隅
  glColor3f(1.0, 1.0, 0.1);
  glBegin(GL_LINE_LOOP);
  glVertex3f(s * 0.8, s * -1.0, 0.0);
  glVertex3f(s * 1.0, s * -0.8, 0.0);
  glVertex3f(s * 1.0, s * -1.0, 0.0);
  glEnd();
}
