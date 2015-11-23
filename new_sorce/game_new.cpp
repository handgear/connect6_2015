#include "connect_new.h"

void game::initialize_map() 
{  
	char stone[3][3]={"","●","○"}; // initialize stone
	
	print_board(); 
	//turn==1: white, turn==2: black
	int totalturn = 0, turn2 = 0; //turn2: flag for two turn
	turn = 2;  //first turn is black
	Cursor(); 
	first_move(&y, &x); //first random move
	
	

}
void game::print_board()   
{
	//
	//corner
	strcpy(pan[0][0], "┌");
	strcpy(pan[0][16] ,"┐");   
	strcpy(pan[16][0],"└");
	strcpy(pan[16][16],"┘");   
	//side
	for(y=1; y<16; y++)   
	{   
		strcpy(pan[y][0], "├");
		strcpy(pan[y][16],"┤");
	}   
	//bottom and top
	for(x=1; x<16; x++)   
	{   
		strcpy(pan[0][x], "┬");   
		strcpy(pan[16][x],"┴");   
	} 
	//else
	for(y=1; y<16; y++)     
		for(x=1; x<16; x++)         
			strcpy(pan[y][x],"┼");   
	
	system("CLS"); //
	for(y=0; y<17; y++,cout<<endl)
		for(x=0; x<17; x++)   
			cout<<pan[y][x][0];

	//position number
	gotoxy(0, 17);//bottom board number(1st liine)
	cout << " ";
	for(int i=1;i<18;i++)
	{
		gotoxy(i*2-1, 17);
		
		if (i<10)
			cout<< i; 
		else
			cout << '1';
		
	}
	gotoxy(0, 18);//bottom board number(2nd liine)
	cout << " ";
	for (int i = 1; i<18; i++)
	{
		gotoxy(i * 2 - 1, 18);

		if (i>9)
			cout << i-10;
		
	}
	for (int i = 1; i<18; i++)//right borad number
	{
		gotoxy(34, i-1);
		cout << i;
		
	}
	
}
int game::put(int y, int x, int turn)   
{
	char stone[3][3]={"","●","○"};   
	if(board[y][x] == 0)   //
	{   

		board[y][x]=turn;   //
		strcpy(pan[y][x], stone[turn]);   //
		gotoxy(x*2, y); 
		cout<<stone[turn];   
		//
		return 1;   
	}   
	return 0;   
}



void game::pause() 
{
	_getch();  // 
	puts(""); //
}
void game::Cursor() //cursor setting
{   
	HANDLE hConsole;   
	CONSOLE_CURSOR_INFO ConsoleCursor;   
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);   
	ConsoleCursor.bVisible =0 ;   //cursor visability
	ConsoleCursor.dwSize = 1;   // cursor size
	SetConsoleCursorInfo(hConsole , &ConsoleCursor);   

}

//move cursor to xy
void game::gotoxy(int x, int y)
{     
	COORD XY = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), XY);
}