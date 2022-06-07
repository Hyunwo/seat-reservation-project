#include"main.h"
#include"util.h"
#include"function.h"


void init() { //초기화 함수
	system("mode con:cols=84 lines=30"); //col = 가로, lines = 세로
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 헨들가져오기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false 또는 0 : 숨기기
	ConsoleCursor.dwSize = 1; //커서 사이즈 (1 ~ 100)
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
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

//커서 위치 이동함수
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);//콘솔 핸들가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int menu_cursor() {
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
				gotoxy(x - 2, y -= 2); //두 칸 위로 이동
				printf(">"); //다시 그리기
			}
			break;
		}

		case DOWN: { //키 값이 DOWN인경우
			if (y < 23) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, y += 2); //두 칸 아래로 이동
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
