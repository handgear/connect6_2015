
#include "connect.h"


int game::start() 
{  
	char stone[3][3]={"","��","��"}; // initialize stone
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
		while(!put(y, x, turn))  //put �Լ����� enterġ�������� Ŀ����� �̵�.
		{   
			go(&y, &x);   //call by reference�� go �Լ����� ���� ��ǥ������ �̵�,
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
	memset(board, 0, sizeof(int)*17*17); //17x17�� memset�迭�� ������ְ� 0���� �ʱ�ȭ ���ش�.
	//corner
	strcpy(pan[0][0], "��");
	strcpy(pan[0][16] ,"��");   
	strcpy(pan[16][0],"��");
	strcpy(pan[16][16],"��");   
	//side
	for(y=1; y<16; y++)   
	{   
		strcpy(pan[y][0], "��");
		strcpy(pan[y][16],"��");
	}   
	//bottom and top
	for(x=1; x<16; x++)   
	{   
		strcpy(pan[0][x], "��");   
		strcpy(pan[16][x],"��");   
	} 
	//else
	for(y=1; y<16; y++)     
		for(x=1; x<16; x++)         
			strcpy(pan[y][x],"��");   
	
	system("CLS"); //������ �κ��� for���� �̿��� ä�� �迭�� ���� �ѹ��� ����ϱ� ���� ȭ�鿡 �ִ� ���� �����ش�.
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
	char stone[3][3]={"","��","��"};   
	if(board[y][x] == 0)   //�����ϰ��ִ� �ٵϹ��� ��ġ�� �ٵϵ��� ������� if������ ����.
	{   

		board[y][x]=turn;   //�ٵ��� ��ġ�� ���� turn ���� �Է��Ѵ�.
		strcpy(pan[y][x], stone[turn]);   //�� ����� ���� ���� ���� ��ȯ��Ų��.
		setting::gotoxy(x*2, y); 
		cout<<stone[turn];   
		//��ȯ�� ��ǥ�� �̵��Ͽ� ������� ����Ѵ�.
		return 1;   
	}   
	return 0;   
}
void game::pause() 
{
	_getch();  // �ƹ� Ű�� 1�� �Է� �ޱ�
	puts(""); // �ٹٲ�
}



