#include <windows.h>//�ܼ�â ����� ���� ȣ��(system)
#include <conio.h>//�ܼ� ����� �Լ��� ����(kbhit, getch)#pragma once

//Ű���� ��
#define UP 0
#define DOWN 1
#define SUBMIT 3
void gotoxy(int x, int y);
void init(); //�ʱ�ȭ �Լ�
int menu_cursor();
int key();
