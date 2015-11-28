#include "MySocket.h"
#include "connect.h"

int Socket(int argc, char *argv[]);
int Socket_AI(int argc, char *argv[]);
int game_ai();

void main(int argc, char *argv[])
{ 
	game G1;
	ai test_ai2;
	//game class def
	int button;
	cout<<"                               1) 1P play"<<endl;
	cout<<"                               2) 2P play"<<endl;
	cout<<"                               3) network P2P"<<endl;
	cout<<"                               4) network AI "<<endl;
	cin>>button;
	switch(button)
	{
	case 1: //AI
		while(game_ai());
		main(argc, argv);
		//while(1);//for debug
		break;
	case 2: //use while, after exe start, goto main when game over
		while(G1.start());
		main(argc, argv);
		break;
	case 3: //network P2P
		Socket(argc, argv);
		main(argc, argv);
		break;
	case 4: //network AI
		Socket_AI(argc, argv);
		main(argc, argv);
		break;
	case 5: //for test
		// while(game_ai());
		// main(argc, argv);
		// test_ai2.place_point();
		// test_ai2.place_stone(2);
		// test_ai2.print_point_board();
		while(1);
		break;
	default:
		cout<<"select number"<<endl;
		G1.pause(); 
		system("cls"); 
		main(argc, argv);
	}
}

int game_ai()
{
	//game G2;
	
	setting set;
	ai test_ai;
	
	char stone[3][3]={"","●","○"};
	int temp_first=0;
	test_ai.initialize();
	while(test_ai.decideWinner() == 0) //yet winner occur 
	{   
		if(test_ai.turn2==2)
		{//after place two stones
			//change player   		
			if (test_ai.turn == 2)
				test_ai.turn = 1;
			else
				test_ai.turn = 2;
			test_ai.turn2=0; //initialize flag
			set.gotoxy(0, 21);   
			cout<<stone[test_ai.turn]<<"'s turn";  
		}

		while(test_ai.turn==1 && test_ai.turn2<2)//user
		{
			//test_ai.go(&test_ai.y, &test_ai.x);//for debug

			while(1)
			{
				test_ai.input(&test_ai.y, &test_ai.x,test_ai.turn);//input position to move
				if(test_ai.board[test_ai.y][test_ai.x]==1 || test_ai.board[test_ai.y][test_ai.x]==2)
				{
					set.gotoxy(0, 24);
					cout<<"please input valied position";
					set.gotoxy(0, 23);
					cout<<"                 ";	
				}
				else
					break;
			}
			test_ai.put(test_ai.y, test_ai.x, test_ai.turn);
			test_ai.update_total_stone_num();
			test_ai.turn2++;
		}
		while(test_ai.turn==2 && test_ai.turn2<2)//ai
		{
			if(temp_first==0)
			{
				test_ai.place_first_stone(test_ai.turn);
				temp_first=1;
				test_ai.update_total_stone_num();
				test_ai.turn2++;

			}
			else if(temp_first==1)
			{
				test_ai.place_point();
				test_ai.place_stone(test_ai.turn);
				
				test_ai.update_total_stone_num();
				test_ai.turn2++;
			}
			
		}
	}
	return test_ai.winner_Message(test_ai.turn^=3);
}

