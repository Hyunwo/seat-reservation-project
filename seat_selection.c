#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

//char LJW();      //함수원형
int main()
{
    int x[10][6]; //예약좌석을 표시하기 위한 2차원 배열
    int i, j, k=1; //i는 행, j는 열, k는 열 번호
    char c; //c는 문답을 위한 변수

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            x[10][6] = rand() % 2;
        }
    }

    while (1) {
        printf("    좌석번호를 행, 열 순서로 입력해주세요\n");
        printf("      선택가능 : □    선택불가능 : ■\n");
        printf("1 2 3      4 5 6\n");

        //좌석 지정 화면 만들기
        for (i = 0; i < 10; i++){
            for (j = 0; j < 6; j++) {
                printf("□");
                if (j == 2) {
                    if (k == 10) {          //□열 맞추기 위해
                        printf("  %d ", k);
                    }
                    else
                        printf("  %d  ", k);
                    k += 1;

                    if (k == 11) {          //다시 질문을 물어볼때 k값 초기화

                        k = 1;
                    }
                }
            }
            printf("\n");
        }
    //goto문 사용을 위한 레이블
    ROW:
        printf("행(가로)을 입력해주세요 : ");
        scanf("%d", &i);

        if (i < 1 || i > 10) {
            printf("※행은 1 ~ 10까지 입니다. 다시 입력해주세요.\n");
            goto ROW;
        }
    COLUMN:
        printf("열(세로)를 입력해주세요 : ");
        scanf("%d", &j);

        if (j < 1 || j > 6) {
            printf("※열은 1~6까지 입니다. 다시 입력해주세요.\n");
            goto COLUMN;
        }

        //if(x[][])
        
        printf("선택한 좌석은 %d행 %d열입니다.\n", i, j);
    GO:
        printf("-------------------------------------------------------------------------------------\n");
        printf("좌석 선택을 계속하시겠습니까? (추가 좌석 선택은'y', 다음페이지는 'n'을 입력해주세요)\n");
        scanf(" %c", &c);//입력버퍼?떄문에 오류현상이 일어남ㅜ 스페이스바...

        if (c == 'y') {
            system("cls");//Clean Screen
        }
        else if (c == 'n') {
            system("cls");//다음 페이지로 넘길 것
        }
        else {
            printf("※'y'와 'n'중에서 입력해주세요.\n");
            goto GO;
        }

        //printf("예약을 할 수 없습니다.");
    }
    
    /*int y[5][5];    //예약좌석을 표시하기 위한 2차원 배열
    int i, j, add = 0;   //i는 줄, j는 칸, add는 빈자리수 계산
    char c;      //c는 y와n 변수
    srand(time(NULL));   //난수함수의 무작위성 확대

    for (i = 0; i < 5; i++)   //무작위로 입력
    {
        for (j = 0; j < 5; j++)  //무작위로 입력
        {
            y[i][j] = rand() % 2; //난수입력
        }
    }
    while (1)     //무한반복
    {
        printf("예약 프로그램 : 총 30 석\n\n");
        printf("　 1 2 3 4 5\n"); //칸번호
        for (i = 0; i < 5; i++)   //줄 만들기
        {
            printf(" %d", i + 1);  //줄번호
            for (j = 0; j < 5; j++)  //칸 만들기
            {
                if (y[i][j] == 1)
                    printf("■"); //예약된 좌석 표시
                else
                {
                    printf("□"); //예약 가능한 좌석 표시
                    add++;   //빈 자리 계산
                }
            }
            printf("\n");   //줄바꿈
        }
        printf("빈자리 수 : %d\n\n", add); //빈 자리수 표시
        add = 0;        //add변수 초기화
    ONE:
        printf("줄을 선택하시오 : ");
        scanf_s("%d", &i);     //줄 번호 입력
        if (i <= 0)       //0 이하인 수를 입력할때
            return 0;      //프로그램 종료
        if (i > 5)       //5보다 큰수를 입력할때
        {
            printf("*주의! 5줄이 넘는 경우는 없습니다. 다시 입력하세요.\n\n");
            goto ONE;      //ONE으로 돌아간다.
        }
    TWO:
        printf("칸을 선택하시오 : ");
        scanf_s("%d", &j);     //칸 번호 입력
        if (j <= 0)       //0 이하인 수를 입력할때
            return 0;      //프로그램 종료
        if (j > 5)       //5보다 큰수를 입력할때
        {
            printf("*주의! 5칸이 넘는 경우는 없습니다. 다시 입력하세요.\n\n");
            goto TWO;      //TWO으로 돌아간다.
        }
        if (y[i - 1][j - 1] == 1)     //예약된 자리가 있을 경우
        {
            printf("이미 예약된 자리입니다. 다른 자리를 선택하시오\n");
            goto ONE;      //ONE으로 돌아간다.
        }
        else
        {
            y[i - 1][j - 1] = 1;    //예약한다.
            printf("%d줄 %d칸 예약이 완료되었습니다.\n\n", i, j);
        }
    THREE:
        printf("계속 하시려면 'y', 끝내시려면 'n'를 누르시오.\n");
        LJW();        //함수호출
        c = LJW();       //함수값을 c에다 입력
        if (c == 121)       //y를 입력했을 경우
            system("cls");     //화면 지우기
        else if (c == 110)      //n을 입력했을 경우
            return 0;      //프로그램 종료
        else
        {
            printf("\n'y'또는'n'을 입력하세요\n\n");
            goto THREE;
        }
    }*/
}

/*char LJW()    //함수 정의
{
    char a;    //a값(실행 여부)를 입력 받음
    scanf_s("%c", &a); //값을 입력
    return a;   //a값을 반환
}*/