#include "connect.h"

//이동하기
void move::go(int *y, int *x) // 함수내에서 값 수정 (포인터)   
{   
	int oy=*y, ox=*x;   // ox, oy는 이전 좌표 
	char input;    // 키보드로 받는 input

	while((input=_getch()) != ENTER)   // Enter 치기 전까지 입력에 맞게 위치 이동
	{   
		if(input == UP)   
		{   
			ox=*x;   
			oy=(*y)--;   
		}   
		else if(input == DOWN)   
		{   
			ox=*x;   
			oy=(*y)++;   
		}   
		else if(input == LEFT)   
		{   
			ox=(*x)--;   
			oy=*y;   
		}   
		else if(input == RIGHT)   
		{   
			ox=(*x)++;   
			oy=*y;   
		}

		(*x)=((*x) + 17) % 17;   // 바둑판의 끝에서 움직이면 반대편 끝으로 감
		(*y)=((*y) + 17) % 17;   
		gotoxy(ox*2, oy);   //커서가 이동되고 원래 있던 부분에는다시 바둑판 모양을 채움
		cout<<pan[oy][ox];  // 화살표로 이동하는 위치 
		gotoxy((*x)*2, *y);  
		cout<<"⊙";   //현재 위치하고 있는 좌표상에 ⊙ 출력
	}

}
