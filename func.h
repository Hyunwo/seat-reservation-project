#pragma once	//중복 헤더 방지
#include <stdio.h>
#include <stdlib.h> //rand()함수를 사용하기 위해 호출
#define MAX 1
//#include <time.h> //time()함수를 사용하기 위해 호출

struct MyInfo
{
	char name[20];
	char gender[5];
	char birth[10];
	char nationality[30];
	char email[30];
};


int MainView();
int OptionUiNum1();
void banbok(int num);
int view(int option);
void seat_selection();
void Print_UI(int x[10][6]); //좌석 지정 화면 만들기
void Input_information();