#include "func.h"

int option2;
int a;
extern int v;// ���� ��� ����, extern�� �տ� �ٿ��־ �ٸ� c���Ͽ��� ���� �̸��� v ������ ����ϸ� �װ��� ������.
extern int b;//���� ��� ����, extern�� �տ� �ٿ��־ �ٸ� c���Ͽ��� ���� �̸��� b ������ ����ϸ� �װ��� ������.
extern struct MyInfo person[MAX];


int MainView() {// ù ���� ȭ��
	system("cls");
	int selectNum = 0;
Back:
	printf("�װ��� ���� ���α׷�\n\n");
	printf("1. �װ��� ����\n\n");
	printf("2. �װ��� ���\n\n");
	printf("3. �¼� Ȯ��\n\n");
	printf("4. ����\n\n");
	printf("�ɼ��� ������ �ּ���: ");
	scanf("%d", &selectNum);

	if (selectNum == 1) {//1�� �����ϸ� ���� �޴��� OptionUiNum1()�Լ��� �Ѿ��.
		system("cls");
		OptionUiNum1();
	}
	else if (selectNum == 2) {//2�� �����ϸ� option2(������ �ð� ���� �����ϴ� �޴� ���ð�)�� 0���� �ʱ�ȭ, ������, ���� ���� �޴�
		option2 = 0;
		system("cls");
		MainView();//�ٽ� �޴��� ���ư�

	}
	if (selectNum == 3) {// 3�� �����ϸ� ������ �¼��� ������ �ҷ��´�.
		char save;
		FILE* fp = fopen("test.txt", "r");
		a = fscanf(fp, "%d", &option2);
		if (a == 0) {//2�޴��� ���� �Ǵ� �¼��� �������� �ʾ� option2�� 0�̸�(�ʱⰪ) ���� �¼��� ���ٰ� ǥ���� ���θ޴��� ����.
			printf("����� �¼��� �����ϴ�.\n");
			MainView();
		}
	Back1:
		system("cls");
		view(a);//view(������ ������ �ð� �޴� ��): ������ �ɼ��� ���ڸ� ������ �� ���� ���߾� ���� ǥ��.
		printf("��: %d ��:%d.\n", v, b);//�����ߴ� �ڸ� ��ȣ ǥ��
		printf("%s\n", person[0].name);//�Է��ߴ� �̸� ǥ��
		printf("%s\n", person[0].gender);//�Է��ߴ� ���� ǥ��
		printf("%s\n", person[0].birth);//�Է��ߴ� ������� ǥ��
		printf("%s\n", person[0].nationality);// �Է��ߴ� ��ű��� ǥ��
		printf("%s\n", person[0].email);// �Է��ߴ� �̸��� ǥ��
		printf("y�� �Է��ϸ� �޴��� ���ư��ϴ�. ");
		scanf("%s", &save);
		if (save == 'y') {
			system("cls");
			fclose(fp);
			MainView();
		}
		else {
			goto Back1;
		}

	}
	else if (selectNum == 4) {


		goto Back;
	}
	else {
		printf("����\n");

	}
}



int OptionUiNum1() {
	system("cls");
	int selectNum = 0;
Back:

	printf("\n\n\t\t\t�ɼ��� ������ �ּ���\n\n\n");
	printf("         ������                    ��� ��¥           �װ���\n\n");
	printf("1.�̱� - �ν���������(LAX)       2022/06/02/11:05      �����Ѱ�\n\n");
	printf("2.�̱� - �ν���������(LAX)       2022/06/10/17:35      �����Ѱ�\n\n");
	printf("3.�̱� - �ν���������(LAX)       2022/06/22/06:30      ������\n\n");
	printf("4.�̱� - �ν���������(LAX)       2022/06/28/18:15      ������\n\n");
	printf("5.�Ϻ� - ����                    2022/06/03/13:10      �����Ѱ�\n\n");
	printf("6.�Ϻ� - ����                    2022/06/08/15:35      �����װ�\n\n");
	printf("7.�Ϻ� - ����                    2022/06/17/20:40      ������\n\n");
	printf("8.�Ϻ� - ����                    2022/06/30/07:50      ������\n\n");
	printf("�Է�: ");
	scanf("%d", &selectNum);

	if (selectNum == 0) {
		printf("1�� ���� 8������ �ɼ��� �ϳ��� ��� ���ڸ� �Է����ּ���.");
		goto Back;
	}
	else if (8 < selectNum) {
		printf("1�� ���� 8������ �ɼ��� �ϳ��� ��� ���ڸ� �Է����ּ���.");
		goto Back;
	}
	else if (-1 >= selectNum) {
		printf("1�� ���� 8������ �ɼ��� �ϳ��� ��� ���ڸ� �Է����ּ���.");
		goto Back;
	}
	else {

		option2 = selectNum;

		FILE* fp = fopen("test.txt", "w+");
		fprintf(fp, "%d\n", option2);
		fclose(fp);
		view(option2);
		seat_selection();

	}

}

