#include "connect_new.h"
 
void user::input(int *y, int *x, int turn)
{
	int x_in, y_in;
	char player[3][3] = { "", "●", "○" };
	while(1)
	{
		game::gotoxy(0, 22);
		cout<<"input"<< player[turn]<<"'s next position"<<endl;
		cout<<"<x y> : ";
		cin>>x_in>>y_in;
		//check varified num
		if(x_in>0 && x_in<18 && y_in>0 && y_in<18)
		{
			*x=x_in-1; *y=y_in-1;
			game::gotoxy(0, 23);
			cout<<"                 ";
			game::gotoxy(0, 24);
			cout<<"                            ";
			break;
		}
		else
		{
			game::gotoxy(0, 24);
			cout<<"please input valied position";
			game::gotoxy(0, 23);
			cout<<"                 ";
		}
	}
}
void user::first_move(int *y, int *x)
{
	srand(time(NULL));
	*x=rand()%7+5;//5~11
	*y=rand()%7+5;//5~11
}
void user::go(int *y, int *x)
{   
	int oy=*y, ox=*x;  
	char input;   

	while((input=_getch()) != ENTER)  
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

		(*x)=((*x) + 17) % 17;  
		(*y)=((*y) + 17) % 17;   
		game::gotoxy(ox*2, oy);   //
		cout<<game::pan[oy][ox];  // 
		game::gotoxy((*x)*2, *y);  
		cout<<"◎";   //
	}

}