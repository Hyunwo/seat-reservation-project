#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
int v;
int b;
struct MyInfo person[MAX];

void Print_UI(int x[10][6]) {
    int i, j, k = 1; //i�� ��, j�� ��, k�� �� ��ȣ
    char c; //c�� ������ ���� ����



    while (1) {
        printf("�¼���ȣ�� ��, �� ������ �Է����ּ���!\n");
        printf("   ���ð��� : ��   ���úҰ��� : ��\n");
        printf("\t1 2 3      4 5 6\n");

        for (i = 0; i < 10; i++) {
            printf("\t");
            for (j = 0; j < 6; j++) {
                if (x[i][j] == 1) {     //����� �¼��̸� '��', ����ȣ�� 10�̸� �ٽ� 1�� �ʱ�ȭ
                    printf("��");
                    if (j == 2 && k != 10) {
                        printf("  %d  ", k);
                        k++;
                    }
                    else if (j == 2 && k == 10) {   //���� ���߱� ���� ���
                        printf("  %d ", k);
                        k = 1;
                    }
                }

                else {     //�� �¼��̸� '��', ����ȣ�� 10�̸� �ٽ� 1�� �ʱ�ȭ
                    printf("��");
                    if (j == 2 && k != 10) {
                        printf("  %d  ", k);
                        k++;
                    }
                    else if (j == 2 && k == 10) {   //���� ���߱� ���� ���
                        printf("  %d ", k);
                        k = 1;
                    }
                }
            }
            printf("\n");
        }

        //goto�� ����� ���� ���̺�
    ROW://��(����)
        printf("��(����)�� �Է����ּ��� : ");
        scanf("%d", &i);

        if (i < 1 || i > 10) {
            printf("������ 1 ~ 10���� �Դϴ�. �ٽ� �Է����ּ���.\n");
            goto ROW;   //1~10������ ����� ROW�� ���ư� �ٽ� �Է�
        }
    COLUMN://��(����)
        printf("��(����)�� �Է����ּ��� : ");
        scanf("%d", &j);

        if (j < 1 || j > 6) {
            printf("�ؿ��� 1~6���� �Դϴ�. �ٽ� �Է����ּ���.\n");
            goto COLUMN;    //1~6������ ����� COLUMN���� ���ư� �ٽ� �Է�
        }

        else if (x[i - 1][j - 1] == 1) {    //�¼��� ���ŵ� ���� 1�̹Ƿ� ROW�� ���ư� �ٽ� �Է�
            printf("������ �Ϸ�� �¼��Դϴ�. �ٽ� �Է����ּ���.\n");
            printf("------------------------------------------------------------------------------------\n");
            goto ROW;
        }

        else x[i - 1][j - 1] = 1;   //�¼��� �����߱� ������ ������ ��� ���� �ε����� 1����
        printf("������ �¼��� %d�� %d���Դϴ�.\n", i, j);
    GO:
        printf("------------------------------------------------------------------------------------\n");
        printf("�¼� ������ ����Ͻðڽ��ϱ�? (�߰� �¼� ������'y', ������������ 'n'�� �Է����ּ���)\n");
        scanf(" %c", &c);//�Է¹���?������ ���������� �Ͼ�� �����̽���...

        if (c == 'y') {
            system("cls");//Clean Screen
        }
        else if (c == 'n') {
            system("cls");
            v = i;//�� ���� v�� ����, v�� extern ���� selectNum1.c���� ������ �־��⶧���� v���� �����Ѵ�.
            b = j;//�� ���� b�� ����, b�� extern ���� selectNum1.c���� ������ �־��⶧���� b���� �����Ѵ�.

            Input_information();//���� �������� �̵�
            break;//while�� ����
        }
        else {
            printf("��'y'�� 'n'�߿��� �Է����ּ���.\n");
            goto GO;    //'y'��'n'�̿��� �Է��� GO�� ���ư� �ٽ� �Է�
        }
    }
}

void Input_information() {



    char save;
Back1:
    printf("������ ������ �Է����ּ���\n");

    printf("�̸� : ");
    scanf("%s", &person[0].name/*, sizeof(person[0].name) / sizeof(char)*/);


    printf("���� : ");
    scanf("%s", &person[0].gender);


    printf("�������(6�ڸ�) : ");
    scanf("%s", &person[0].birth);


    printf("���� : ");
    scanf("%s", &person[0].nationality);


    printf("�̸��� : ");
    scanf("%s", &person[0].email);



    printf("------------------------------------------------------------------------------------\n");
    printf("�Է� �� ������ Ȯ�����ּ���\n");
    printf("�̸� : %s\n", person[0].name);
    printf("���� : %s\n", person[0].gender);
    printf("������� : %s\n", person[0].birth);
    printf("���� : %s\n", person[0].nationality);
    printf("�̸��� : %s\n", person[0].email);
    printf("------------------------------------------------------------------------------------\n");

    //�� 2���̳� �Է��� �޳�???
Back2:
    printf("�����Ͻðڽ��ϱ�? (���� : y / ���� : n)\t");
    scanf(" %c", &save);

    if (save == 'y') {
        printf("����Ǿ����ϴ�.\n");

    }
    else if (save == 'n') {
        system("cls");
        goto Back1;//���� �ٽ� �Է�
    }
    else {
        printf("��'y'�� 'n'�߿��� �Է����ּ���.\n");
        goto Back2;
    }
    system("cls");//Clean Screen, ����ȭ������
    MainView();

}
