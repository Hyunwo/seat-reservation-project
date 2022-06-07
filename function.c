#include"main.h"
#include"util.h"
#include"function.h"

int OptionUiNum1() {
	system("cls");
	int selectNum = 0;

	printf("\n\n\t\t\t옵션을 선택해 주세요\n\n\n");
	printf("         목적지                    출발 날짜           항공사\n\n");
	printf("1.미국 - 로스엔젤레스(LAX)       2022/07/02/11:05      대한한공\n\n");
	printf("2.미국 - 로스엔젤레스(LAX)       2022/07/10/17:35      대한한공\n\n");
	printf("3.미국 - 로스엔젤레스(LAX)       2022/07/22/06:30      진에어\n\n");
	printf("4.미국 - 로스엔젤레스(LAX)       2022/07/28/18:15      진에어\n\n");
	printf("5.일본 - 도쿄(NRT)               2022/07/03/13:10      대한한공\n\n");
	printf("6.일본 - 도쿄(NRT)               2022/07/08/15:35      대한항공\n\n");
	printf("7.일본 - 도쿄(NRT)               2022/07/17/20:40      진에어\n\n");
	printf("8.일본 - 도쿄(NRT)               2022/07/30/07:50      진에어\n\n");
Back:
	printf("입력 : ");
	if (scanf("%d", &selectNum) == 0) {
		printf("숫자를 입력해주세요.\n");
		while (getchar() != '\n') {}
		goto Back;
	}

	printf("------------------------------------------------------------------------------------\n");

	if (selectNum > 0 && selectNum < 9) {
		option2 = selectNum;

		FILE* fp = fopen("test.txt", "w+");
		fprintf(fp, "%d\n", option2);
		fclose(fp);
		view(option2);
		seat_selection();
	}
	else {
		printf("1번 부터 8번까지 옵션중 하나를 골라 숫자를 입력해주세요.\n");
		goto Back;
	}

}

void seat_selection()//main -> void seat_selection으로 변경
{
	system("cls");
	int x[10][6]; //예약좌석을 표시하기 위한 2차원 배열
	int i, j; //i는 행, j는 열

	srand(time(NULL)); //rand()함수를 사용하기 전 초기화

	for (i = 0; i < 10; i++) {  //행이 10칸
		for (j = 0; j < 6; j++) {   //열이 6칸
			x[i][j] = rand() % 2;   //랜덤으로 지정된 좌석은 1, 빈 좌석은 0
		}
	}
	Print_UI(x);//좌석 선택 화면
	Input_information();//사용자 정보 입력
}

