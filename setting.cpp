
#include "connect.h"
 
void setting::Cursor() //cursor setting
{   
	HANDLE hConsole;   
	CONSOLE_CURSOR_INFO ConsoleCursor;   
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
	ConsoleCursor.bVisible =0 ;   //cursor visability
	ConsoleCursor.dwSize = 1;   // cursor size
	SetConsoleCursorInfo(hConsole , &ConsoleCursor);   

}

//move cursor to xy
void setting::gotoxy(int x, int y)
{     
	COORD XY = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}