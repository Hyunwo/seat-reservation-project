#pragma once	//�ߺ� ��� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand()�Լ��� ����ϱ� ���� ȣ��
#include <windows.h>//�ܼ�â ����� ���� ȣ��(system)
#include <conio.h>//�ܼ� ����� �Լ��� ����(kbhit, getch)
//#include <time.h> //time()�Լ��� ����ϱ� ���� ȣ��

//#define MAX 1
//Ű���� ��
#define UP 0
#define DOWN 1
#define SUBMIT 3


struct MyInfo
{
	char name[20];
	char gender[10];
	char birth[10];
	char nationality[30];
	char email[30];
};

void doubleCheck();
void init(); //�ʱ�ȭ �Լ�
int key();
void gotoxy(int x, int y);
int menu();
int OptionUiNum1();
int view(int option);
void seat_selection();
void Print_UI(int x[10][6]); //�¼� ���� ȭ�� �����
void Input_information();