void Print_UI(int x[10][6]) {
	int i, j, k = 1; //i는 행, j는 열, k는 행 번호
	char c; //c는 문답을 위한 변수



	while (1) {
		printf("좌석번호를 행, 열 순서로 입력해주세요!\n");
		printf("   선택가능 : □   선택불가능 : ■\n");
		printf("\t1 2 3      4 5 6\n");

		for (i = 0; i < 10; i++) {
			printf("\t");
			for (j = 0; j < 6; j++) {
				if (x[i][j] == 1) {     //예약된 좌석이면 '■', 행번호가 10이면 다시 1로 초기화
					printf("■");
					if (j == 2 && k != 10) {
						printf("  %d  ", k);
						k++;
					}
					else if (j == 2 && k == 10) {   //열을 맞추기 위해 사용
						printf("  %d ", k);
						k = 1;
					}
				}

				else {     //빈 좌석이면 '□', 행번호가 10이면 다시 1로 초기화
					printf("□");
					if (j == 2 && k != 10) {
						printf("  %d  ", k);
						k++;
					}
					else if (j == 2 && k == 10) {   //열을 맞추기 위해 사용
						printf("  %d ", k);
						k = 1;
					}
				}
			}
			printf("\n");
		}

		//goto문 사용을 위한 레이블
	ROW://행(가로)
		printf("행(가로)을 입력해주세요 : ");
		if (scanf("%d", &i) == 0) {
			printf("숫자를 입력해주세요.\n");
			while (getchar() != '\n') {}
			goto ROW;
		}

		if (i < 1 || i > 10) {
			printf("※행은 1 ~ 10까지 입니다. 다시 입력해주세요.\n");
			while (getchar() != '\n') {}
			goto ROW;   //1~10범위를 벗어나면 ROW로 돌아가 다시 입력
		}
	COLUMN://열(세로)
		printf("열(세로)를 입력해주세요 : ");
		if (scanf("%d", &j) == 0) {
			printf("숫자를 입력해주세요.\n");
			while (getchar() != '\n') {}
			goto COLUMN;
		}

		if (j < 1 || j > 6) {
			printf("※열은 1~6까지 입니다. 다시 입력해주세요.\n");
			while (getchar() != '\n') {}
			goto COLUMN;    //1~6범위를 벗어나면 COLUMN으로 돌아가 다시 입력
		}

		else if (x[i - 1][j - 1] == 1) {    //좌석이 예매된 곳은 1이므로 ROW로 돌아가 다시 입력
			printf("예약이 완료된 좌석입니다. 다시 입력해주세요.\n");
			printf("------------------------------------------------------------------------------------\n");
			while (getchar() != '\n') {}
			goto ROW;
		}

		else x[i - 1][j - 1] = 1;   //좌석을 선택했기 때문에 선택한 행과 열의 인덱스에 1대입
		printf("선택한 좌석은 %d행 %d열입니다.\n", i, j);

		FILE* fp1 = fopen("test2.txt", "a+");
		fprintf(fp1, "%d", i);
		fputs("행", fp1);
		fprintf(fp1, "%d", j);
		fputs("열\n", fp1);

		fclose(fp1);
	GO:
		printf("------------------------------------------------------------------------------------\n");
		printf("좌석 선택을 계속하시겠습니까? (추가 좌석 선택은'y', 다음페이지는 'n'을 입력해주세요)\n");
		scanf(" %c", &c);//입력버퍼?문에 오류현상이 일어남ㅜ 스페이스바...

		if (c == 'y') {
			system("cls");//Clean Screen
		}
		else if (c == 'n') {
			system("cls");
			Input_information();//다음 페이지로 이동
			break;//while문 종료
		}
		else {
			printf("※'y'와 'n'중에서 입력해주세요.\n");
			goto GO;    //'y'와'n'이외의 입력은 GO로 돌아가 다시 입력
		}
	}
}

void Input_information() {
	char save;
Back1:
	printf("예매자 정보를 입력해주세요\n");

	printf("이름 : ");
	scanf("%s", &person[1].name/*, sizeof(person[0].name) / sizeof(char)*/);

	printf("성별 : ");
	scanf("%s", &person[1].gender);

	printf("생년월일(6자리) : ");
	scanf("%s", &person[1].birth);

	printf("국적 : ");
	scanf("%s", &person[1].nationality);

	printf("이메일 : ");
	scanf("%s", &person[1].email);


	printf("------------------------------------------------------------------------------------\n");
	printf("입력 된 정보를 확인해주세요\n");
	printf("이름 : %s\n", person[1].name);
	printf("성별 : %s\n", person[1].gender);
	printf("생년월일 : %s\n", person[1].birth);
	printf("국적 : %s\n", person[1].nationality);
	printf("이메일 : %s\n", person[1].email);
	printf("------------------------------------------------------------------------------------\n");

	//왜 2번이나 입력을 받냐???
Back2:
	printf("저장하시겠습니까? (저장 : y / 수정 : n)\t");
	scanf(" %c", &save);

	if (save == 'y') {
		FILE* fp = fopen("test.txt", "a+");
		fprintf(fp, "%s\n", person[1].name);
		fprintf(fp, "%s\n", person[1].gender);
		fprintf(fp, "%s\n", person[1].birth);
		fprintf(fp, "%s\n", person[1].nationality);
		fprintf(fp, "%s\n", person[1].email);
		fclose(fp);
		printf("저장되었습니다.\n");
	}
	else if (save == 'n') {
		system("cls");
		goto Back1;//정보 다시 입력
	}
	else {
		printf("※'y'와 'n'중에서 입력해주세요.\n");
		goto Back2;
	}
	system("cls");//Clean Screen, 메인화면으로
	main();
}

