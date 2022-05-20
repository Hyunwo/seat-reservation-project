#define _CRT_SECURE_NO_WARNINGS
#include "func.h"
int v;
int b;
struct MyInfo person[MAX];

void Print_UI(int x[10][6]) {
    int i, j, k = 1; //i는 행, j는 열, k는 열 번호
    char c; //c는 문답을 위한 변수



    while (1) {
        printf("좌석번호를 행, 열 순서로 입력해주세요!\n");
        printf("   선택가능 : □   선택불가능 : ■\n");
        printf("\t1 2 3      4 5 6\n");

        for (i = 0; i < 10; i++) {
            printf("\t");
            for (j = 0; j < 6; j++) {
                if (x[i][j] == 1) {     //예약된 좌석이면 '■', 열번호가 10이면 다시 1로 초기화
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

                else {     //빈 좌석이면 '□', 열번호가 10이면 다시 1로 초기화
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
        scanf("%d", &i);

        if (i < 1 || i > 10) {
            printf("※행은 1 ~ 10까지 입니다. 다시 입력해주세요.\n");
            goto ROW;   //1~10범위를 벗어나면 ROW로 돌아가 다시 입력
        }
    COLUMN://열(세로)
        printf("열(세로)를 입력해주세요 : ");
        scanf("%d", &j);

        if (j < 1 || j > 6) {
            printf("※열은 1~6까지 입니다. 다시 입력해주세요.\n");
            goto COLUMN;    //1~6범위를 벗어나면 COLUMN으로 돌아가 다시 입력
        }

        else if (x[i - 1][j - 1] == 1) {    //좌석이 예매된 곳은 1이므로 ROW로 돌아가 다시 입력
            printf("예약이 완료된 좌석입니다. 다시 입력해주세요.\n");
            printf("------------------------------------------------------------------------------------\n");
            goto ROW;
        }

        else x[i - 1][j - 1] = 1;   //좌석을 선택했기 때문에 선택한 행과 열의 인덱스에 1대입
        printf("선택한 좌석은 %d행 %d열입니다.\n", i, j);
    GO:
        printf("------------------------------------------------------------------------------------\n");
        printf("좌석 선택을 계속하시겠습니까? (추가 좌석 선택은'y', 다음페이지는 'n'을 입력해주세요)\n");
        scanf(" %c", &c);//입력버퍼?떄문에 오류현상이 일어남ㅜ 스페이스바...

        if (c == 'y') {
            system("cls");//Clean Screen
        }
        else if (c == 'n') {
            system("cls");
            v = i;//행 값을 v에 저장, v는 extern 으로 selectNum1.c에서 선언해 주었기때문에 v값을 공유한다.
            b = j;//행 값을 b에 저장, b는 extern 으로 selectNum1.c에서 선언해 주었기때문에 b값을 공유한다.

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
    scanf("%s", &person[0].name/*, sizeof(person[0].name) / sizeof(char)*/);


    printf("성별 : ");
    scanf("%s", &person[0].gender);


    printf("생년월일(6자리) : ");
    scanf("%s", &person[0].birth);


    printf("국적 : ");
    scanf("%s", &person[0].nationality);


    printf("이메일 : ");
    scanf("%s", &person[0].email);



    printf("------------------------------------------------------------------------------------\n");
    printf("입력 된 정보를 확인해주세요\n");
    printf("이름 : %s\n", person[0].name);
    printf("성별 : %s\n", person[0].gender);
    printf("생년월일 : %s\n", person[0].birth);
    printf("국적 : %s\n", person[0].nationality);
    printf("이메일 : %s\n", person[0].email);
    printf("------------------------------------------------------------------------------------\n");

    //왜 2번이나 입력을 받냐???
Back2:
    printf("저장하시겠습니까? (저장 : y / 수정 : n)\t");
    scanf(" %c", &save);

    if (save == 'y') {
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
    MainView();

}
