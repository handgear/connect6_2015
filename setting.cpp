
#include "connect.h"

//Ŀ�� �����  
void setting::Cursor() //Ŀ���� ��� ���θ� �����ϴ� �Լ�
{   
	HANDLE hConsole;   
	CONSOLE_CURSOR_INFO ConsoleCursor;   
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
	ConsoleCursor.bVisible =0 ;   //Ŀ���� ���̴°� �Ⱥ��̴°�
	ConsoleCursor.dwSize = 1;   // Ŀ���� ũ��
	SetConsoleCursorInfo(hConsole , &ConsoleCursor);   

}

//���ϴ� ��ǥ�� Ŀ�� �̵�
void setting::gotoxy(int x, int y)
{     
	COORD XY = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}