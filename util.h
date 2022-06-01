#include <windows.h>//콘솔창 사용을 위해 호출(system)
#include <conio.h>//콘솔 입출력 함수를 제공(kbhit, getch)#pragma once

//키보드 값
#define UP 0
#define DOWN 1
#define SUBMIT 3
void gotoxy(int x, int y);
void init(); //초기화 함수
int menu_cursor();
int key();
