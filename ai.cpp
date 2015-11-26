#include "connect.h"
// #define white 1
// #define black 2

// class ai
// {
// private:
// 	int point_board[17][17][2];
//  int highest_point_x, highest_point_y;
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
		five_two_WH=-9, five_one_WH=-5,
		four_two_WH=-8, four_one_WH=-4,
		three_two_WH=-7, three_one_WH=-3,
		two_two_WH=-6, two_one_WH=-2,

		five_two_BK=9, five_one_BK=5,
		four_two_BK=8, four_one_BK=4,
		three_two_BK=7, three_one_BK=3,
		two_two_BK=6, two_one_BK=2,
	};
	int temp = 0;
	//for debug
	// for(int y=0; y<17; y++,cout<<endl)
	// 	for(int x=0; x<17; x++)   
	// 		board[y][x]=1;
	int test_board[17][17] ={ 
	{ 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0 },
	{ 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0 },
	{ 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0 } };
	//memcpy
	// for(int y=0; y<17; y++)
	// 	for(int x=0; x<17; x++)   
	// 		point_board[y][x][0]=board[y][x];
	for(int y=0; y<17; y++)
		for(int x=0; x<17; x++)   
			board[y][x]=test_board[y][x];
	
	for (int y = 0; y<17; y++){
		for (int x = 0; x<17; x++){
			//row
			temp = countSeries(x, y, 1, 0);
			//if this code can't accsess to x+5, need to be modifiy
			//turn==2 : black stone : AI
			//five
			if (temp == 5 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+5] == 0 && x!=0 && x<12)//0222220
			{
					point_board[y][x-1][1]+=five_two_BK; point_board[y][x+5][1]+=five_two_BK;
			}
			else if(temp == 5 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+5] == 0 && x<12)//1222220
			{
					point_board[y][x+5][1]+=five_one_BK;
			}
			else if(temp == 5 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+5] == 1 && x!=0)//0222221
			{
					point_board[y][x-1][1]+=five_one_BK;
			}
			else if(temp==5 && x==0 && board[y][x] == 2 && board[y][5] == 0)//|222220
				point_board[y][5][1]+=five_one_BK;
			else if(temp==5 && x==12 && board[y][x] == 2 && board[y][11] == 0)//022222|
				point_board[y][11][1]+=five_one_BK;
			//four
			if (temp == 4 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+4] == 0 && x!=0 && x<13)//022220
			{
					point_board[y][x-1][1]+=four_two_BK; point_board[y][x+4][1]+=four_two_BK;
			}
			else if(temp == 4 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+4] == 0 && x<13)//122220
			{
					point_board[y][x+4][1]+=four_one_BK;
			}
			else if(temp == 4 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+4] == 1 && x!=0)//022221
			{
					point_board[y][x-1][1]+=four_one_BK;
			}
			else if(temp==4 && x==0 && board[y][x] == 2 && board[y][4] == 0)//|22220
				point_board[y][4][1]+=four_one_BK;
			else if(temp==4 && x==13 && board[y][x] == 2 && board[y][12] == 0)//02222|
				point_board[y][12][1]+=four_one_BK;
			//three
			if (temp == 3 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+3] == 0 && x!=0 && x<14)//02220
			{
					point_board[y][x-1][1]+=three_two_BK; point_board[y][x+3][1]+=three_two_BK;
			}
			else if(temp == 3 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+3] == 0 && x<14)//12220
			{
					point_board[y][x+3][1]+=three_one_BK;
			}
			else if(temp == 3 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+3] == 1 && x!=0)//02221
			{
					point_board[y][x-1][1]+=three_one_BK;
			}
			else if(temp==3 && x==0 && board[y][x] == 2 && board[y][3] == 0)//|2220
				point_board[y][3][1]+=three_one_BK;
			else if(temp==3 && x==14 && board[y][x] == 2 && board[y][13] == 0)//0222|
				point_board[y][13][1]+=three_one_BK;
			//two
			if (temp == 2 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+2] == 0 && x!=0 && x<15)//0220
			{
					point_board[y][x-1][1]+=two_two_BK; point_board[y][x+2][1]+=two_two_BK;
			}
			else if(temp == 2 && board[y][x - 1] == 1 && board[y][x] == 2 && board[y][x+2] == 0 && x<15)//1220
			{
					point_board[y][x+2][1]+=two_one_BK;
			}
			else if(temp == 2 && board[y][x - 1] == 0 && board[y][x] == 2 && board[y][x+2] == 1 && x!=0)//0221
			{
					point_board[y][x-1][1]+=two_one_BK;
			}
			else if(temp==2 && x==0 && board[y][x] == 2 && board[y][2] == 0)//|220
				point_board[y][2][1]+=two_one_BK;
			else if(temp==2 && x==15 && board[y][x] == 2 && board[y][14] == 0)//022|
				point_board[y][14][1]+=two_one_BK;

			//turn==1 : white stone : player
			//five
			if (temp == 5 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+5] == 0 && x!=0 && x<12)//0111110
			{
					point_board[y][x-1][0]+=five_two_WH; point_board[y][x+5][0]+=five_two_WH;
			}
			else if(temp == 5 && board[y][x - 1] == 2 && board[y][x] == 1 && board[y][x+5] == 0 && x<12)//2111110
			{
					point_board[y][x+5][0]+=five_one_WH;
			}
			else if(temp == 5 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+5] == 2 && x!=0 && x<12)//0111112
			{
					point_board[y][x-1][0]+=five_one_WH;
			}
			else if(temp==5 && x==0 && board[y][x] == 1 && board[y][5] == 0)//|111110
				point_board[y][5][0]+=five_one_WH;
			else if(temp==5 && x==12 && board[y][x] == 1 && board[y][11] == 0)//011111|
				point_board[y][11][0]+=five_one_WH;
			//four
			if (temp == 4 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+4] == 0 && x!=0 && x<13)//011110
			{
					point_board[y][x-1][0]+=four_two_WH; point_board[y][x+4][0]+=four_two_WH;
			}
			else if(temp == 4 && board[y][x - 1] == 2 && board[y][x] == 1 && board[y][x+4] == 0 && x<13)//211110
			{
					point_board[y][x+4][0]+=four_one_WH;
			}
			else if(temp == 4 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+4] == 2 && x!=0 && x<13)//011112
			{
					point_board[y][x-1][0]+=four_one_WH;
			}
			else if(temp==4 && x==0 && board[y][x] == 1 && board[y][4] == 0)//|11110
				point_board[y][4][0]+=four_one_WH;
			else if(temp==4 && x==13 && board[y][x] == 1 && board[y][12] == 0)//01111|
				point_board[y][12][0]+=four_one_WH;
			//three
			if (temp == 3 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+3] == 0 && x!=0 && x<14)//01110
			{
					point_board[y][x-1][0]+=three_two_WH; point_board[y][x+3][0]+=three_two_WH;
			}
			else if(temp == 3 && board[y][x - 1] == 2 && board[y][x] == 1 && board[y][x+3] == 0 && x<14)//21110
			{
					point_board[y][x+3][0]+=three_one_WH;
			}
			else if(temp == 3 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+3] == 2 && x!=0 && x<14)//01112
			{
					point_board[y][x-1][0]+=three_one_WH;
			}
			else if(temp==3 && x==0 && board[y][x] == 1 && board[y][3] == 0)//|1110
				point_board[y][3][0]+=three_one_WH;
			else if(temp==3 && x==14 && board[y][x] == 1 && board[y][13] == 0)//0111|
				point_board[y][13][0]+=three_one_WH;
			//two
			if (temp == 2 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+2] == 0 && x!=0 && x<15)//0110
			{
					point_board[y][x-1][0]+=two_two_WH; point_board[y][x+2][0]+=two_two_WH;
			}
			else if(temp == 2 && board[y][x - 1] == 2 && board[y][x] == 1 && board[y][x+2] == 0 && x<15)//2110
			{
					point_board[y][x+2][0]+=two_one_WH;
			}
			else if(temp == 2 && board[y][x - 1] == 0 && board[y][x] == 1 && board[y][x+2] == 2 && x!=0 && x<15)//0112
			{
					point_board[y][x-1][0]+=two_one_WH;
			}
			else if(temp==2 && x==0 && board[y][x] == 1 && board[y][2] == 0)//|110
				point_board[y][2][0]+=two_one_WH;
			else if(temp==2 && x==15 && board[y][x] == 1 && board[y][14] == 0)//011|
				point_board[y][14][0]+=two_one_WH;
			///////////////////////////////////////////////////////////////////////////////////////
			//column
			temp = countSeries(x, y, 0, 1);
			//turn==2 : black stone : AI
			//five
			if (temp == 5 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+5][x] == 0 && y!=0 && y<12)//0222220
			{
					point_board[y-1][x][1]+=five_two_BK; point_board[y+5][x][1]+=five_two_BK;
			}
			else if(temp == 5 && board[y-1][x] == 1 && board[y][x] == 2 && board[y+5][x] == 0 && y<12)//1222220
			{
					point_board[y+5][x][1]+=five_one_BK;
			}
			else if(temp == 5 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+5][x] == 1 && y!=0 && y<12)//0222221
			{
					point_board[y-1][x][1]+=five_one_BK;
			}
			else if(temp==5 && y==0 && board[y][x] == 2 && board[5][x] == 0)//|222220
				point_board[y][5][1]+=five_one_BK;
			else if(temp==5 && y==12 && board[y][x] == 2 && board[11][x] == 0)//022222|
				point_board[11][x][1]+=five_one_BK;
			//four
			if (temp == 4 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+4][x] == 0 && y!=0 && y<13)//022220
			{
					point_board[y-1][x][1]+=four_two_BK; point_board[y+4][x][1]+=four_two_BK;
			}
			else if(temp == 4 && board[y-1][x] == 1 && board[y][x] == 2 && board[y+4][x] == 0 && y<13)//122220
			{
					point_board[y+4][x][1]+=four_one_BK;
			}
			else if(temp == 4 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+4][x] == 1 && y!=0 && y<13)//022221
			{
					point_board[y-1][x][1]+=four_one_BK;
			}
			else if(temp==4 && y==0 && board[y][x] == 2 && board[5][x] == 0)//|22220
				point_board[y][5][1]+=four_one_BK;
			else if(temp==4 && y==12 && board[y][x] == 2 && board[11][x] == 0)//02222|
				point_board[11][x][1]+=four_one_BK;
			//three
			if (temp == 3 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+3][x] == 0 && y!=0 && y<14)//02220
			{
					point_board[y-1][x][1]+=three_two_BK; point_board[y+3][x][1]+=three_two_BK;
			}
			else if(temp == 3 && board[y-1][x] == 1 && board[y][x] == 2 && board[y+3][x] == 0 && y<14)//12220
			{
					point_board[y+3][x][1]+=three_one_BK;
			}
			else if(temp == 3 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+3][x] == 1 && y!=0 && y<14)//02221
			{
					point_board[y-1][x][1]+=three_one_BK;
			}
			else if(temp==3 && y==0 && board[y][x] == 2 && board[3][x] == 0)//|2220
				point_board[3][x][1]+=three_one_BK;
			else if(temp==3 && y==14 && board[y][x] == 2 && board[13][x] == 0)//0222|
				point_board[13][x][1]+=three_one_BK;
			//two
			if (temp == 2 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+2][x] == 0 && y!=0 && y<15)//0220
			{
					point_board[y-1][x][1]+=two_two_BK; point_board[y+2][x][1]+=two_two_BK;
			}
			else if(temp == 2 && board[y-1][x] == 1 && board[y][x] == 2 && board[y+2][x] == 0 && y<15)//1220
			{
					point_board[y+2][x][1]+=two_one_BK;
			}
			else if(temp == 2 && board[y-1][x] == 0 && board[y][x] == 2 && board[y+2][x] == 1 && y!=0 && y<15)//0221
			{
					point_board[y-1][x][1]+=two_one_BK;
			}
			else if(temp==2 && y==0 && board[y][x] == 2 && board[2][x] == 0)//|220
				point_board[2][x][1]+=two_one_BK;
			else if(temp==2 && y==15 && board[y][x] == 2 && board[14][x] == 0)//022|
				point_board[14][x][1]+=two_one_BK;
		
			//turn==1 : white stone : player
			//five
			if (temp == 5 && board[y-1][x] == 0 && board[y][x] == 1 && board[y+5][x] == 0 && y!=0 && y<12)//0111110
			{
					point_board[y-1][x][0]+=five_two_WH; point_board[y+5][x][0]+=five_two_WH;
			}
			else if(temp == 5 && board[y-1][x] == 2 && board[y][x] == 1 && board[y+5][x] == 0 && y<12)//2111110
			{
					point_board[y+5][x][0]+=five_one_WH;
			}
			else if(temp == 5 && board[y-1][x] == 0 && board[y][x] == 1 && board[y+5][x] == 2 && y!=0 && y<12)//0111112
			{
					point_board[y-1][x][0]+=five_one_WH;
			}
			else if(temp==5 && y==0 && board[y][x] == 1 && board[5][x] == 0)//|111110
				point_board[5][x][0]+=five_one_WH;
			else if(temp==5 && y==12 && board[y][x] == 1 && board[11][x] == 0)//011111|
				point_board[11][x][0]+=five_one_WH;
			//four
			if (temp == 4 && board[y-1][x] == 0 && board[y][x] == 1 && board[y+4][x] == 0 && y!=0 && y<13)//011110
			{
					point_board[y-1][x][0]+=four_two_WH; point_board[y+4][x][0]+=four_two_WH;
			}
			else if(temp == 4 && board[y-1][x] == 2 && board[y][x] == 1 && board[y+4][x] == 0 && y<13)//211110
			{
					point_board[y+4][x][0]+=four_one_WH;
			}
			else if(temp == 4 && board[y-1][x] == 0 && board[y][x] == 1 && board[y+4][x] == 2 && y!=0 && y<13)//011112
			{
					point_board[y-1][x][0]+=four_one_WH;
			}
			else if(temp==4 && y==0 && board[y][x] == 1 && board[4][x] == 0)//|11110
				point_board[4][x][0]+=four_one_WH;
			else if(temp==4 && y==13 && board[y][x] == 1 && board[12][x] == 0)//01111|
				point_board[12][x][0]+=four_one_WH;
			//three
			if (temp == 3 && board[y-1][x] == 0 && board[y][x] == 1 && board[y+3][x] == 0 && y!=0 && y<14)//01110
			{
					point_board[y-1][x][0]+=three_two_WH; point_board[y+3][x][0]+=three_two_WH;
			}
			else if(temp == 3 && board[y-1][x] == 2 && board[y][x] == 1 && board[y+3][x] == 0 && y<14)//21110
			{
					point_board[y+3][x][0]+=three_one_WH;
			}
			else if(temp == 3 && board[y-1][x] == 0 && board[y][x] == 1 && board[y+3][x] == 2 && y!=0 && y<14)//01112
			{
					point_board[y-1][x][0]+=three_one_WH;
			}
			else if(temp==3 && y==0 && board[y][x] == 1 && board[3][x] == 0)//|1110
				point_board[3][x][0]+=three_one_WH;
			else if(temp==3 && y==14 && board[y][x] == 1 && board[13][x] == 0)//0111|
				point_board[13][x][0]+=three_one_WH;
			//two
			if (temp == 2 && board[y-1][x] == 0 && board[y][x] == 1 && board[y+2][x] == 0 && y!=0 && y<15)//0110
			{
					point_board[y-1][x][0]+=two_two_WH; point_board[y+2][x][0]+=two_two_WH;
			}
			else if(temp == 2 && board[y-1][x] == 2 && board[y][x] == 1 && board[y+2][x] == 0 && y<15)//2110
			{
					point_board[y+2][x][0]+=two_one_WH;
			}
			else if(temp == 2 && board[y-1][x] == 0 && board[y][x] == 1 && board[y+2][x] == 2 && y!=0 && y<15)//0112
			{
					point_board[y-1][x][0]+=two_one_WH;
			}
			else if(temp==2 && y==0 && board[y][x] == 1 && board[2][x] == 0)//|110
				point_board[2][x][0]+=two_one_WH;
			else if(temp==2 && y==15 && board[y][x] == 1 && board[14][x] == 0)//011|
				point_board[14][x][0]+=two_one_WH;
			// ///////////////////////////////////////////////////////////////////////////////////////////
			//diagonal
			temp = countSeries(x, y, 1, 1);
			//turn==2 : black stone : AI
			//five
			if (temp == 5 && board[y-1][x - 1] == 0 && board[y][x] == 2 && board[y+5][x+5] == 0 && x!=0 && y!=0 && x<12 && y<12)//0222220
			{
					point_board[y-1][x-1][1]+=five_two_BK; point_board[y+5][x+5][1]+=five_two_BK;
			}
			else if(temp == 5 && board[y-1][x - 1] == 1 && board[y][x] == 2 && board[y+5][x+5] == 0 && x!=0 && y!=0 && x<12 && y<12)//1222220
			{
					point_board[y+5][x+5][1]+=five_one_BK;
			}
			else if(temp == 5 && board[y-1][x - 1] == 0 && board[y][x] == 2 && board[y+5][x+5] == 1 && x!=0 && y!=0 && x<12 && y<12)//0222221
			{
					point_board[y-1][x-1][1]+=five_one_BK;
			}
			else if(temp==5 && (x==0 || y==0) && board[y][x] == 2 && board[y+5][x+5] == 0 && x<12 && y<12)//|222220
				point_board[y+5][x+5][1]+=five_one_BK;
			else if(temp==5 && (x==12 || y==12) && board[y][x] == 2 && board[y-1][x-1] == 0 && x!=0 && y!=0)//022222|
				point_board[y-1][x-1][1]+=five_one_BK;
			//four
			if (temp == 4 && board[y-1][x - 1] == 0 && board[y][x] == 2 && board[y+4][x+4] == 0 && x!=0 && y!=0 && x<13 && y<13)//022220
			{
					point_board[y-1][x - 1][1]+=four_two_BK; point_board[y+4][x+4][1]+=four_two_BK;
			}
			else if(temp == 4 && board[y-1][x - 1] == 1 && board[y][x] == 2 && board[y+4][x+4] == 0 && x!=0 && y!=0 && x<13 && y<13)//122220
			{
					point_board[y+4][x+4][1]+=four_one_BK;
			}
			else if(temp == 4 && board[y-1][x - 1] == 0 && board[y][x] == 2 && board[y+4][x+4] == 1 && x!=0 && y!=0 && x<13 && y<13)//022221
			{
					point_board[y-1][x - 1][1]+=four_one_BK;
			}
			else if(temp==4 && (x==0 || y==0) && board[y][x] == 2 && board[y+4][x+4] == 0 && x<13 && y<13)//|22220
				point_board[y+4][x+4][1]+=four_one_BK;
			else if(temp==4 && (x==13 || y==13) && board[y][x] == 2 && board[y-1][x-1] == 0 && x!=0 && y!=0)//02222|
				point_board[y-1][x-1][1]+=four_one_BK;
			//three
			if (temp == 3 && board[y-1][x - 1] == 0 && board[y][x] == 2 && board[y+3][x+3] == 0 && x!=0 && y!=0 && x<14 && y<14)//02220
			{
				point_board[y-1][x-1][1]+=three_two_BK; point_board[y+3][x+3][1]+=three_two_BK;
			}
			else if(temp == 3 && board[y-1][x - 1] == 1 && board[y][x] == 2 && board[y+3][x+3] == 0 && x!=0 && y!=0 && x<14 && y<14)//12220
			{
				point_board[y+3][x+3][1]+=three_one_BK;
			}
			else if(temp == 3 && board[y-1][x - 1] == 0 && board[y][x] == 2 && board[y+3][x+3] == 1 && x!=0 && y!=0 && x<14 && y<14)//02221
			{
				point_board[y-1][x-1][1]+=three_one_BK;
			}
			else if(temp==3 && (x==0 || y==0) && board[y][x] == 2 && board[y+3][x+3] == 0 && x<14 && y<14)//|2220
				point_board[y+3][x+3][1]+=three_one_BK;
			else if(temp==3 && (x==14 || y==14) && board[y][x] == 2 && board[y-1][x-1] == 0 && x!=0 && y!=0)//0222|
				point_board[y-1][x-1][1]+=three_one_BK;
			//two
			if (temp == 2 && board[y-1][x - 1] == 0 && board[y][x] == 2 && board[y+2][x+2] == 0 && x!=0 && y!=0 && x<15 && y<15)//0220
			{
					point_board[y-1][x-1][1]+=two_two_BK; point_board[y+2][x+2][1]+=two_two_BK;
			}
			else if(temp == 2 && board[y-1][x - 1] == 1 && board[y][x] == 2 && board[y+2][x+2] == 0 && x!=0 && y!=0 && x<15 && y<15)//1220
			{
					point_board[y+2][x+2][1]+=two_one_BK;
			}
			else if(temp == 2 && board[y-1][x - 1] == 0 && board[y][x] == 2 && board[y+2][x+2] == 1 && x!=0 && y!=0 && x<15 && y<15)//0221
			{
					point_board[y-1][x-1][1]+=two_one_BK;
			}
			else if(temp==2 && (x==0 || y==0) && board[y][x] == 2 && board[y+2][x+2] == 0 && x<15 && y<15)//|220
				point_board[y+2][x+2][1]+=two_one_BK;
			else if(temp==2 && (x==15 || y==15) && board[y][x] == 2 && board[y-1][x-1] == 0 && x!=0 && y!=0)//022|
				point_board[y-1][x-1][1]+=two_one_BK;
			
			//turn==1 : white stone : player
			//five
			if (temp == 5 && board[y-1][x - 1] == 0 && board[y][x] == 1 && board[y+5][x+5] == 0 && x!=0 && y!=0 && x<12 && y<12)//0111110
			{
					point_board[y-1][x-1][0]+=five_two_WH; point_board[y+5][x+5][0]+=five_two_WH;
			}
			else if(temp == 5 && board[y-1][x - 1] == 2 && board[y][x] == 1 && board[y+5][x+5] == 0 && x!=0 && y!=0 && x<12 && y<12)//2111110
			{
					point_board[y+5][x+5][0]+=five_one_WH;
			}
			else if(temp == 5 && board[y-1][x - 1] == 0 && board[y][x] == 1 && board[y+5][x+5] == 2 && x!=0 && y!=0 && x<12 && y<12)//0111112
			{
					point_board[y-1][x-1][0]+=five_one_WH;
			}
			else if(temp==5 && (x==0 || y==0) && board[y][x] == 1 && board[y+5][x+5] == 0 && x<12 && y<12)//|111110
				point_board[y+5][x+5][0]+=five_one_WH;
			else if(temp==5 && (x==12 || y==12) && board[y][x] == 1 && board[y-1][x-1] == 0 && x!=0 && y!=0)//011111|
				point_board[y-1][x-1][0]+=five_one_WH;
			//four
			if (temp == 4 && board[y-1][x - 1] == 0 && board[y][x] == 1 && board[y+4][x+4] == 0 && x!=0 && y!=0 && x<13 && y<13)//011110
			{
					point_board[y-1][x - 1][0]+=four_two_WH; point_board[y+4][x+4][0]+=four_two_WH;
			}
			else if(temp == 4 && board[y-1][x - 1] == 2 && board[y][x] == 1 && board[y+4][x+4] == 0 && x!=0 && y!=0 && x<13 && y<13)//211110
			{
					point_board[y+4][x+4][0]+=four_one_WH;
			}
			else if(temp == 4 && board[y-1][x - 1] == 0 && board[y][x] == 1 && board[y+4][x+4] == 2 && x!=0 && y!=0 && x<13 && y<13)//011112
			{
					point_board[y-1][x - 1][0]+=four_one_WH;
			}
			else if(temp==4 && (x==0 || y==0) && board[y][x] == 1 && board[y+4][x+4] == 0 && x<13 && y<13)//|11110
				point_board[y+4][x+4][0]+=four_one_WH;
			else if(temp==4 && (x==13 || y==13) && board[y][x] == 1 && board[y-1][x-1] == 0 && x!=0 && y!=0)//01111|
				point_board[y-1][x-1][0]+=four_one_WH;
			//three
			if (temp == 3 && board[y-1][x - 1] == 0 && board[y][x] == 1 && board[y+3][x+3] == 0 && x!=0 && y!=0 && x<14 && y<14)//01110
			{
					point_board[y-1][x-1][0]+=three_two_WH; point_board[y+3][x+3][0]+=three_two_WH;
			}
			else if(temp == 3 && board[y-1][x - 1] == 2 && board[y][x] == 1 && board[y+3][x+3] == 0 && x!=0 && y!=0 && x<14 && y<14)//21110
			{
					point_board[y+3][x+3][0]+=three_one_WH;
			}
			else if(temp == 3 && board[y-1][x - 1] == 0 && board[y][x] == 1 && board[y+3][x+3] == 2 && x!=0 && y!=0 && x<14 && y<14)//01112
			{
					point_board[y-1][x-1][0]+=three_one_WH;
			}
			else if(temp==3 && (x==0 || y==0) && board[y][x] == 1 && board[y+3][x+3] == 0 && x<14 && x<14)//|1110
				point_board[y+3][x+3][0]+=three_one_WH;
			else if(temp==3 && (x==14 || y==14) && board[y][x] == 1 && board[y-1][x-1] == 0 && x!=0 && y!=0)//0111|
				point_board[y-1][x-1][0]+=three_one_WH;
			//two
			if (temp == 2 && board[y-1][x - 1] == 0 && board[y][x] == 1 && board[y+2][x+2] == 0 && x!=0 && y!=0 && x<15 && y<15)//0110
			{
					point_board[y-1][x-1][0]+=two_two_WH; point_board[y+2][x+2][0]+=two_two_WH;
			}
			else if(temp == 2 && board[y-1][x - 1] == 2 && board[y][x] == 1 && board[y+2][x+2] == 0 && x!=0 && y!=0 && x<15 && y<15)//2110
			{
					point_board[y+2][x+2][0]+=two_one_WH;
			}
			else if(temp == 2 && board[y-1][x - 1] == 0 && board[y][x] == 1 && board[y+2][x+2] == 2 && x!=0 && y!=0 && x<15 && y<15)//0112
			{
					point_board[y-1][x-1][0]+=two_one_WH;
			}
			else if(temp==2 && (x==0 || y==0) && board[y][x] == 1 && board[y+2][x+2] == 0 && x<15 && y<15)//|110
				point_board[y+2][x+2][0]+=two_one_WH;
			else if(temp==2 && (x==15 || y==15) && board[y][x] == 1 && board[y-1][x-1] == 0 && x!=0 && y!=0)//011|
				point_board[y-1][x-1][0]+=two_one_WH;
			// ///////////////////////////////////////////////////////////////////////////////////////////
			//anti-diagonal
			temp = countSeries(x, y, -1, 1);
			//turn==2 : black stone : AI
			//five
			// 0000P
			// 00020
			// 00200
			// 02000
			// 20000
			if (temp == 5 && board[y-1][x + 1] == 0 && board[y][x] == 2 && board[y+5][x-5] == 0 && x!=0 && y!=0 && x>4 && x<16 && y<12)//0222220
			{
					point_board[y-1][x+1][1]+=five_two_BK; point_board[y+5][x-5][1]+=five_two_BK;
			}
			else if(temp == 5 && board[y-1][x + 1] == 1 && board[y][x] == 2 && board[y+5][x-5] == 0 && x!=0 && y!=0 && x>4 && x<16 && y<12)//1222220
			{
					point_board[y+5][x-5][1]+=five_one_BK;
			}
			else if(temp == 5 && board[y-1][x + 1] == 0 && board[y][x] == 2 && board[y+5][x-5] == 1 && x!=0 && y!=0 && x>4 && x<16 && y<12)//0222221
			{
					point_board[y-1][x+1][1]+=five_one_BK;
			}
			else if(temp==5 && (x==16 || y==0) && board[y][x] == 2 && board[y+5][x-5] == 0 && x>4 && y<12)//|222220
				point_board[y+5][x-5][1]+=five_one_BK;
			else if(temp==5 && (x==4 || y==12) && board[y][x] == 2 && board[y-1][x+1] == 0 && x>3 && x!=16 && y<13)//022222|
				point_board[y-1][x+1][1]+=five_one_BK;
			// four
			if (temp == 4 && board[y-1][x + 1] == 0 && board[y][x] == 2 && board[y+4][x-4] == 0 && x!=0 && y!=0 && x>3 && x<16 && y<13)//022220
			{
					point_board[y-1][x + 1][1]+=four_two_BK; point_board[y+4][x-4][1]+=four_two_BK;
			}
			else if(temp == 4 && board[y-1][x + 1] == 1 && board[y][x] == 2 && board[y+4][x-4] == 0 && x!=0 && y!=0 && x>3 && x<16 && y<13)//122220
			{
					point_board[y+4][x-4][1]+=four_one_BK;
			}
			else if(temp == 4 && board[y-1][x + 1] == 0 && board[y][x] == 2 && board[y+4][x-4] == 1 && x!=0 && y!=0 && x>3 && x<16 && y<13)//022221
			{
					point_board[y-1][x + 1][1]+=four_one_BK;
			}
			else if(temp==4 && (x==16 || y==0) && board[y][x] == 2 && board[y+4][x-4] == 0 && x>3 && y<13)//|22220
				point_board[y+4][x-4][1]+=four_one_BK;
			else if(temp==4 && (x==3 || y==13) && board[y][x] == 2 && board[y-1][x+1] == 0 && x>2 && x!=16 && y<14)//02222|
				point_board[y-1][x+1][1]+=four_one_BK;
			// three
			if (temp == 3 && board[y-1][x + 1] == 0 && board[y][x] == 2 && board[y+3][x-3] == 0 && x!=0 && y!=0 && x>2 && x<16 && y<14)//02220
			{
				point_board[y-1][x+1][1]+=three_two_BK; point_board[y+3][x-3][1]+=three_two_BK;
			}
			else if(temp == 3 && board[y-1][x + 1] == 1 && board[y][x] == 2 && board[y+3][x-3] == 0 && x!=0 && y!=0 && x>2 && x<16 && y<14)//12220
			{
				point_board[y+3][x-3][1]+=three_one_BK;
			}
			else if(temp == 3 && board[y-1][x + 1] == 0 && board[y][x] == 2 && board[y+3][x-3] == 1 && x!=0 && y!=0 && x>2 && x<16 && y<14)//02221
			{
				point_board[y-1][x+1][1]+=three_one_BK;
			}
			else if(temp==3 && (x==16 || y==0) && board[y][x] == 2 && board[y+3][x-3] == 0 && x>2 && y<14)//|2220
				point_board[y+3][x-3][1]+=three_one_BK;
			else if(temp==3 && (x==2 || y==14) && board[y][x] == 2 && board[y-1][x+1] == 0 && x>1 && x!=16 && y<15)//0222|
				point_board[y-1][x+1][1]+=three_one_BK;
			//two
			if (temp == 2 && board[y-1][x + 1] == 0 && board[y][x] == 2 && board[y+2][x-2] == 0 && x!=0 && y!=0 && x>1 && x<16 && y<15)//0220
			{
					point_board[y-1][x+1][1]+=two_two_BK; point_board[y+2][x-2][1]+=two_two_BK;
			}
			else if(temp == 2 && board[y-1][x + 1] == 1 && board[y][x] == 2 && board[y+2][x-2] == 0 && x!=0 && y!=0 && x>1 && x<16 && y<15)//1220
			{
					point_board[y+2][x-2][1]+=two_one_BK;
			}
			else if(temp == 2 && board[y-1][x + 1] == 0 && board[y][x] == 2 && board[y+2][x-2] == 1 && x!=0 && y!=0 && x>1 && x<16 && y<15)//0221
			{
					point_board[y-1][x+1][1]+=two_one_BK;
			}
			else if(temp==2 && (x==16 || y==0) && board[y][x] == 2 && board[y+2][x-2] == 0 && x>1 && y<15)//|220
				point_board[y+2][x-2][1]+=two_one_BK;
			else if(temp==2 && (x==1 || y==15) && board[y][x] == 2 && board[y-1][x+1] == 0 && x>0 && x!=16 && y<16)//022|
				point_board[y-1][x+1][1]+=two_one_BK;
			
			//turn==1 : white stone : player
			//five
			if (temp == 5 && board[y-1][x + 1] == 0 && board[y][x] == 1 && board[y+5][x-5] == 0 && x!=0 && y!=0 && x>4 && x<16 && y<12)//0111110
			{
					point_board[y-1][x+1][0]+=five_two_WH; point_board[y+5][x-5][0]+=five_two_WH;
			}
			else if(temp == 5 && board[y-1][x + 1] == 2 && board[y][x] == 1 && board[y+5][x-5] == 0 && x!=0 && y!=0 && x>4 && x<16 && y<12)//2111110
			{
					point_board[y+5][x-5][0]+=five_one_WH;
			}
			else if(temp == 5 && board[y-1][x + 1] == 0 && board[y][x] == 1 && board[y+5][x-5] == 2 && x!=0 && y!=0 && x>4 && x<16 && y<12)//0111112
			{
					point_board[y-1][x+1][0]+=five_one_WH;
			}
			else if(temp==5 && (x==16 || y==0) && board[y][x] == 1 && board[y+5][x-5] == 0 && x>4 && y<12)//|111110
				point_board[y+5][x-5][0]+=five_one_WH;
			else if(temp==5 && (x==4 || y==12) && board[y][x] == 1 && board[y-1][x+1] == 0 && x>3 && x!=16 && y<13)//011111|
				point_board[y-1][x+1][0]+=five_one_WH;
			// four
			if (temp == 4 && board[y-1][x + 1] == 0 && board[y][x] == 1 && board[y+4][x-4] == 0 && x!=0 && y!=0 && x>3 && x<16 && y<13)//011110
			{
					point_board[y-1][x + 1][0]+=four_two_WH; point_board[y+4][x-4][0]+=four_two_WH;
			}
			else if(temp == 4 && board[y-1][x + 1] == 2 && board[y][x] == 1 && board[y+4][x-4] == 0 && x!=0 && y!=0 && x>3 && x<16 && y<13)//211110
			{
					point_board[y+4][x-4][0]+=four_one_WH;
			}
			else if(temp == 4 && board[y-1][x + 1] == 0 && board[y][x] == 1 && board[y+4][x-4] == 2 && x!=0 && y!=0 && x>3 && x<16 && y<13)//011112
			{
					point_board[y-1][x + 1][0]+=four_one_WH;
			}
			else if(temp==4 && (x==16 || y==0) && board[y][x] == 1 && board[y+4][x-4] == 0 && x>3 && y<13)//|11110
				point_board[y+4][x-4][0]+=four_one_WH;
			else if(temp==4 && (x==3 || y==13) && board[y][x] == 1 && board[y-1][x+1] == 0 && x>2 && x!=16 && y<14)//01111|
				point_board[y-1][x+1][0]+=four_one_WH;
			// three
			if (temp == 3 && board[y-1][x + 1] == 0 && board[y][x] == 1 && board[y+3][x-3] == 0 && x!=0 && y!=0 && x>2 && x<16 && y<14)//01110
			{
				point_board[y-1][x+1][0]+=three_two_WH; point_board[y+3][x-3][0]+=three_two_WH;
			}
			else if(temp == 3 && board[y-1][x + 1] == 2 && board[y][x] == 1 && board[y+3][x-3] == 0 && x!=0 && y!=0 && x>2 && x<16 && y<14)//21110
			{
				point_board[y+3][x-3][0]+=three_one_WH;
			}
			else if(temp == 3 && board[y-1][x + 1] == 0 && board[y][x] == 1 && board[y+3][x-3] == 2 && x!=0 && y!=0 && x>2 && x<16 && y<14)//01112
			{
				point_board[y-1][x+1][0]+=three_one_WH;
			}
			else if(temp==3 && (x==16 || y==0) && board[y][x] == 1 && board[y+3][x-3] == 0 && x>2 && y<14)//|1110
				point_board[y+3][x-3][0]+=three_one_WH;
			else if(temp==3 && (x==2 || y==14) && board[y][x] == 1 && board[y-1][x+1] == 0 && x>1 && x!=16 && y<15)//0111|
				point_board[y-1][x+1][0]+=three_one_WH;
			//two
			if (temp == 2 && board[y-1][x + 1] == 0 && board[y][x] == 1 && board[y+2][x-2] == 0 && x!=0 && y!=0 && x>1 && x<16 && y<15)//0110
			{
					point_board[y-1][x+1][0]+=two_two_WH; point_board[y+2][x-2][0]+=two_two_WH;
			}
			else if(temp == 2 && board[y-1][x + 1] == 2 && board[y][x] == 1 && board[y+2][x-2] == 0 && x!=0 && y!=0 && x>1 && x<16 && y<15)//2110
			{
					point_board[y+2][x-2][0]+=two_one_WH;
			}
			else if(temp == 2 && board[y-1][x + 1] == 0 && board[y][x] == 1 && board[y+2][x-2] == 2 && x!=0 && y!=0 && x>1 && x<16 && y<15)//0112
			{
					point_board[y-1][x+1][0]+=two_one_WH;
			}
			else if(temp==2 && (x==16 || y==0) && board[y][x] == 1 && board[y+2][x-2] == 0 && x>1 && y<15)//|110
				point_board[y+2][x-2][0]+=two_one_WH;
			else if(temp==2 && (x==1 || y==15) && board[y][x] == 1 && board[y-1][x+1] == 0 && x>0 && x!=16 && y<16)//011|
				point_board[y-1][x+1][0]+=two_one_WH;
			
		}
	}

}
void ai::print_point_board()
{
	for(int y=0; y<17; y++,cout<<endl)
		for(int x=0; x<17; x++)   
			cout<<board[y][x];
	cout<<endl;
	for(int y=0; y<17; y++,cout<<endl)
		for(int x=0; x<17; x++)   
			cout<<point_board[y][x][0];
	cout<<endl;
	for(int y=0; y<17; y++,cout<<endl)
		for(int x=0; x<17; x++)   
			cout<<point_board[y][x][1];
}