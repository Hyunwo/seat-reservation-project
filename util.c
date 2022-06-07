#include"main.h"
#include"util.h"
#include"function.h"


void init() { //�ʱ�ȭ �Լ�
	system("mode con:cols=84 lines=30"); //col = ����, lines = ����
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� ��鰡������
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false �Ǵ� 0 : �����
	ConsoleCursor.dwSize = 1; //Ŀ�� ������ (1 ~ 100)
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

int key() {
	int key;

	while (1)
	{
		if (_kbhit())//Ű���尡 �Էµ� �������� ����
		{
			key = _getch();//C4996���� _���̴ϱ� �ذ�
			if (key == 224 || key == 0)//����Ű�� 2���� ���� ��ȯ - ���� 224��ȯ
			{
				key = _getch();
				switch (key)
				{
				case 72://��ĵ�ڵ� - �ƽ�Ű�ڵ�� ǥ������ ���ϴ� 2����Ʈ¥������ ǥ���� �ڵ�
					return UP;
					break;
				case 80:
					return DOWN;
					break;
				default:
					break;
				}
			}
			else if (key == 13) { //key == Enter
				return SUBMIT;
			}

		}
	}
}

//Ŀ�� ��ġ �̵��Լ�
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ鰡������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menu_cursor() {
	int x = 34;
	int y = 17;
	gotoxy(x - 3, y - 13);
	printf("�װ��� ���� ���α׷�");
	gotoxy(x - 2, y);
	printf(">  �װ��� ����");
	gotoxy(x, y + 2);
	printf(" �װ��� ��� ");
	gotoxy(x, y + 4);
	printf("  �¼� Ȯ�� ");
	gotoxy(x, y + 6);
	printf("    ����  ");

	while (1) { //���� �ݺ�
		int n = key(); //Ű �� �޾ƿ���
		switch (n) {
		case UP: { //Ű ���� UP�ΰ��
			if (y > 17) {
				gotoxy(x - 2, y);
				printf(" "); //�����
				gotoxy(x - 2, y -= 2); //�� ĭ ���� �̵�
				printf(">"); //�ٽ� �׸���
			}
			break;
		}

		case DOWN: { //Ű ���� DOWN�ΰ��
			if (y < 23) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y += 2); //�� ĭ �Ʒ��� �̵�
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 17;
		}
		}
	}
}
