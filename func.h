#pragma once	//�ߺ� ��� ����
#include <stdio.h>
#include <stdlib.h> //rand()�Լ��� ����ϱ� ���� ȣ��
#define MAX 2
//#include <time.h> //time()�Լ��� ����ϱ� ���� ȣ��

struct MyInfo
{
	char name[20];
	char gender[5];
	int yymmdd;
	char nationality[30];
	char email[30];
};

void Print_UI(int x[10][6]); //�¼� ���� ȭ�� �����
void Input_information();