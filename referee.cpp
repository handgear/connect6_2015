#include "connect.h"

//��������
int referee::countSeries(int x, int y, int ax, int ay) //���ӵ� ������ ī��Ʈ. ��ǥ ������ �ʿ��ϹǷ� ���ڸ� 4�� ����
{
	int sx=x, sy=y;  // x�� sx�� , y�� sy�� ����
	int total=0; //���� ���ӵ� ���� 0���� �ʱ�ȭ
	for(int i=0; i<6; i++){ // ���ӵ� ���� 6���� �ְ��̹Ƿ� for���� 6���� ������.
		if((board[sy][sx] == board[y][x]) && (board[sy][sx] != 0)){
			total++; // ���� ������ �ø���.
			x += ax; // ���� ��ǥ�� ax�� ����
			y += ay; // ���� ��ǥ�� ay�� ����
		} else
			return total; //���� �ҿ��ӵǸ� ���� �ֱٿ� ���ӵ� ���� ������ �������ش�.
	}
	return total;
}

int referee::decideWinner() //���� ���� �Լ�
{
	int temp=0;

	for(int y=0; y<19; y++){
		for(int x=0; x<19; x++){

			temp = countSeries(x, y, 1, 0); //���� (���� ���̰� �� ����)
			if(temp == 6 && ((board[y][x-1] != board[y][x]) || x == 0) ) //���ӵ� �������� �ٵϵ��� 6�̰�,
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
			// counterseries�� �̿��Ͽ� ���� ���ӵ� ������ ���Ϲ����� 6�ϰ�� �ٷ� 1�� �����Ͽ� ��⸦ ������,
			//�׷��� ������� board[y][x]�� ���� ��,�鿡 ���� �ٵ����� �� �����ٿ� 2~5���� ���� ���Ӊ���� Ȯ���Ͽ� ���� ���ش�.
			temp = countSeries(x, y, 0, 1);
			if(temp == 6 && ((board[y-1][x] != board[y][x]) || y == 0) ) //���� (���� ���̰� �� ����)
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
			// counterseries�� �̿��Ͽ� ���� ���ӵ� ������ ���Ϲ����� 6�ϰ�� �ٷ� 1�� �����Ͽ� ��⸦ ������,
			//�׷��� ������� board[y][x]�� ���� ��,�鿡 ���� �ٵ����� �� �����ٿ� 2~5���� ���� ���Ӊ���� Ȯ���Ͽ� ���� ���ش�.
			temp = countSeries(x, y, 1, 1);
			if(temp == 6 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0))) //���밢�� (���� ���̰� ���� ���̰��)
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
			// counterseries�� �̿��Ͽ� ���� ���ӵ� ������ ���Ϲ����� 6�ϰ�� �ٷ� 1�� �����Ͽ� ��⸦ ������,
			//�׷��� ������� board[y][x]�� ���� ��,�鿡 ���� �ٵ����� �� ���밢���� 2~5���� ���� ���Ӊ���� Ȯ���Ͽ� ���� ���ش�.
			temp = countSeries(x, y, -1, 1);
			if(temp == 6 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)))  //���밢�� (���� ���̰� ���� �ø���)
				return 1;
			else if(temp == 5 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)) && board[y][x]==2)
				five++;
			else if(temp == 4 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)) && board[y][x]==2)
				four++;
			else if(temp == 3 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)) && board[y][x]==2)
				three++;
			else if(temp == 2 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)) && board[y][x]==2)
				two++;
			else if(temp == 5 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)) && board[y][x]==1)
				five1++;
			else if(temp == 4 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)) && board[y][x]==1)
				four1++;
			else if(temp == 3 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)) && board[y][x]==1)
				three1++;
			else if(temp == 2 && ((board[y-1][x+1] != board[y][x]) || (x==18 && y==0)) && board[y][x]==1)
				two1++;
			// counterseries�� �̿��Ͽ� ���� ���ӵ� ������ ���Ϲ����� 6�ϰ�� �ٷ� 1�� �����Ͽ� ��⸦ ������,
			//�׷��� ������� board[y][x]�� ���� ��,�鿡 ���� �ٵ����� �� ���밢���� 2~5���� ���� ���Ӊ���� Ȯ���Ͽ� ���� ���ش�.
		}
	}
	gotoxy(42, 3);
	cout <<"2�� : �� - "<<two<<" �� - "<<two1 ;
	gotoxy(42, 4);
	cout <<"3�� : �� - "<<three<<" �� - "<<three1 ;
	gotoxy(42, 5);
	cout <<"4�� : �� - "<<four<<" �� - "<<four1 ;
	gotoxy(42, 6);
	cout <<"5�� : �� - "<<five<<" �� - "<<five1 ;
	//2~5���� ���� ��,�� ������ ������ش�.
	sentfive=five;
	sentfive1=five1;
	//6���� �ɰ�� 5�������� �پ���� �ʰ� �ٷ� ���������� �����ϱ� ���� winner_Message�Լ��� ������ ����ϱ� ���� ���� �� �����̴�.
	five=0;
	four=0;
	three=0;
	two=0;
	five1=0;
	four1=0;
	three1=0;
	two1=0;
	//��� �ٵ����� �ξ��������� �ֽ�ȭ�����ֱ� ���� ������ ���� �ʱ�ȭ �����ش�.
	return 0;
}

//�¸��޽���, �ٽ��ϱ�
int referee::winner_Message(int turn)
{
	char player[3][3]={"", "��", "��"};   
	gotoxy(42, 6);
	if(turn==2)
	{
		if(sentfive1!=0)
			cout <<"5�� : �� - "<<sentfive<<" �� - "<<sentfive1-1 ;
	}
	//�鵹 ���ʿ��� �鵹�� 5���������� 0�� �ƴҰ�� 5�������� 1�� ���ҽ����ش�
	else
	{
		if(sentfive!=0)
			cout <<"5�� : �� - "<<sentfive-1<<" �� - "<<sentfive1 ;
	}
	//�浹 ���ʿ��� �浹�� 5���������� 0�� �ƴҰ�� 5�������� 1�� ���ҽ����ش�
	gotoxy(0,20);   
	cout<<player[turn]<<"�� �¸��Դϴ�. �ٽ� �Ͻðڽ��ϱ�? (y,n)";   
	//0,20 ��ǥ�� ������ �¸����� ������ش�.
	fflush(stdin);   
	//�Է¹��� ������ ���尪�� �����ش�. ��� �׿� ���۰� �������� �����Ѱ��� ��� �� �� �ֱ� ������.
	cin>>ans;
	if(ans=='y'||ans=='Y')   //y�ϰ�� �ٽ� �����ϱ����� return1�� ���ش�.
		return 1;   
	else
	{
		system("cls");
		return 0;  
	}

}