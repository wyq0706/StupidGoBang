#ifndef _MAKEMOVE_
#define _MAKEMOVE_
//走法执行器

#include "define.h"

bool makeMove(int x,int y,int player);//执行走法

bool unMakeMove(int x,int y);//撤销走法

bool regretMove(); //用户反悔

#endif