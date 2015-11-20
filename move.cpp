#include "connect.h"

//?Ìµ¿ÇÏ±â
void move::go(int *y, int *x) // ÇÔ¼ö³»¿¡¼­ °ª ¼öÁ¤ (Æ÷?ÎÅÍ)   
{   
	int oy=*y, ox=*x;   // ox, oy´Â ?Ì?ü ÁÂÇ¥ 
	char input;    // Å°º¸µå·Î ¹Þ´Â input

	while((input=_getch()) != ENTER)   // Enter Ä¡±â ?ü±îÁö ?Ô·Â¿¡ ¸Â°Ô ?§Ä¡ ?Ìµ¿
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

		(*x)=((*x) + 17) % 17;   // ¹ÙµÏÆÇ?Ç ³¡¿¡¼­ ¿òÁ÷?Ì¸é ¹Ý´ëÆí ³¡?¸·Î °¨
		(*y)=((*y) + 17) % 17;   
		gotoxy(ox*2, oy);   //Ä¿¼­°¡ ?Ìµ¿µÇ°í ¿ø·¡ ?Ö´ø ºÎºÐ¿¡´Â´Ù½Ã ¹ÙµÏÆÇ ¸ð¾ç?» Ã¤¿ò
		cout<<pan[oy][ox];  // È­»ìÇ¥·Î ?Ìµ¿ÇÏ´Â ?§Ä¡ 
		gotoxy((*x)*2, *y);  
		cout<<"¢Á";   //Çö?ç ?§Ä¡ÇÏ°í ?Ö´Â ÁÂÇ¥»ó¿¡ ¢Á Ãâ·Â
	}

}
void move::first_move(int *y, int *x)
{
	srand(time(NULL));
	*x=rand()%7+5;//5~11
	*y=rand()%7+5;//5~11
}
void move::input(int *y, int *x, int turn)
{
	int x_in, y_in;
	char player[3][3] = { "", "��", "��" };
	while(1)
	{
		setting::gotoxy(0, 22);
		cout<<"input"<< player[turn]<<"'s next position"<<endl;
		cout<<"<x y> : ";
		cin>>x_in>>y_in;
		//check varified num
		if(x_in>0 && x_in<18 && y_in>0 && y_in<18)
		{
			*x=x_in-1; *y=y_in-1;
			setting::gotoxy(0, 23);
			cout<<"                 ";
			setting::gotoxy(0, 24);
			cout<<"                            ";
			break;
		}
		else
		{
			setting::gotoxy(0, 24);
			cout<<"please input valied position";
			setting::gotoxy(0, 23);
			cout<<"                 ";
		}
	}
}