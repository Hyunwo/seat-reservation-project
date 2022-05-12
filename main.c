
int option2 = 0;

void banbok(int num) {
	if (num == 0) {
		printf("1번 부터 8번까지 옵션중 하나를 골라 숫자를 입력해주세요.");
		banbok(OptionUiNum1());
	}
	else if (8 < num) {
		printf("1번 부터 8번까지 옵션중 하나를 골라 숫자를 입력해주세요.");
		banbok(OptionUiNum1());
	}
	else if (-1 >= num) {
		printf("1번 부터 8번까지 옵션중 하나를 골라 숫자를 입력해주세요.");
		banbok(OptionUiNum1());
	}
	else {
		option2 = num;
		view(option2);
	}

}

int MainView() {
	int selectNum = 0;
	printf("항공권 예매 프로그램\n");
	printf("1. 항공권 예매\n");
	printf("2. 항공권 취소\n");
	printf("3. 좌석 확인\n");
	printf("4. 종료\n");
	printf("옵션을 선택해 주세요: ");
	scanf("%d", &selectNum);

	if (selectNum == 1) {
		system("cls");
		banbok(OptionUiNum1());

	}
	else if (selectNum == 2) {
		printf("준비중 입니다.\n");
	}
	else if (selectNum == 3) {
		printf("준비중 입니다.\n");
	}
	else if (selectNum == 4) {
		printf("준비중 입니다.\n");
	}
	else {
		printf("오류\n");
	}

}

int OptionUiNum1() {

	int selectNum = 0;

	printf("옵션을 선택해 주세요.\n");
	printf("         목적지                    출발 날짜           항공사\n");
	printf("1.미국 - 로스엔젤레스(LAX)       2022/06/02/11:05      대한한공\n");
	printf("2.미국 - 로스엔젤레스(LAX)       2022/06/10/17:35      대한한공\n");
	printf("3.미국 - 로스엔젤레스(LAX)       2022/06/22/06:30      진에어\n");
	printf("4.미국 - 로스엔젤레스(LAX)       2022/06/28/18:15      진에어\n");
	printf("5.일본 - 도쿄                    2022/06/03/13:10      대한한공\n");
	printf("6.일본 - 도쿄                    2022/06/08/15:35      대한항공\n");
	printf("7.일본 - 도쿄                    2022/06/17/20:40      진에어\n");
	printf("8.일본 - 도쿄                    2022/06/30/07:50      진에어\n");
	printf("입력: ");
	scanf("%d", &selectNum);
	return selectNum;

}

int view(int option) {
	printf("선택한 옵션 넘버: %d\n", option2);
	if (option == 1) {
		printf("1.미국 - 로스엔젤레스(LAX)       2022/06/02/11:05      대한한공\n");
	}
	else if (option == 2) {
		printf("2.미국 - 로스엔젤레스(LAX)       2022/06/10/17:35      대한한공\n");
	}
	else if (option == 3) {
		printf("3.미국 - 로스엔젤레스(LAX)       2022/06/22/06:30      진에어\n");
	}
	else if (option == 4) {
		printf("4.미국 - 로스엔젤레스(LAX)       2022/06/28/18:15      진에어\n");
	}
	else if (option == 5) {
		printf("5.일본 - 도쿄                    2022/06/03/13:10      대한한공\n");
	}
	else if (option == 6) {
		printf("6.일본 - 도쿄                    2022/06/08/15:35      대한항공\n");
	}
	else if (option == 7) {
		printf("7.일본 - 도쿄                    2022/06/17/20:40      진에어\n");
	}
	else if (option == 8) {
		printf("8.일본 - 도쿄                    2022/06/30/07:50      진에어\n");
	}
	return option2;
}

int main(void){
	MainView();
	seat_selection();
	MainView();
	
	

}