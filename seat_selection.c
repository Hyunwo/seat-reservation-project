#include "func.h"

int main()
{
    int x[10][6]; //예약좌석을 표시하기 위한 2차원 배열
    int i, j; //i는 행, j는 열

    //srand(time(NULL)); //rand()함수를 사용하기 전 초기화

    for (i = 0; i < 10; i++) {  //행이 10칸
        for (j = 0; j < 6; j++) {   //열이 6칸
            x[i][j] = rand() % 2;   //랜덤으로 지정된 좌석은 1, 빈 좌석은 0
        }
    }
    Print_UI(x);//좌석 선택 화면
    Input_information();//사용자 정보 입력
    return 0;
}