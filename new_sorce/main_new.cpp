#include "connect_new.h"

void main()
{
	game G1;
	//game class def
	int button;
	while(1)//add exit condition
	{
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"                                                                               "<<endl;
		cout<<"-------------------------------------------------------------------------------"<<endl;
		cout<<"                               1) 1P play"<<endl;
		cout<<"                               2) 2P play"<<endl;
		cout<<"                               3) network P2P"<<endl;
		cout<<"                               4) setting    "<<endl;
		cin>>button;
		switch(button)
		{
		case 1: //AI
			break;
		case 2: //use while, after exe start, goto main when game over
			//while(G1.start());
			break;
		case 3: //network P2P
			break;
		case 4: //setting menu
			break;
		default:
			cout<<"select number"<<endl;
			G1.pause(); 
			system("cls"); 
		}
	}
	
}
