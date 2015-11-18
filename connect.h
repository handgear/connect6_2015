#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  
#include <windows.h>
#include <time.h>
using namespace std;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

class setting
{
public :
	void Cursor();
	void gotoxy(int x, int y);
};

class move : public setting
{
public :
	char pan[17][17][3];
	void go(int *y, int *x);
	void first_move(int *y, int *x);
};

class referee : public setting
{
private :
	int x,y;
	int count;
	char ans;
	int two,three,four,five,two1,three1,four1,five1;
	int sentfive,sentfive1;
public :
	referee()
	{
		setting();  //for inheritence
		two=three=four=five=two1=three1=four1=five1=0;
	}
	int countSeries(int x, int y, int ax, int ay);
	int decideWinner(); 
	int board[17][17]; 
	int winner_Message(int turn); 

};
class game : public referee , public move 
{
private :
	int x, y, turn;
	int turn1Cnt, turn2Cnt;
public :
	game()
	{
		referee();
		move();
		turn1Cnt = 0;
		turn2Cnt = 0;
	}
	int start();
	void map();
	void pause();
	int put(int y, int x, int turn);
};