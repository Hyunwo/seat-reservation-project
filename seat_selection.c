#include "func.h"

int main()
{
    int x[10][6]; //�����¼��� ǥ���ϱ� ���� 2���� �迭
    int i, j; //i�� ��, j�� ��

    //srand(time(NULL)); //rand()�Լ��� ����ϱ� �� �ʱ�ȭ

    for (i = 0; i < 10; i++) {  //���� 10ĭ
        for (j = 0; j < 6; j++) {   //���� 6ĭ
            x[i][j] = rand() % 2;   //�������� ������ �¼��� 1, �� �¼��� 0
        }
    }
    Print_UI(x);//�¼� ���� ȭ��
    Input_information();//����� ���� �Է�
    return 0;
}