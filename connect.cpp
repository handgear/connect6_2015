#include "MySocket.h"
#include "connect.h"

int Socket(int argc, char *argv[]);
int game_ai();

void main(int argc, char *argv[])
{ 
	game G1;
	ai test_ai;
	//game class def
	int button;
	// cout<<"-------------------------------------------------------------------------------"<<endl;
	// cout<<"==============================================================================="<<endl;
	// cout<<"==    66666    CCCCC    OOOOO    N NNN    N NNN    EEEEE    CCCCC    TTTTT   =="<<endl;
	// cout<<"==    66       CC       OO  O    NN  N    NN  N    EE       CC        TT     =="<<endl;
	// cout<<"==    66666    CC       OO  O    NN  N    NN  N    EEEEE    CC        TT     =="<<endl;
	// cout<<"==    66  6    CC       OO  O    NN  N    NN  N    EE       CC        TT     =="<<endl;
	// cout<<"==    66666    CCCCC    OOOOO    NN  N    NN  N    EEEEE    CCCCC     TT     =="<<endl;
	// cout<<"==============================================================================="<<endl;
	// cout<<"==============================================================================="<<endl;
	cout<<"                               1) 1P play"<<endl;
	cout<<"                               2) 2P play"<<endl;
	cout<<"                               3) network P2P"<<endl;
	cout<<"                               4) setting    "<<endl;
	cin>>button;
	switch(button)
	{
	case 1: //AI
		while(G1.start_ai());
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
	case 4: //setting menu
		break;
	case 5: //for test
		game_ai();
		test_ai.place_point();
		test_ai.print_point_board();
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
	game G2;
	while(G2.start_ai());
	return 0;
}

int Socket(int argc, char *argv[]){
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