int Socket(int argc, char *argv[])
{
//typedef struct{
//	int x,y;
//	int win;//0:game running, 1:sever win ,2:client win
//	int turn;//1:sever turn ,2:client turn
//}GAME_DATA;
   int gameMode;
   game gameData;
   MySocket player(sizeof(game));
   do{
	   system("cls");
	   cout << "1. This Machine will work as a Server" << endl;
	   cout << "2. This Machine will work as a Client" << endl;
	   cin >> gameMode;

	   if (gameMode == SE)
	   {
		   player.ServerSetting();
		   player.ServerRun();
		   gameData.turn = SE;
		   player.SendData(&gameData); // Game Running Signal and Send its my turn
	   }
	   else if (gameMode == CL)
	   {
		   player.ClientSetting();
		   player.ClientRun();
		   player.RecvData(&gameData);// Game Running Signal and Receive its other side turn
	   }
   }
	while( gameData.start_network(gameMode, player, gameData));
  //==================================================================
	// Implement Connect-6 Algorithm Below

	// Example of Data Sending And Receiving
	//if(gameMode==SE){
	//	gameData.x=5;
	//	gameData.y=5;
	//	player.SendData(&gameData);
	//}else if(gameMode==CL){
	//	player.RecvData(&gameData);
	//}
	//cout << "DATA:" << endl
	//	<< gameData.x << endl
	//	<< gameData.y << endl;
	//system("pause");

	//==================================================================
	return 0;
}
int Socket_AI(int argc, char *argv[])
{
//typedef struct{
//	int x,y;
//	int win;//0:game running, 1:sever win ,2:client win
//	int turn;//1:sever turn ,2:client turn
//}GAME_DATA;
	int temp_first=0;
	int temp_end=1;
  int gameMode;
  ai gameData;
  setting set;
  MySocket player(sizeof(game));

	while(temp_end)
	{
		system("cls");
	  cout << "1. This Machine will work as a Server" << endl;
	  cout << "2. This Machine will work as a Client" << endl;
	  cin >> gameMode;

	  if (gameMode == SE)//black stone
	  {
		  player.ServerSetting();
		  player.ServerRun();
		  gameData.turn = SE;
		  player.SendData(&gameData); // Game Running Signal and Send its my turn
	  }
	  else if (gameMode == CL)//white stone
	  {
		  player.ClientSetting();
		  player.ClientRun();
		  player.RecvData(&gameData);// Game Running Signal and Receive its other side turn
	  }

		char stone[3][3]={"","●","○"}; // initialize stone
		int totalturn = 0, turn2 = 0; //turn2: flag for two turn
		gameData.initialize();
		while(gameData.decideWinner() == 0) //yet winner occur 
		{  
			if(turn2==2)
			{//after place two stones
				//change player   		
				if (gameData.turn == 2)
					gameData.turn = 1;
				else
					gameData.turn = 2;
				turn2=0; //initialize flag
				set.gotoxy(0, 21);   
				cout<<stone[gameData.turn]<<"'s turn";  
			}
			if(gameMode==SE)//black stone
			{
				while(gameData.turn==1 && turn2<2)//white stone, client, other side
				{
					player.RecvData(&gameData);
					gameData.put(gameData.y, gameData.x, gameData.turn);
					gameData.update_total_stone_num();
					turn2++;
				}
				while(gameData.turn==2 && turn2<2)//black stone, server, our side(AI)
				{
					if(temp_first==0)
					{
						gameData.place_first_stone(gameData.turn);
						player.SendData(&gameData);
						temp_first=1;
						gameData.update_total_stone_num();
						turn2++;

					}
					else if(temp_first==1)
					{
						gameData.place_point();
						gameData.place_stone(gameData.turn);
						player.SendData(&gameData);
						gameData.update_total_stone_num();
						turn2++;
					}			
				}
			}
			else if(gameMode==CL)//white stone
			{
				while(gameData.turn==1 && turn2<2)//white stone, client, our side(AI)
				{
					if(temp_first==0)
					{
						gameData.place_first_stone(gameData.turn);
						player.SendData(&gameData);
						temp_first=1;
						gameData.update_total_stone_num();
						turn2++;

					}
					else if(temp_first==1)
					{
						gameData.place_point();
						gameData.place_stone(gameData.turn);
						player.SendData(&gameData);
						gameData.update_total_stone_num();
						turn2++;
					}			
				}
				while(gameData.turn==2 && turn2<2)//black stone, server, other side
				{
					player.RecvData(&gameData);
					gameData.put(gameData.y, gameData.x, gameData.turn);
					gameData.update_total_stone_num();
					turn2++;
				}
			}
		}
		temp_end=gameData.winner_Message(gameData.turn^=3);   
	}
	return 0;
}