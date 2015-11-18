
#include "connect.h"

//커서 숨기기  
void setting::Cursor() //커서의 출력 여부를 결정하는 함수
{   
	HANDLE hConsole;   
	CONSOLE_CURSOR_INFO ConsoleCursor;   
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
	ConsoleCursor.bVisible =0 ;   //커서가 보이는가 안보이는가
	ConsoleCursor.dwSize = 1;   // 커서의 크기
	SetConsoleCursorInfo(hConsole , &ConsoleCursor);   

}

//원하는 좌표로 커서 이동
void setting::gotoxy(int x, int y)
{     
	COORD XY = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}