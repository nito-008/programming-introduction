// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/05a kameda[at]iit.tsukuba.ac.jp
// 07.04. イベントの追加（キーボード）

// ***********************************************************************
// CommonHeaders.h : common header files *********************************

// +++--------------------------------------------------
// どの部分ソースでも利用する可能性が高いライブラリ(関数)に
// 相当するヘッダファイル
// +++--------------------------------------------------

#include <stdio.h>   // printf()
#include <stdlib.h>  // exit()
#include <GL/glut.h> // gl*(), glut*()

// +++--------------------------------------------------
// この授業で作った関数のプロトタイプ
// +++--------------------------------------------------

// 07-03-Callback.c
void ic2_timerhandler(int keynumber);
void ic2_NormalKeyInput(unsigned char key, int x, int y);

// 07-03-EmbededObjects.c
void ic2_OpenGLLogo(float s);

// 07-03-Initialization.c
void ic2_BootWindow(char winname[]);

// 07-03-Projection.c
void ic2_SetUpCamera_Ortho(void);

// 07-03-Rendering.c
void ic2_DrawFrame(void);

// +++--------------------------------------------------
// この授業で使う大域変数の外部宣言
// +++--------------------------------------------------

// 07-05-MainFunction.c
extern float logoscale;
extern int is_colored;