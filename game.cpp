
#include "connect.h"


int game::start() 
{  
	char stone[3][3]={"","●","○"}; // initialize stone
	map(); 
	setting::Cursor(); 
	y=x=9; //initialize to center
	turn=2;  //first turn is black
	//turn==1: white, turn==2: black
	int totalturn=0, turn2=0; //turn2: flag for two turn
	setting::gotoxy(x*2,y);  //initialize to center
	cout<<"GO"; //print "go"
	setting::gotoxy(0, 20);  //set curser below the board 
	cout<<stone[turn^=0]<<"turn"; //
	go(&y, &x); //go 함수 9,9로 이동???

	while(decideWinner() == 0) //yet winner occur 
	{   
		if(turn2==1)
		{//after place two stones
			turn^=3; //change player   			
			turn2=0; //initialize flag
		}
		else turn2++;
		setting::gotoxy(0, 20);   
		cout<<stone[turn]<<"turn";  
		while(!put(y, x, turn))  //put 함수에서 enter치기전까지 커서대로 이동.
		{   
			go(&y, &x);   //call by reference로 go 함수에서 받은 좌표값으로 이동,
		} 
		if(turn==1) //turn==white, print num of white stone 
		{
			setting::gotoxy(42, 0);
			cout <<"white Stone : "<< ++turn1Cnt;
		}
		else //turn==black, print num of black stone 
		{
			setting::gotoxy(42, 1);
			cout << "Black Stone : "<<++turn2Cnt;
		}
		setting::gotoxy(42, 2);
		cout <<"Total : "<<++totalturn; 
	} 

	return winner_Message(turn^=3);   

}

//print board  
void game::map()   
{
	memset(board, 0, sizeof(int)*19*19); //19x19의 memset배열을 만들어주고 0으로 초기화 해준다.
	strcpy(pan[0][0], "┌");
	strcpy(pan[0][18] ,"┐");   
	strcpy(pan[18][0],"└");
	strcpy(pan[18][18],"┘");   
	//양 사이드에는 위와같은 문자열로 판을 채워준다.
	for(y=1; y<18; y++)   
	{   
		strcpy(pan[y][0], "├");
		strcpy(pan[y][18],"┤");
	}   
	//좌우 끝자락을 제외한 나머지를 위와같은 문자열로 입시킨다.
	for(x=1; x<18; x++)   
	{   
		strcpy(pan[0][x], "┬");   
		strcpy(pan[18][x],"┴");   
	} 
	//상하 끝자락을 제외한 나머지를 위와같은 문자열로 입시킨다.
	for(y=1; y<18; y++)     
		for(x=1; x<18; x++)         
			strcpy(pan[y][x],"┼");   
	//나머지 가운데 부분을 +모양으로 다 채워준다.
	system("CLS"); //각각의 부분을 for문을 이용해 채운 배열을 이제 한번에 출력하기 위해 화면에 있는 값을 지워준다.
	for(y=0; y<19; y++,cout<<endl)
		for(x=0; x<19; x++)   
			cout<<pan[y][x];
}
int game::put(int y, int x, int turn)   
{
	char stone[3][3]={"","●","○"};   
	if(board[y][x] == 0)   //지정하고있는 바둑반의 위치에 바둑돌이 없을경우 if문으로 들어간다.
	{   

		board[y][x]=turn;   //바둑판 위치에 현재 turn 돌을 입력한다.
		strcpy(pan[y][x], stone[turn]);   //판 모양을 현재 턴의 돌로 변환시킨다.
		setting::gotoxy(x*2, y); 
		cout<<stone[turn];   
		//변환된 좌표로 이동하여 돌모양을 출력한다.
		return 1;   
	}   
	return 0;   
}
void game::pause() 
{
	_getch();  // 아무 키나 1개 입력 받기
	puts(""); // 줄바꿈
}



