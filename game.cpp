
#include "connect.h"


int game::start() 
{  
	char stone[3][3]={"","��","��"}; // initialize stone
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
	go(&y, &x); //go �Լ� 9,9�� �̵�???

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
	memset(board, 0, sizeof(int)*19*19); //19x19�� memset�迭�� ������ְ� 0���� �ʱ�ȭ ���ش�.
	strcpy(pan[0][0], "��");
	strcpy(pan[0][18] ,"��");   
	strcpy(pan[18][0],"��");
	strcpy(pan[18][18],"��");   
	//�� ���̵忡�� ���Ͱ��� ���ڿ��� ���� ä���ش�.
	for(y=1; y<18; y++)   
	{   
		strcpy(pan[y][0], "��");
		strcpy(pan[y][18],"��");
	}   
	//�¿� ���ڶ��� ������ �������� ���Ͱ��� ���ڿ��� �Խ�Ų��.
	for(x=1; x<18; x++)   
	{   
		strcpy(pan[0][x], "��");   
		strcpy(pan[18][x],"��");   
	} 
	//���� ���ڶ��� ������ �������� ���Ͱ��� ���ڿ��� �Խ�Ų��.
	for(y=1; y<18; y++)     
		for(x=1; x<18; x++)         
			strcpy(pan[y][x],"��");   
	//������ ��� �κ��� +������� �� ä���ش�.
	system("CLS"); //������ �κ��� for���� �̿��� ä�� �迭�� ���� �ѹ��� ����ϱ� ���� ȭ�鿡 �ִ� ���� �����ش�.
	for(y=0; y<19; y++,cout<<endl)
		for(x=0; x<19; x++)   
			cout<<pan[y][x];
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



