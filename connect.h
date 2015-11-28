#pragma once
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  
#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <time.h>
using namespace std;
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

class MySocket;
class setting
{
public:
	void Cursor();
	void gotoxy(int x, int y);
};

class move : public setting
{
public:
	char pan[17][17][3];
	void go(int *y, int *x);
	void first_move(int *y, int *x);
	void input(int *y, int *x, int turn);
};

class referee : public setting
{
private:
	int x, y;
	int count;
	char ans;
	int two, three, four, five, two1, three1, four1, five1;
	int sentfive, sentfive1;
public:
	referee()
	{
		setting();  //for inheritence
		two = three = four = five = two1 = three1 = four1 = five1 = 0;
	}
	int countSeries(int x, int y, int ax, int ay);
	int decideWinner();
	int board[17][17];
	int winner_Message(int turn);

};

class game : public referee, public move
{
private:
	
	int turn1Cnt, turn2Cnt;
	int totalturn = 0; //turn2: flag for two turn
public:
	int x, y, turn, turn2 = 0;
	game()
	{
		referee();
		move();
		turn1Cnt = 0;
		turn2Cnt = 0;
	}
	int friend Socket(int argc, char *argv[]);
	int start_network(int gameMode, MySocket& player, game& gameData);
	int start();
	// int start_ai();
	void initialize();
	void change_turn();
	void update_total_stone_num();
	void map();
	void pause();
	int put(int y_, int x_, int turn);
};

class ai :  public game//public referee
{
private:
	int point_board[17][17][2];
	// int highest_point_x, highest_point_y;
public:
	ai()
	{
		// referee();
		game();
		memset(point_board, 0, sizeof(int)*17*17*2);
	}
void place_point();
void place_first_stone(int turn);
void place_stone(int turn);
void print_point_board();
};