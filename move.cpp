#include "connect.h"

//�̵��ϱ�
void move::go(int *y, int *x) // �Լ������� �� ���� (������)   
{   
	int oy=*y, ox=*x;   // ox, oy�� ���� ��ǥ 
	char input;    // Ű����� �޴� input

	while((input=_getch()) != ENTER)   // Enter ġ�� ������ �Է¿� �°� ��ġ �̵�
	{   
		if(input == UP)   
		{   
			ox=*x;   
			oy=(*y)--;   
		}   
		else if(input == DOWN)   
		{   
			ox=*x;   
			oy=(*y)++;   
		}   
		else if(input == LEFT)   
		{   
			ox=(*x)--;   
			oy=*y;   
		}   
		else if(input == RIGHT)   
		{   
			ox=(*x)++;   
			oy=*y;   
		}

		(*x)=((*x) + 17) % 17;   // �ٵ����� ������ �����̸� �ݴ��� ������ ��
		(*y)=((*y) + 17) % 17;   
		gotoxy(ox*2, oy);   //Ŀ���� �̵��ǰ� ���� �ִ� �κп��´ٽ� �ٵ��� ����� ä��
		cout<<pan[oy][ox];  // ȭ��ǥ�� �̵��ϴ� ��ġ 
		gotoxy((*x)*2, *y);  
		cout<<"��";   //���� ��ġ�ϰ� �ִ� ��ǥ�� �� ���
	}

}
