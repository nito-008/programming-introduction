// Keisanki Joron 2 (Introduction to Computing II)
// Dept. of Engineering Systems, University of Tsukuba
// [UTF-8 / Unix]
// 計算機序論２・実習 (筑波大学工学システム学類)

// 2012/11/19a kameda[at]iit.tsukuba.ac.jp
// 11.04. ポリゴン表示

// ***********************************************************************
// CommonHeaders.h : common header files *********************************

// +++--------------------------------------------------
// どの部分ソースでも利用する可能性が高いライブラリ(関数)に
// 相当するヘッダファイル
// +++--------------------------------------------------

#include <stdio.h>   // printf()
#include <stdlib.h>  // exit(), calloc(), free()
#include <GL/glut.h> // gl*(), glut*()

// +++--------------------------------------------------
// マクロ
// +++--------------------------------------------------

#define IC2DEFAULTMODEL "Rin_000.txt"

// +++--------------------------------------------------
// 構造体
// +++--------------------------------------------------

// +----------------------------------------------------
// １つの点の３次元位置のための構造体
// +----------------------------------------------------
struct ic2POINT
{
  float x;
  float y;
  float z;
};

// +----------------------------------------------------
// RGB反射率のための構造体
// +----------------------------------------------------
struct ic2COLOR
{
  float r;
  float g;
  float b;
};

// +----------------------------------------------------
// １つの三角形パッチのための構造体
// 次の三角形パッチへのポインタを持つ。
// +----------------------------------------------------
struct ic2PATCH
{
  struct ic2POINT s;     // 頂点s
  struct ic2POINT t;     // 頂点t
  struct ic2POINT u;     // 頂点u
  struct ic2COLOR c;     // 色の強度 (通常は0.0 - 1.0)
  struct ic2PATCH *next; // 次の三角形パッチへのポインタ
};

// +++--------------------------------------------------
// この授業で作った関数のプロトタイプ
// +++--------------------------------------------------

// 07-04-Callback.c
void ic2_timerhandler(int keynumber);
void ic2_NormalKeyInput(unsigned char key, int x, int y);

// 07-03-EmbededObjects.c
void ic2_OpenGLLogo(float s);
void ic2_WORDLogo(float s);

// 07-03-Initialization.c
void ic2_BootWindow(char winname[]);

// 09-01-Projection.c
void ic2_SetUpCamera_Ortho(void);
void ic2_SetUpCamera_Perspective(void);

// 07-03-Rendering.c
void ic2_DrawFrame(void);

// 08-01
void ic2_ShowMATRIX(char *str);

// 10-02-ReadModel.c
int ic2_ReadModel(char *, struct ic2PATCH **);

// 11-04-FileObjects.c
int ic2_DrawModel(void);

// +++--------------------------------------------------
// この授業で使う大域変数の外部宣言
// +++--------------------------------------------------

// 11-04-MainFunction.c
extern float logoscale;
extern struct ic2PATCH *firstpatchptr;