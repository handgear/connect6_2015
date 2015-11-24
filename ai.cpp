#include "connect.h"
// #define white 1
// #define black 2

// class ai
// {
// private:
// 	int point_board[17][17][2];
// public:

// void point_initialize();
// void place_point();
// void print_point_board();
// };


void ai::place_point()
{
	enum POINT//set weight point
	{
		//connedted_unblocked number
		five_two=12, five_one=10,
		four_two=12, four_one=10,
		three_two=12, three_one=10,
		two_two=12, two_one=10,
	};
	int temp = 0;
	//for debug
	for(int y=0; y<17; y++,cout<<endl)
		for(int x=0; x<17; x++)   
			board[y][x]=1;
	//memcpy
	for(int y=0; y<17; y++)
		for(int x=0; x<17; x++)   
			point_board[y][x][0]=board[y][x];
	
	for (int y = 0; y<17; y++){
		for (int x = 0; x<17; x++){
			//row
			temp = countSeries(x, y, 1, 0);
			//if this code can't accsess to x+5, need to be modifiy
			//turn==2
			//five
			if (temp == 5 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+5] == 0)//0222220
			{
					point_board[y][x-1][1]=five_two; point_board[y][x+5][1]=five_two;
			}
			else if(temp == 5 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+5] == 0)//1222220
			{
					point_board[y][x+5][1]=five_one;
			}
			else if(temp == 5 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+5] == 1)//0222221
			{
					point_board[y][x-1][1]=five_one;
			}
			else if(temp==5 && x==0 && board[y][x] == 2 && board[y][5] == 0)//|222220
				point_board[y][5][1]=five_one;
			else if(temp==5 && x==12 && board[y][x] == 2 && board[y][11] == 0)//022222|
				point_board[y][11][1]=five_one;
			//four
			if (temp == 4 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+4] == 0)//022220
			{
					point_board[y][x-1][1]=four_two; point_board[y][x+4][1]=four_two;
			}
			else if(temp == 4 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+4] == 0)//122220
			{
					point_board[y][x+4][1]=four_one;
			}
			else if(temp == 4 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+4] == 1)//022221
			{
					point_board[y][x-1][1]=four_one;
			}
			else if(temp==4 && x==0 && board[y][x] == 2 && board[y][4] == 0)//|22220
				point_board[y][4][1]=four_one;
			else if(temp==4 && x==13 && board[y][x] == 2 && board[y][12] == 0)//02222|
				point_board[y][12][1]=four_one;
			//three
			if (temp == 3 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+3] == 0)//02220
			{
					point_board[y][x-1][1]=three_two; point_board[y][x+3][1]=three_two;
			}
			else if(temp == 3 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+3] == 0)//12220
			{
					point_board[y][x+3][1]=three_one;
			}
			else if(temp == 3 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+3] == 1)//02221
			{
					point_board[y][x-1][1]=three_one;
			}
			else if(temp==3 && x==0 && board[y][x] == 2 && board[y][3] == 0)//|2220
				point_board[y][3][1]=three_one;
			else if(temp==3 && x==14 && board[y][x] == 2 && board[y][13] == 0)//0222|
				point_board[y][13][1]=three_one;
			//two
			if (temp == 2 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+2] == 0)//0220
			{
					point_board[y][x-1][1]=two_two; point_board[y][x+2][1]=two_two;
			}
			else if(temp == 2 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+2] == 0)//1220
			{
					point_board[y][x+2][1]=two_one;
			}
			else if(temp == 2 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+2] == 1)//0221
			{
					point_board[y][x-1][1]=two_one;
			}
			else if(temp==2 && x==0 && board[y][x] == 2 && board[y][2] == 0)//|220
				point_board[y][3][1]=two_one;
			else if(temp==2 && x==15 && board[y][x] == 2 && board[y][14] == 0)//022|
				point_board[y][14][1]=two_one;

			//turn==1
			//five
			if (temp == 5 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+5] == 0)//0111110
			{
					point_board[y][x-1][0]=five_two; point_board[y][x+5][0]=five_two;
			}
			else if(temp == 5 && board[y][x - 1] == 2 && board[y][x] == 1 && board[y][x+5] == 0)//2111110
			{
					point_board[y][x+5][0]=five_one;
			}
			else if(temp == 5 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+5] == 2)//0111112
			{
					point_board[y][x-1][0]=five_one;
			}
			else if(temp==5 && x==0 && board[y][x] == 1 && board[y][5] == 0)//|111110
				point_board[y][5][0]=five_one;
			else if(temp==5 && x==12 && board[y][x] == 1 && board[y][11] == 0)//011111|
				point_board[y][11][0]=five_one;
			//four
			if (temp == 4 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+4] == 0)//011110
			{
					point_board[y][x-1][0]=four_two; point_board[y][x+4][0]=four_two;
			}
			else if(temp == 4 && board[y][x - 1] == 2 && board[y][x] == 1 && board[y][x+4] == 0)//211110
			{
					point_board[y][x+4][0]=four_one;
			}
			else if(temp == 4 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+4] == 2)//011112
			{
					point_board[y][x-1][0]=four_one;
			}
			else if(temp==4 && x==0 && board[y][x] == 1 && board[y][4] == 0)//|11110
				point_board[y][4][0]=four_one;
			else if(temp==4 && x==13 && board[y][x] == 1 && board[y][12] == 0)//01111|
				point_board[y][12][0]=four_one;
			//////////////////////////////need to be modify
			//three
			if (temp == 3 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+3] == 0)//02220
			{
					point_board[y][x-1][1]=three_two; point_board[y][x+3][1]=three_two;
			}
			else if(temp == 3 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+3] == 0)//12220
			{
					point_board[y][x+3][1]=three_one;
			}
			else if(temp == 3 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+3] == 1)//02221
			{
					point_board[y][x-1][1]=three_one;
			}
			else if(temp==3 && x==0 && board[y][x] == 2 && board[y][3] == 0)//|2220
				point_board[y][3][1]=three_one;
			else if(temp==3 && x==14 && board[y][x] == 2 && board[y][13] == 0)//0222|
				point_board[y][13][1]=three_one;
			//two
			if (temp == 2 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+2] == 0)//0220
			{
					point_board[y][x-1][1]=two_two; point_board[y][x+2][1]=two_two;
			}
			else if(temp == 2 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+2] == 0)//1220
			{
					point_board[y][x+2][1]=two_one;
			}
			else if(temp == 2 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+2] == 1)//0221
			{
					point_board[y][x-1][1]=two_one;
			}
			else if(temp==2 && x==0 && board[y][x] == 2 && board[y][2] == 0)//|220
				point_board[y][3][1]=two_one;
			else if(temp==2 && x==15 && board[y][x] == 2 && board[y][14] == 0)//022|
				point_board[y][14][1]=two_one;

			//column
			temp = countSeries(x, y, 0, 1);
			//five
			if (temp == 5 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+5][x] == 0)//0222220
			{
					point_board[y-1][x][1]=five_two; point_board[y+5][x][1]=five_two;
			}
			else if(temp == 5 && board[y-1][x] == 1 && board[y][x] == 2 && board[y+5][x] == 0)//1222220
			{
					point_board[y+5][x][1]=five_one;
			}
			else if(temp == 5 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+5][x] == 1)//0222221
			{
					point_board[y-1][x][1]=five_one;
			}
			else if(temp==5 && y==0 && board[y][x] == 2 && board[5][x] == 0)//|222220
				point_board[y][5][1]=five_one;
			else if(temp==5 && y==12 && board[y][x] == 2 && board[11][x] == 0)//022222|
				point_board[11][x][1]=five_one;
			//four
			if (temp == 4 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+4][x] == 0)//022220
			{
					point_board[y-1][x][1]=four_two; point_board[y+4][x][1]=four_two;
			}
			else if(temp == 4 && board[y-1][x] == 1 && board[y][x] == 2 && board[y+4][x] == 0)//122220
			{
					point_board[y+4][x][1]=four_one;
			}
			else if(temp == 4 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+4][x] == 1)//022221
			{
					point_board[y-1][x][1]=four_one;
			}
			else if(temp==4 && y==0 && board[y][x] == 2 && board[5][x] == 0)//|22220
				point_board[y][5][1]=four_one;
			else if(temp==4 && y==12 && board[y][x] == 2 && board[11][x] == 0)//02222|
				point_board[11][x][1]=four_one;
			//
			temp = countSeries(x, y, 1, 1);
			if (temp == 6 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0))) //
				return 1;
			else if (temp == 5 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0)) && board[y][x] == 2)
				five++;
			else if (temp == 4 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0)) && board[y][x] == 2)
				four++;
			else if (temp == 3 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0)) && board[y][x] == 2)
				three++;
			else if (temp == 2 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0)) && board[y][x] == 2)
				two++;
			else if (temp == 5 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0)) && board[y][x] == 1)
				five1++;
			else if (temp == 4 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0)) && board[y][x] == 1)
				four1++;
			else if (temp == 3 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0)) && board[y][x] == 1)
				three1++;
			else if (temp == 2 && ((board[y - 1][x - 1] != board[y][x]) || (x == 0 && y == 0)) && board[y][x] == 1)
				two1++;
			// 
			//
			temp = countSeries(x, y, -1, 1);
			if (temp == 6 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)))  //
				return 1;
			else if (temp == 5 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)) && board[y][x] == 2)
				five++;
			else if (temp == 4 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)) && board[y][x] == 2)
				four++;
			else if (temp == 3 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)) && board[y][x] == 2)
				three++;
			else if (temp == 2 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)) && board[y][x] == 2)
				two++;
			else if (temp == 5 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)) && board[y][x] == 1)
				five1++;
			else if (temp == 4 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)) && board[y][x] == 1)
				four1++;
			else if (temp == 3 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)) && board[y][x] == 1)
				three1++;
			else if (temp == 2 && ((board[y - 1][x + 1] != board[y][x]) || (x == 16 && y == 0)) && board[y][x] == 1)
				two1++;
			//
			//
		}
	}

}
void ai::print_point_board()
{
	for(int y=0; y<17; y++,cout<<endl)
		for(int x=0; x<17; x++)   
			cout<<point_board[y][x][0];
	cout<<endl;
	for(int y=0; y<17; y++,cout<<endl)
		for(int x=0; x<17; x++)   
			cout<<point_board[y][x][1];
}