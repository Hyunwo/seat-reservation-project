#pragma once
#include <time.h> //time()함수를 사용하기 위해 호출

struct MyInfo
{
	char name[20];
	char gender[5];
	char birth[10];
	char nationality[30];
	char email[30];
};

int OptionUiNum1();
void seat_selection();
void Print_UI(int x[10][6]); //좌석 지정 화면 만들기
void Input_information();
int menu_cursor();
void selectMenu();
int view(int option);
void doubleCheck();

int option2;
int a;
extern int v;// 행을 담는 변수, extern을 앞에 붙여주어서 다른 c파일에서 같은 이름인 v 변수를 사용하면 그값을 공유함.
extern int b;//열을 담는 변수, extern을 앞에 붙여주어서 다른 c파일에서 같은 이름인 b 변수를 사용하면 그값을 공유함.

struct MyInfo person[1];//밖으로 뺄경우 앞에 extern 붙여주기