int view(int option) {//������ �ɼ��� ���ڸ� ������ �׿� ���� ������ �ɼ��� ������ ����ϴ� �Լ�
	printf("������ �ɼ� �ѹ�: %d\n", option2);
	if (option == 1) {
		printf("1.�̱� - �ν���������(LAX)       2022/06/02/11:05      �����Ѱ�\n");
	}
	else if (option == 2) {
		printf("2.�̱� - �ν���������(LAX)       2022/06/10/17:35      �����Ѱ�\n");
	}
	else if (option == 3) {
		printf("3.�̱� - �ν���������(LAX)       2022/06/22/06:30      ������\n");
	}
	else if (option == 4) {
		printf("4.�̱� - �ν���������(LAX)       2022/06/28/18:15      ������\n");
	}
	else if (option == 5) {
		printf("5.�Ϻ� - ����                    2022/06/03/13:10      �����Ѱ�\n");
	}
	else if (option == 6) {
		printf("6.�Ϻ� - ����                    2022/06/08/15:35      �����װ�\n");
	}
	else if (option == 7) {
		printf("7.�Ϻ� - ����                    2022/06/17/20:40      ������\n");
	}
	else if (option == 8) {
		printf("8.�Ϻ� - ����                    2022/06/30/07:50      ������\n");
	}
	return option2;
}



int main() {
	init();
	while (1) {
		int menuCode = menu();
		if (menuCode == 0) {
			//�װ��� ����
			//MainView();
			OptionUiNum1();
		}
		else if (menuCode == 1) {
			//�װ��� ���
			option2 = 0;
			system("cls");
			menu();
		}
		else if (menuCode == 2) {
			//�¼� Ȯ��
			doubleCheck();
			
		}
		else if (menuCode == 3) {
			//����
			return 0;
		}
		system("cls");
	}
	return 0;
}

//Ŀ�� ��ġ �̵��Լ�
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//�ܼ� �ڵ鰡������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menu() {
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
				gotoxy(x - 2, y-=2); //�� ĭ ���� �̵�
				printf(">"); //�ٽ� �׸���
			}
			break;
		}

		case DOWN: { //Ű ���� DOWN�ΰ��
			if (y < 23) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y+=2); //�� ĭ �Ʒ��� �̵�
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

void init() { //�ʱ�ȭ �Լ�
	system("mode con:cols=84 lines=30"); //col = ����, lines = ����
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� ��鰡������
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false �Ǵ� 0 : �����
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void doubleCheck() {
	char save;
	FILE* fp = fopen("test.txt", "r");
	a = fscanf(fp, "%d", &option2);
	if (a == 0) {//2�޴��� ���� �Ǵ� �¼��� �������� �ʾ� option2�� 0�̸�(�ʱⰪ) ���� �¼��� ���ٰ� ǥ���� ���θ޴��� ����.
		printf("����� �¼��� �����ϴ�.\n");
		menu();
	}
Back1:
	system("cls");
	view(a);//view(������ ������ �ð� �޴� ��): ������ �ɼ��� ���ڸ� ������ �� ���� ���߾� ���� ǥ��.
	printf("��: %d ��:%d.\n", v, b);//�����ߴ� �ڸ� ��ȣ ǥ��
	printf("%s\n", person[0].name);//�Է��ߴ� �̸� ǥ��
	printf("%s\n", person[0].gender);//�Է��ߴ� ���� ǥ��
	printf("%s\n", person[0].birth);//�Է��ߴ� ������� ǥ��
	printf("%s\n", person[0].nationality);// �Է��ߴ� ��ű��� ǥ��
	printf("%s\n", person[0].email);// �Է��ߴ� �̸��� ǥ��
	printf("y�� �Է��ϸ� �޴��� ���ư��ϴ�. ");
	scanf("%s", &save);
	if (save == 'y') {
		system("cls");
		fclose(fp);
		menu();
	}
	else {
		goto Back1;
	}
}