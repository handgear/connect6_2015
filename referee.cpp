#include "connect.h"

//승패판정
int referee::countSeries(int x, int y, int ax, int ay) //연속된 돌조합 카운트. 좌표 수정이 필요하므로 인자를 4개 받음
{
	int sx=x, sy=y;  // x를 sx에 , y를 sy에 저장
	int total=0; //돌의 연속된 갯수 0으로 초기화
	for(int i=0; i<6; i++){ // 연속된 돌은 6개가 최고이므로 for문을 6번만 돌린다.
		if((board[sy][sx] == board[y][x]) && (board[sy][sx] != 0)){
			total++; // 돌의 갯수를 늘린다.
			x += ax; // 열의 좌표를 ax씩 증가
			y += ay; // 행의 좌표를 ay씩 증가
		} else
			return total; //돌이 불연속되면 가장 최근에 연속된 돌의 갯수를 리턴해준다.
	}
	return total;
}

int referee::decideWinner() //승패 결정 함수
{
	int temp=0;

	for(int y=0; y<17; y++){
		for(int x=0; x<17; x++){

			temp = countSeries(x, y, 1, 0); //가로 (열을 줄이고 행 고정)
			if(temp == 6 && ((board[y][x-1] != board[y][x]) || x == 0) ) //연속된 같은색의 바둑돌이 6이고,
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
			// counterseries를 이용하여 돌의 연속된 갯수를 리턴받은뒤 6일경우 바로 1을 리턴하여 경기를 끝내고,
			//그렇지 않을경우 board[y][x]의 값이 흑,백에 따라 바둑판의 각 가로줄에 2~5까지 돌의 연속됬는지 확인하여 각각 세준다.
			temp = countSeries(x, y, 0, 1);
			if(temp == 6 && ((board[y-1][x] != board[y][x]) || y == 0) ) //세로 (행을 줄이고 열 고정)
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
			// counterseries를 이용하여 돌의 연속된 갯수를 리턴받은뒤 6일경우 바로 1을 리턴하여 경기를 끝내고,
			//그렇지 않을경우 board[y][x]의 값이 흑,백에 따라 바둑판의 각 세로줄에 2~5까지 돌의 연속됬는지 확인하여 각각 세준다.
			temp = countSeries(x, y, 1, 1);
			if(temp == 6 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0))) //역대각선 (행을 줄이고 열을 줄이고고)
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
			// counterseries를 이용하여 돌의 연속된 갯수를 리턴받은뒤 6일경우 바로 1을 리턴하여 경기를 끝내고,
			//그렇지 않을경우 board[y][x]의 값이 흑,백에 따라 바둑판의 각 역대각선에 2~5까지 돌의 연속됬는지 확인하여 각각 세준다.
			temp = countSeries(x, y, -1, 1);
			if(temp == 6 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)))  //정대각선 (행을 줄이고 열을 늘리고)
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
			// counterseries를 이용하여 돌의 연속된 갯수를 리턴받은뒤 6일경우 바로 1을 리턴하여 경기를 끝내고,
			//그렇지 않을경우 board[y][x]의 값이 흑,백에 따라 바둑판의 각 정대각선에 2~5까지 돌의 연속됬는지 확인하여 각각 세준다.
		}
	}
	gotoxy(42, 3);
	cout <<"2개 : 흑 - "<<two<<" 백 - "<<two1 ;
	gotoxy(42, 4);
	cout <<"3개 : 흑 - "<<three<<" 백 - "<<three1 ;
	gotoxy(42, 5);
	cout <<"4개 : 흑 - "<<four<<" 백 - "<<four1 ;
	gotoxy(42, 6);
	cout <<"5개 : 흑 - "<<five<<" 백 - "<<five1 ;
	//2~5까지 각각 흑,백 조합을 출력해준다.
	sentfive=five;
	sentfive1=five1;
	//6개가 될경우 5의조합이 줄어들지 않고 바로 끝나는점을 수정하기 위해 winner_Message함수로 보내서 출력하기 위한 변수 값 선언이다.
	five=0;
	four=0;
	three=0;
	two=0;
	five1=0;
	four1=0;
	three1=0;
	two1=0;
	//계속 바둑판이 두어질때마다 최신화시켜주기 위해 원래의 값은 초기화 시켜준다.
	return 0;
}

//승리메시지, 다시하기
int referee::winner_Message(int turn)
{
	char player[3][3] = { "", "○", "●"};   
	gotoxy(42, 6);
	if(turn==2)//6개 연결이 되었으므로 5개는 1 줄여준다
	{
		if(sentfive1!=0)
			cout <<"5개 : 흑 - "<<sentfive<<" 백 - "<<sentfive1-1 ;
	}
	else
	{
		if(sentfive!=0)
			cout <<"5개 : 흑 - "<<sentfive-1<<" 백 - "<<sentfive1 ;
	}
	gotoxy(0,21);   
	cout<<player[turn]<<"'s WIN. Try again? (y,n)";   
	
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