#pragma once	//�ߺ� ��� ����
#include <stdio.h>
#include <stdlib.h> //rand()�Լ��� ����ϱ� ���� ȣ��
#define MAX 1
//#include <time.h> //time()�Լ��� ����ϱ� ���� ȣ��

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
void Print_UI(int x[10][6]); //�¼� ���� ȭ�� �����
void Input_information();