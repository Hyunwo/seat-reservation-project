#include "func.h"

int option2;
int a;
extern int v;// 행을 담는 변수, extern을 앞에 붙여주어서 다른 c파일에서 같은 이름인 v 변수를 사용하면 그값을 공유함.
extern int b;//열을 담는 변수, extern을 앞에 붙여주어서 다른 c파일에서 같은 이름인 b 변수를 사용하면 그값을 공유함.
extern struct MyInfo person[MAX];


int MainView() {// 첫 메인 화면
	system("cls");
	int selectNum = 0;
Back:
	printf("항공권 예매 프로그램\n\n");
	printf("1. 항공권 예매\n\n");
	printf("2. 항공권 취소\n\n");
	printf("3. 좌석 확인\n\n");
	printf("4. 종료\n\n");
	printf("옵션을 선택해 주세요: ");
	scanf("%d", &selectNum);

	if (selectNum == 1) {//1을 선택하면 예약 메뉴인 OptionUiNum1()함수로 넘어간다.
		system("cls");
		OptionUiNum1();
	}
	else if (selectNum == 2) {//2를 선택하면 option2(도착지 시간 등을 설정하는 메뉴 선택값)를 0으로 초기화, 삭제함, 예약 삭제 메뉴
		option2 = 0;
		system("cls");
		MainView();//다시 메뉴로 돌아감

	}
	if (selectNum == 3) {// 3을 선택하면 예약한 좌석의 정보를 불러온다.
		char save;
		FILE* fp = fopen("test.txt", "r");
		a = fscanf(fp, "%d", &option2);
		if (a == 0) {//2메뉴를 통해 또는 좌석을 예약하지 않아 option2가 0이면(초기값) 예약 좌석이 없다고 표시후 메인메뉴로 간다.
			printf("예약된 좌석이 없습니다.\n");
			MainView();
		}
	Back1:
		system("cls");
		view(a);//view(선택한 도착지 시간 메뉴 값): 선택한 옵션의 숫자를 넣으면 그 값에 맞추어 정보 표시.
		printf("행: %d 열:%d.\n", v, b);//예약했던 자리 번호 표시
		printf("%s\n", person[0].name);//입력했던 이름 표시
		printf("%s\n", person[0].gender);//입력했던 성별 표시
		printf("%s\n", person[0].birth);//입력했던 생년월일 표시
		printf("%s\n", person[0].nationality);// 입력했던 출신국가 표시
		printf("%s\n", person[0].email);// 입력했던 이메일 표시
		printf("y를 입력하면 메뉴로 돌아갑니다. ");
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
		printf("오류\n");

	}
}



int OptionUiNum1() {
	system("cls");
	int selectNum = 0;
Back:

	printf("\n\n\t\t\t옵션을 선택해 주세요\n\n\n");
	printf("         목적지                    출발 날짜           항공사\n\n");
	printf("1.미국 - 로스엔젤레스(LAX)       2022/06/02/11:05      대한한공\n\n");
	printf("2.미국 - 로스엔젤레스(LAX)       2022/06/10/17:35      대한한공\n\n");
	printf("3.미국 - 로스엔젤레스(LAX)       2022/06/22/06:30      진에어\n\n");
	printf("4.미국 - 로스엔젤레스(LAX)       2022/06/28/18:15      진에어\n\n");
	printf("5.일본 - 도쿄                    2022/06/03/13:10      대한한공\n\n");
	printf("6.일본 - 도쿄                    2022/06/08/15:35      대한항공\n\n");
	printf("7.일본 - 도쿄                    2022/06/17/20:40      진에어\n\n");
	printf("8.일본 - 도쿄                    2022/06/30/07:50      진에어\n\n");
	printf("입력: ");
	scanf("%d", &selectNum);

	if (selectNum == 0) {
		printf("1번 부터 8번까지 옵션중 하나를 골라 숫자를 입력해주세요.");
		goto Back;
	}
	else if (8 < selectNum) {
		printf("1번 부터 8번까지 옵션중 하나를 골라 숫자를 입력해주세요.");
		goto Back;
	}
	else if (-1 >= selectNum) {
		printf("1번 부터 8번까지 옵션중 하나를 골라 숫자를 입력해주세요.");
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

int view(int option) {//선택한 옵션의 숫자를 넣으면 그에 맞춰 선택한 옵션의 정보를 출력하는 함수
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



int main() {
	init();
	while (1) {
		int menuCode = menu();
		if (menuCode == 0) {
			//항공권 예매
			//MainView();
			OptionUiNum1();
		}
		else if (menuCode == 1) {
			//항공권 취소
			option2 = 0;
			system("cls");
			menu();
		}
		else if (menuCode == 2) {
			//좌석 확인
			doubleCheck();
			
		}
		else if (menuCode == 3) {
			//종료
			return 0;
		}
		system("cls");
	}
	return 0;
}

//커서 위치 이동함수
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔 핸들가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menu() {
	int x = 34;
	int y = 17;
	gotoxy(x - 3, y - 13);
	printf("항공권 예매 프로그램");
	gotoxy(x - 2, y);
	printf(">  항공권 예매");
	gotoxy(x, y + 2);
	printf(" 항공권 취소 ");
	gotoxy(x, y + 4);
	printf("  좌석 확인 ");
	gotoxy(x, y + 6);
	printf("    종료  ");
	
	while (1) { //무한 반복
		int n = key(); //키 값 받아오기
		switch (n) {
		case UP: { //키 값이 UP인경우
			if (y > 17) {
				gotoxy(x - 2, y);
				printf(" "); //지우기
				gotoxy(x - 2, y-=2); //두 칸 위로 이동
				printf(">"); //다시 그리기
			}
			break;
		}

		case DOWN: { //키 값이 DOWN인경우
			if (y < 23) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y+=2); //두 칸 아래로 이동
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
		if (_kbhit())//키보드가 입력된 상태인지 조사
		{
			key = _getch();//C4996오류 _붙이니까 해결
			if (key == 224 || key == 0)//방향키는 2개의 값을 반환 - 먼저 224반환
			{
				key = _getch();
				switch (key)
				{
				case 72://스캔코드 - 아스키코드로 표현하지 못하는 2바이트짜리까지 표현한 코드
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

void init() { //초기화 함수
	system("mode con:cols=84 lines=30"); //col = 가로, lines = 세로
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 헨들가져오기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false 또는 0 : 숨기기
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void doubleCheck() {
	char save;
	FILE* fp = fopen("test.txt", "r");
	a = fscanf(fp, "%d", &option2);
	if (a == 0) {//2메뉴를 통해 또는 좌석을 예약하지 않아 option2가 0이면(초기값) 예약 좌석이 없다고 표시후 메인메뉴로 간다.
		printf("예약된 좌석이 없습니다.\n");
		menu();
	}
Back1:
	system("cls");
	view(a);//view(선택한 도착지 시간 메뉴 값): 선택한 옵션의 숫자를 넣으면 그 값에 맞추어 정보 표시.
	printf("행: %d 열:%d.\n", v, b);//예약했던 자리 번호 표시
	printf("%s\n", person[0].name);//입력했던 이름 표시
	printf("%s\n", person[0].gender);//입력했던 성별 표시
	printf("%s\n", person[0].birth);//입력했던 생년월일 표시
	printf("%s\n", person[0].nationality);// 입력했던 출신국가 표시
	printf("%s\n", person[0].email);// 입력했던 이메일 표시
	printf("y를 입력하면 메뉴로 돌아갑니다. ");
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