void selectMenu() {
	while (1) {
		int menuCode = menu_cursor();
		if (menuCode == 0) { //항공권 예매
			FILE* fp;
			if (fp = fopen("test.txt", "r")) {

			Return0:
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                 이미 예약한 좌석이 있습니다. 좌석 삭제후 선택해주세요.\n\n\n\n");
				printf("                      스페이스바를 입력하면 메뉴로 돌아갑니다.\n");
				int key = getch();
				if (key == 32) {
					fclose(fp);
					system("cls");
					main();
				}
				else {
					system("cls");
					goto Return0;
				}
			}
			else {
				OptionUiNum1();
			}
		}
		else if (menuCode == 2) {
			FILE* fp;

			if (fp = fopen("test.txt", "r"))
			{
				fclose(fp);
				char save;
				FILE* fp = fopen("test.txt", "r");
				a = fscanf(fp, "%d", &option2);

				fscanf(fp, "%s", person[1].name);
				fscanf(fp, "%s", person[1].gender);
				fscanf(fp, "%s", person[1].birth);
				fscanf(fp, "%s", person[1].nationality);
				fscanf(fp, "%s", person[1].email);


			Return1:
				system("cls");
				printf("이름 : %-34s", &person[1].name);
				view(0);//view(선택한 도착지 시간 메뉴 값): 선택한 옵션의 숫자를 넣으면 그 값에 맞추어 정보 표시.
				printf("\n");
				printf("성별 : %-35s", &person[1].gender);//입력했던 성별 표시
				view(1);
				printf("\n");
				printf("생년월일 : %-31s", &person[1].birth);//입력했던 생년월일 표시
				view(2);
				printf("\n");
				printf("국적 : %-35s\n", &person[1].nationality);
				printf("\n");
				printf("이메일 : %s\n", &person[1].email);// 입력했던 이메일 표시
				printf("\n");
				printf("좌석 :\n");// 입력했던 출신국가 표시

				FILE* fp1 = fopen("test2.txt", "a+");
				int c;
				while ((c = fgetc(fp1)) != EOF) {
					putchar(c);
				}

				fclose(fp1);
				printf("\n");
				printf("\n");
				printf("정말 삭제 하시겠습니까? y 입력시 삭제, 그외 입력시 메인메뉴로 이동\n");
				printf("입력: ");
				scanf("%s", &save);

				if (save == 'y') { //항공권 취소
					system("cls");
					fclose(fp);
					remove("test.txt");
					remove("test2.txt");
					main();
				}
				else {
					system("cls");
					fclose(fp);
					main();
				}
			}
			else
			{
				char save2;
			Return2:
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                             예약된 정보가 없습니다.\n\n\n\n");
				printf("                      스페이스바를 입력하면 메뉴로 돌아갑니다.\n");

				int key = getch();
				if (key == 32) {

					system("cls");
					main();
				}
				else {
					system("cls");
					goto Return2;
				}
			}
			main();
		}
		else if (menuCode == 4) {
			//좌석 확인
			doubleCheck();
		}
		else if (menuCode == 6) {
			//종료
			exit(0);
		}
		system("cls");
	}
}

