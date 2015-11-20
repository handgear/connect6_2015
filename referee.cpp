#include "connect.h"

//
int referee::countSeries(int x, int y, int ax, int ay) //
{
	int sx=x, sy=y;  // 
	int total=0; //
	for(int i=0; i<6; i++){ // 
		if((board[sy][sx] == board[y][x]) && (board[sy][sx] != 0)){
			total++; // 
			x += ax; // 
			y += ay; // 
		} else
			return total; //
	}
	return total;
}

int referee::decideWinner() //
{
	int temp=0;

	for(int y=0; y<17; y++){
		for(int x=0; x<17; x++){

			temp = countSeries(x, y, 1, 0); //
			if(temp == 6 && ((board[y][x-1] != board[y][x]) || x == 0) ) //
				return 1;
			else if(temp == 5 && ((board[y][x-1] != board[y][x]) || x == 0) && board[y][x]==2) 
				five++;
			else if(temp == 4 && ((board[y][x-1] != board[y][x]) || x == 0) && board[y][x]==2)
				four++;
			else if(temp == 3 && ((board[y][x-1] != board[y][x]) || x == 0) && board[y][x]==2)
				three++;
			else if(temp == 2 && ((board[y][x-1] != board[y][x]) || x == 0) && board[y][x]==2)
				two++;
			else if(temp == 5 && ((board[y][x-1] != board[y][x]) || x == 0) && board[y][x]==1)
				five1++;
			else if(temp == 4 && ((board[y][x-1] != board[y][x]) || x == 0) && board[y][x]==1)
				four1++;
			else if(temp == 3 && ((board[y][x-1] != board[y][x]) || x == 0) && board[y][x]==1)
				three1++;
			else if(temp == 2 && ((board[y][x-1] != board[y][x]) || x == 0) && board[y][x]==1)
				two1++;
			// 
			//
			temp = countSeries(x, y, 0, 1);
			if(temp == 6 && ((board[y-1][x] != board[y][x]) || y == 0) ) //
				return 1;
			else if(temp == 5 && ((board[y-1][x] != board[y][x]) || y == 0) && board[y][x]==2)
				five++;
			else if(temp == 4 && ((board[y-1][x] != board[y][x]) || y == 0) && board[y][x]==2)
				four++;
			else if(temp == 3 && ((board[y-1][x] != board[y][x]) || y == 0) && board[y][x]==2)
				three++;
			else if(temp == 2 && ((board[y-1][x] != board[y][x]) || y == 0) && board[y][x]==2)
				two++;
			else if(temp == 5 && ((board[y-1][x] != board[y][x]) || y == 0) && board[y][x]==1)
				five1++;
			else if(temp == 4 && ((board[y-1][x] != board[y][x]) || y == 0) && board[y][x]==1)
				four1++;
			else if(temp == 3 && ((board[y-1][x] != board[y][x]) || y == 0) && board[y][x]==1)
				three1++;
			else if(temp == 2 && ((board[y-1][x] != board[y][x]) || y == 0) && board[y][x]==1)
				two1++;
			// 
			//
			temp = countSeries(x, y, 1, 1);
			if(temp == 6 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0))) //
				return 1;
			else if(temp == 5 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0)) && board[y][x]==2)
				five++;
			else if(temp == 4 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0)) && board[y][x]==2)
				four++;
			else if(temp == 3 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0)) && board[y][x]==2)
				three++;
			else if(temp == 2 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0)) && board[y][x]==2)
				two++;
			else if(temp == 5 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0)) && board[y][x]==1)
				five1++;
			else if(temp == 4 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0)) && board[y][x]==1)
				four1++;
			else if(temp == 3 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0)) && board[y][x]==1)
				three1++;
			else if(temp == 2 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0)) && board[y][x]==1)
				two1++;
			// 
			//
			temp = countSeries(x, y, -1, 1);
			if(temp == 6 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)))  //
				return 1;
			else if(temp == 5 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==2)
				five++;
			else if(temp == 4 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==2)
				four++;
			else if(temp == 3 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==2)
				three++;
			else if(temp == 2 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==2)
				two++;
			else if(temp == 5 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==1)
				five1++;
			else if(temp == 4 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==1)
				four1++;
			else if(temp == 3 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==1)
				three1++;
			else if(temp == 2 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==1)
				two1++;
			//
			//
		}
	}
	gotoxy(42, 3);
	cout <<"connect2 : black - "<<two<<" white - "<<two1 ;
	gotoxy(42, 4);
	cout <<"connect3 : black - "<<three<<" white - "<<three1 ;
	gotoxy(42, 5);
	cout <<"connect4 : black - "<<four<<" white - "<<four1 ;
	gotoxy(42, 6);
	cout <<"connect5 : black - "<<five<<" white - "<<five1 ;
	//
	sentfive=five;
	sentfive1=five1;
	//
	five=0;
	four=0;
	three=0;
	two=0;
	five1=0;
	four1=0;
	three1=0;
	two1=0;
	//
	return 0;
}


int referee::winner_Message(int turn)
{
	//char player[3][3] = {"", "1", "2"}; 
	//char player[3][3] = { "", "○", "●" };//not working
	gotoxy(42, 6);
	if(turn==2)
	{
		if(sentfive1!=0)
			cout <<"connect5 : black - "<<sentfive<<" white - "<<sentfive1-1 ;
	}
	else
	{
		if(sentfive!=0)
			cout <<"connect5 : black - "<<sentfive-1<<" white - "<<sentfive1 ;
	}
	gotoxy(0,21);  
	if (turn==1)
		cout << "○'s WIN. Try again? (y,n)";
	if (turn==2)
		cout << "●'s WIN. Try again? (y,n)";
	
	fflush(stdin);   
	cin>>ans;
	if(ans=='y'||ans=='Y')   //play new game
		return 1;   
	else
	{
		system("cls");
		return 0;  
	}

}