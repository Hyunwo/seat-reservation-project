#pragma once	//중복 헤더 방지
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //rand()함수를 사용하기 위해 호출
#include <windows.h>//콘솔창 사용을 위해 호출(system)
#include <conio.h>//콘솔 입출력 함수를 제공(kbhit, getch)
//#include <time.h> //time()함수를 사용하기 위해 호출

//#define MAX 1
//키보드 값
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
void init(); //초기화 함수
int key();
void gotoxy(int x, int y);
int menu();
int OptionUiNum1();
int view(int option);
void seat_selection();
void Print_UI(int x[10][6]); //좌석 지정 화면 만들기
void Input_information();