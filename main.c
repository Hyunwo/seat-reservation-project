
int option2 = 0;

void banbok(int num) {
	if (num == 0) {
		printf("1�� ���� 8������ �ɼ��� �ϳ��� ��� ���ڸ� �Է����ּ���.");
		banbok(OptionUiNum1());
	}
	else if (8 < num) {
		printf("1�� ���� 8������ �ɼ��� �ϳ��� ��� ���ڸ� �Է����ּ���.");
		banbok(OptionUiNum1());
	}
	else if (-1 >= num) {
		printf("1�� ���� 8������ �ɼ��� �ϳ��� ��� ���ڸ� �Է����ּ���.");
		banbok(OptionUiNum1());
	}
	else {
		option2 = num;
		view(option2);
	}

}

int MainView() {
	int selectNum = 0;
	printf("�װ��� ���� ���α׷�\n");
	printf("1. �װ��� ����\n");
	printf("2. �װ��� ���\n");
	printf("3. �¼� Ȯ��\n");
	printf("4. ����\n");
	printf("�ɼ��� ������ �ּ���: ");
	scanf("%d", &selectNum);

	if (selectNum == 1) {
		system("cls");
		banbok(OptionUiNum1());

	}
	else if (selectNum == 2) {
		printf("�غ��� �Դϴ�.\n");
	}
	else if (selectNum == 3) {
		printf("�غ��� �Դϴ�.\n");
	}
	else if (selectNum == 4) {
		printf("�غ��� �Դϴ�.\n");
	}
	else {
		printf("����\n");
	}

}

int OptionUiNum1() {

	int selectNum = 0;

	printf("�ɼ��� ������ �ּ���.\n");
	printf("         ������                    ��� ��¥           �װ���\n");
	printf("1.�̱� - �ν���������(LAX)       2022/06/02/11:05      �����Ѱ�\n");
	printf("2.�̱� - �ν���������(LAX)       2022/06/10/17:35      �����Ѱ�\n");
	printf("3.�̱� - �ν���������(LAX)       2022/06/22/06:30      ������\n");
	printf("4.�̱� - �ν���������(LAX)       2022/06/28/18:15      ������\n");
	printf("5.�Ϻ� - ����                    2022/06/03/13:10      �����Ѱ�\n");
	printf("6.�Ϻ� - ����                    2022/06/08/15:35      �����װ�\n");
	printf("7.�Ϻ� - ����                    2022/06/17/20:40      ������\n");
	printf("8.�Ϻ� - ����                    2022/06/30/07:50      ������\n");
	printf("�Է�: ");
	scanf("%d", &selectNum);
	return selectNum;

}

int view(int option) {
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

int main(void){
	MainView();
	seat_selection();
	MainView();
	
	

}