int view(int h) {//선택한 옵션의 숫자를 넣으면 그에 맞춰 선택한 옵션의 정보를 출력하는 함수

	if (option2 == 1) {

		if (h == 0) {
			printf("목적지: 미국 - 로스엔젤레스(LAX)\n");
		}
		else if (h == 1) {
			printf("날짜: 2022/06/02/11:05\n");
		}
		else if (h == 2) {
			printf("항공사: 대한한공\n");
		}


	}
	else if (option2 == 2) {
		if (h == 0) {
			printf("목적지: 미국 - 로스엔젤레스(LAX)\n");
		}
		else if (h == 1) {
			printf("날짜: 2022/07/10/17:35\n");
		}
		else if (h == 2) {
			printf("항공사: 대한한공\n");
		}

	}
	else if (option2 == 3) {

		if (h == 0) {
			printf(" 목적지: 미국 - 로스엔젤레스(LAX)\n");
		}
		else if (h == 1) {
			printf("날짜:  2022/07/22/06:30\n");
		}
		else if (h == 2) {
			printf("항공사:  진에어\n");
		}
	}
	else if (option2 == 4) {

		if (h == 0) {
			printf("목적지: 미국 - 로스엔젤레스(LAX)\n");
		}
		else if (h == 1) {
			printf("날짜:   2022/07/28/18:15\n");
		}
		else if (h == 2) {
			printf("항공사:  진에어\n");
		}
	}
	else if (option2 == 5) {

		if (h == 0) {
			printf(" 목적지: 일본 - 도쿄(NRT)\n");
		}
		else if (h == 1) {
			printf("날짜:   2022/07/03/13:10 \n");
		}
		else if (h == 2) {
			printf("항공사: 대한한공\n");
		}

	}
	else if (option2 == 6) {

		if (h == 0) {
			printf("목적지: 일본 - 도쿄(NRT)\n");
		}
		else if (h == 1) {
			printf("날짜:  2022/07/08/15:35 \n");
		}
		else if (h == 2) {
			printf("항공사: 대한항공\n");
		}
	}
	else if (option2 == 7) {

		if (h == 0) {
			printf("목적지: 일본 - 도쿄(NRT)\n");
		}
		else if (h == 1) {
			printf("날짜:  2022/07/17/20:40 \n");
		}
		else if (h == 2) {
			printf(" 항공사: 진에어\n");
		}
	}
	else if (option2 == 8) {

		if (h == 0) {
			printf("목적지: 일본 - 도쿄(NRT)\n");
		}
		else if (h == 1) {
			printf("날짜:   2022/07/30/07:50 \n");
		}
		else if (h == 2) {
			printf("항공사: 진에어\n");
		}
	}
	return option2;
}

void doubleCheck() {
	char save;
	FILE* fp;
	if (fp = fopen("test.txt", "r")) {
		a = fscanf(fp, "%d", &option2);

		fscanf(fp, "%s", person[1].name);
		fscanf(fp, "%s", person[1].gender);
		fscanf(fp, "%s", person[1].birth);
		fscanf(fp, "%s", person[1].nationality);
		fscanf(fp, "%s", person[1].email);


	Return1:
		system("cls");
		printf("이름 : %-34s", &person[1].name);
		view(0);//view(선택한 도착지 시간 메뉴 값): 선택한 옵션의 숫자를 넣으면 그 값에 맞추어 정보 표시.
		printf("\n");
		printf("성별 : %-35s", &person[1].gender);//입력했던 성별 표시
		view(1);
		printf("\n");
		printf("생년월일 : %-31s", &person[1].birth);//입력했던 생년월일 표시
		view(2);
		printf("\n");
		printf("국적 : %-35s\n", &person[1].nationality);
		printf("\n");
		printf("이메일 : %s\n", &person[1].email);// 입력했던 이메일 표시
		printf("\n");
		printf("좌석 :\n");// 입력했던 출신국가 표시
		FILE* fp1 = fopen("test2.txt", "a+");
		int c;
		while ((c = fgetc(fp1)) != EOF) {

			putchar(c);

		}
		fclose(fp1);
		printf("\n");
		printf("\n");
		printf("스페이스바를 입력하면 메뉴로 돌아갑니다. ");

		int key = getch();
		if (key == 32) {

			system("cls");
			main();
		}
		else {
			system("cls");
			goto Return1;
		}
	}
	else {
		char save2;
	Return2:
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n                             예약된 정보가 없습니다.\n\n\n\n");
		printf("                      스페이스바를 입력하면 메뉴로 돌아갑니다.\n");

		int key = getch();
		if (key == 32) {

			system("cls");
			main();
		}
		else {
			system("cls");
			goto Return2;
		}
	}
}