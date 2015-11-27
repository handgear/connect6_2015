#include "connect.h"

int game_ai();

void main()
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
		main();
		//while(1);//for debug
		break;
	case 2: //use while, after exe start, goto main when game over
		while(G1.start());
		main();
		break;
	case 3: //network P2P
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
		main(); 
	}
}

int game_ai()
{
	game G2;
	while(G2.start_ai());
	return 0;
}