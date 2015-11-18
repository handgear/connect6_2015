
#include "connect.h"


int game::start() 
{  
	char stone[3][3]={"","●","○"}; // initialize stone
	map(); 
	//turn==1: white, turn==2: black
	int totalturn = 0, turn2 = 0; //turn2: flag for two turn
	turn = 2;  //first turn is black
	setting::Cursor(); 
	first_move(&y, &x); //first randum move
	
	while(decideWinner() == 0) //yet winner occur 
	{   
		if(turn2==1)
		{//after place two stones
			turn^=3; //change player   			
			turn2=0; //initialize flag
		}
		else turn2++;
		setting::gotoxy(0, 21);   
		cout<<stone[turn]<<"'s turn";  
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
	memset(board, 0, sizeof(int)*17*17); //17x17의 memset배열을 만들어주고 0으로 초기화 해준다.
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
	
	system("CLS"); //각각의 부분을 for문을 이용해 채운 배열을 이제 한번에 출력하기 위해 화면에 있는 값을 지워준다.
	for(y=0; y<17; y++,cout<<endl)
		for(x=0; x<17; x++)   
			cout<<pan[y][x];

	//position number
	setting::gotoxy(0, 17);//bottom board number(1st liine)
	cout << " ";
	for(int i=1;i<18;i++)
	{
		setting::gotoxy(i*2-1, 17);
		
		if (i<10)
			cout<< i; 
		else
			cout << '1';
		
	}
	setting::gotoxy(0, 18);//bottom board number(2nd liine)
	cout << " ";
	for (int i = 1; i<18; i++)
	{
		setting::gotoxy(i * 2 - 1, 18);

		if (i>9)
			cout << i-10;
		
	}
	for (int i = 1; i<18; i++)//right borad number
	{
		setting::gotoxy(34, i-1);
		cout << i;
		
	}
	
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



