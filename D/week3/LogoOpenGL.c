#include <stdio.h>   // printf()
#include <GL/glut.h> // gl*(), glut*()

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
  glColor3f(1.0, 1.0, 1.0);

  // glBegin(GL_LINES); から glEnd(); までの間は、
  // 「始点・終点」ごとに線分が描画される
  glBegin(GL_LINES);
  glVertex3f(s * -0.85, s * 0.3, 0.0);
  glVertex3f(s * -0.85, s * -0.3, 0.0); // W
  glVertex3f(s * -0.85, s * -0.3, 0.0);
  glVertex3f(s * -0.65, s * 0.0, 0.0); // W
  glVertex3f(s * -0.65, s * 0.0, 0.0);
  glVertex3f(s * -0.55, s * -0.3, 0.0); // W
  glVertex3f(s * -0.55, s * -0.3, 0.0);
  glVertex3f(s * -0.45, s * 0.3, 0.0); // W

  glVertex3f(s * -0.35, s * 0.3, 0.0);
  glVertex3f(s * -0.05, s * 0.3, 0.0); // O
  glVertex3f(s * -0.05, s * 0.3, 0.0);
  glVertex3f(s * -0.05, s * -0.3, 0.0); // O
  glVertex3f(s * -0.05, s * -0.3, 0.0);
  glVertex3f(s * -0.35, s * -0.3, 0.0); // O
  glVertex3f(s * -0.35, s * -0.3, 0.0);
  glVertex3f(s * -0.35, s * 0.3, 0.0); // O

  glVertex3f(s * 0.05, s * 0.3, 0.0);
  glVertex3f(s * 0.05, s * -0.3, 0.0); // R
  glVertex3f(s * 0.05, s * 0.3, 0.0);
  glVertex3f(s * 0.35, s * 0.3, 0.0); // R
  glVertex3f(s * 0.35, s * 0.3, 0.0);
  glVertex3f(s * 0.35, s * 0.0, 0.0); // R
  glVertex3f(s * 0.35, s * 0.0, 0.0);
  glVertex3f(s * 0.05, s * 0.0, 0.0); // R
  glVertex3f(s * 0.05, s * 0.0, 0.0);
  glVertex3f(s * 0.4, s * -0.3, 0.0); // R

  glVertex3f(s * 0.5, s * 0.3, 0.0);
  glVertex3f(s * 0.5, s * -0.3, 0.0); // D
  glVertex3f(s * 0.5, s * 0.3, 0.0);
  glVertex3f(s * 0.75, s * 0.3, 0.0); // D
  glVertex3f(s * 0.75, s * 0.3, 0.0);
  glVertex3f(s * 0.85, s * 0.1, 0.0); // D
  glVertex3f(s * 0.85, s * 0.1, 0.0);
  glVertex3f(s * 0.85, s * -0.1, 0.0); // D
  glVertex3f(s * 0.85, s * -0.1, 0.0);
  glVertex3f(s * 0.75, s * -0.3, 0.0); // D
  glVertex3f(s * 0.75, s * -0.3, 0.0);
  glVertex3f(s * 0.5, s * -0.3, 0.0); // D
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

// +----------------------------------------------------
// 直交投影
// +----------------------------------------------------
void ic2_SetUpCamera_Ortho(void)
{
  // OpenGLのPROJECTION行列スタックにアクセス
  glMatrixMode(GL_PROJECTION);

  // PROJECTION行列スタックトップを単位行列で初期化
  glLoadIdentity();

  // 直交投影行列を生成するサポート関数 glOrtho を呼び出す
  // glOrtho(左端, 右端, 下端, 上端, 近接側クリッピング面,  遠方側クリッピング面)
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //
}

// +----------------------------------------------------
// １フレーム分の描画
// +----------------------------------------------------
void ic2_DrawFrame(void)
{
  static int loopmax = 4;     // loopmax回ごとに１回色を変える
  static int loopcounter = 0; // 何回目かを覚えておく変数

  // (0) 指定色の変更
  loopcounter++;
  if (loopcounter == loopmax)
  {
    glClearColor(0.0, 1.0, 0.0, 0.0); // ４回に１回は緑
    loopcounter = 0;
  }
  else
  {
    glClearColor(0.0, 0.0, 0.0, 0.0); // ４回に３回は黒
  }

  // (1) 描画バッファの初期化
  // 以前にglClearColor()で指定した色で塗り潰す
  glClear(GL_COLOR_BUFFER_BIT);

  // (2) カメラの設定
  ic2_SetUpCamera_Ortho();

  // (3) 光源の設置

  // (4) 物体の描画
  ic2_OpenGLLogo(0.95);

  // (5) 描画バッファの切替
  glutSwapBuffers();
}

// +----------------------------------------------------
// タイマーで呼出し（繰り返すことで「一定間隔呼出し」化）
// +----------------------------------------------------
void ic2_timerhandler(int keynumber)
{
  glutPostRedisplay();                     // OpenGLのmainloopに戻ったら再描画を頼む
  glutTimerFunc(250, ic2_timerhandler, 0); // 250[ms]後にまた呼び出す
}

// +----------------------------------------------------
// OpenGLとしてのWindowの初期化
// +----------------------------------------------------
void ic2_BootWindow(char winname[])
{

  // DisplayModeの設定(それぞれを|で繋ぐ)
  //   GLUT_DOUBLE ... ダブルバッファ
  //   GLUT_RGB    ... RGB表色モード
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

  // 準備(Initialization)が済んだらウィンドウを開く
  glutCreateWindow(winname);

  // Callback関数を設定 (イベント処理)
  glutDisplayFunc(ic2_DrawFrame);          // フレームを（再）描画するために呼び出す関数
  glutTimerFunc(250, ic2_timerhandler, 0); // 250[ms]後に呼び出す関数

  // ウィンドウ全体を書き直すときの色(R,G,B,0) ここでは黒
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

// +----------------------------------------------------
// Main Function
// +----------------------------------------------------
int main(int argc, char *argv[])
{

  // glutライブラリによる引数の解釈
  glutInit(&argc, argv);

  // OpenGL Window の初期化
  ic2_BootWindow(argv[0]);

  // 無限ループの開始
  glutMainLoop();

  return 0;
}
