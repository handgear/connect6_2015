#include "MySocket.h"
#include "connect.h"


int game::start() 
{  
	char stone[3][3]={"","●","○"}; // initialize stone
	int totalturn = 0, turn2 = 0; //turn2: flag for two turn
	initialize();
	while(decideWinner() == 0) //yet winner occur 
	{   
		if(turn2==2)
		{//after place two stones
			//change player   		
			if (turn == 2)
				turn = 1;
			else
				turn = 2;
			turn2=0; //initialize flag
			setting::gotoxy(0, 21);   
		cout<<stone[turn]<<"'s turn"; 
		}
	
		while(1)
		{
			input(&y, &x,turn);//input position to move
			if(board[y][x]==1 || board[y][x]==2)
			{
				setting::gotoxy(0, 24);
				cout<<"please input valied position";
				setting::gotoxy(0, 23);
				cout<<"                 ";	
			}
			else
				break;	
		}
		// go(&y, &x); //for debug
		put(y, x, turn); 
		turn2++;
		
		if(turn==1) //turn==white, print total num of white stone 
		{
			setting::gotoxy(42, 0);
			cout <<"white Stone : "<< ++turn1Cnt;
		}
		else //turn==black, print total num of black stone 
		{
			setting::gotoxy(42, 1);
			cout << "Black Stone : "<<++turn2Cnt;
		}
		setting::gotoxy(42, 2);
		cout <<"Total : "<<++totalturn; 
	} 

	return winner_Message(turn^=3);   

}
// int game::start_ai()
// {
// 	char stone[3][3]={"","●","○"};
// 	initialize();
// 	while(decideWinner() == 0) //yet winner occur 
// 	{   
// 		if(turn2==2)
// 		{//after place two stones
// 			//change player   		
// 			if (turn == 2)
// 				turn = 1;
// 			else
// 				turn = 2;
// 			turn2=0; //initialize flag
// 			setting::gotoxy(0, 21);   
// 			cout<<stone[turn]<<"'s turn";  
// 		}

// 		//else turn2++;
// 		while(turn==1 && turn2<2)//user
// 		{
// 			go(&y, &x);
// 			put(y, x, turn);
// 			//input(&y, &x,turn);//input position to move		
// 			update_total_stone_num();
// 			turn2++;
// 		}
// 		while(turn==2 && turn2<2)//ai
// 		{
			
// 			// ai->place_point();
// 			// ai->place_stone(turn);

// 			update_total_stone_num();
// 			turn2++;
// 		}
		
// 	} 

// 	return winner_Message(turn^=3); 
// }
int game::start_network(int gameMode, MySocket& player, game& gameData) 
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
			//change player   		
			if (turn == 2)
				turn = 1;
			else
				turn = 2;
			turn2=0; //initialize flag
		}
		else turn2++;
		setting::gotoxy(0, 21);   
		cout<<stone[turn]<<"'s turn";  
		
		while(!put(y, x, turn))  //
		{   
			//go(&y, &x);   //
					
			if (gameMode == SE){ 
				if (turn == 2){
					input(&y, &x, turn);//input position to move
					player.SendData(&gameData);
				}
				else if (turn == 1){
					player.RecvData(&gameData);
				}
				 }
			if (gameMode == CL){
				if (turn == 2){
					player.RecvData(&gameData);
				}
				else if (turn == 1){
					input(&y, &x, turn);//input position to move
					player.SendData(&gameData);
				}
			}
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
void game::initialize()//draw board and put first stone
{
	map(); 
	//turn==1: white, turn==2: black
	turn = 2;  //first turn is black
	setting::Cursor(); 
	first_move(&y, &x); //first randum move
	put(y, x, turn);
	turn=1;//next is white turn
	//while (1);//for debug
}
void game::change_turn()
{
	char stone[3][3]={"","●","○"}; // initialize stone
	if(turn2==1)
	{//after place two stones
		//change player   		
		if (turn == 2)
			turn = 1;
		else
			turn = 2;
		turn2=0; //initialize flag
	}
	else turn2++;
	setting::gotoxy(0, 21);   
	cout<<stone[turn]<<"'s turn";  
}
void game::update_total_stone_num()
{
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
//print board  
void game::map()   
{
	memset(board, 0, sizeof(int)*17*17); //
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
	
	system("CLS"); //
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
	if(board[y][x] == 0)   //
	{   

		board[y][x]=turn;   //
		strcpy(pan[y][x], stone[turn]);   //
		setting::gotoxy(x*2, y); 
		cout<<stone[turn];   
		//
		return 1;   
	}   
	return 0;   
}
void game::pause() 
{
	_getch();  // 
	puts(""); //
}



