#pragma once
#include <time.h> //time()�Լ��� ����ϱ� ���� ȣ��

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
void Print_UI(int x[10][6]); //�¼� ���� ȭ�� �����
void Input_information();
int menu_cursor();
void selectMenu();
int view(int option);
void doubleCheck();

int option2;
int a;
extern int v;// ���� ��� ����, extern�� �տ� �ٿ��־ �ٸ� c���Ͽ��� ���� �̸��� v ������ ����ϸ� �װ��� ������.
extern int b;//���� ��� ����, extern�� �տ� �ٿ��־ �ٸ� c���Ͽ��� ���� �̸��� b ������ ����ϸ� �װ��� ������.

struct MyInfo person[1];//������ ����� �տ� extern �ٿ��ֱ�

