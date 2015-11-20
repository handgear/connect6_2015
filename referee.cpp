#include "connect.h"

//½ÂÆÐÆÇÁ¤
int referee::countSeries(int x, int y, int ax, int ay) //¿¬¼ÓµÈ µ¹Á¶ÇÕ Ä«¿îÆ®. ÁÂÇ¥ ¼öÁ¤ÀÌ ÇÊ¿äÇÏ¹Ç·Î ÀÎÀÚ¸¦ 4°³ ¹ÞÀ½
{
	int sx=x, sy=y;  // x¸¦ sx¿¡ , y¸¦ sy¿¡ ÀúÀå
	int total=0; //µ¹ÀÇ ¿¬¼ÓµÈ °¹¼ö 0À¸·Î ÃÊ±âÈ­
	for(int i=0; i<6; i++){ // ¿¬¼ÓµÈ µ¹Àº 6°³°¡ ÃÖ°íÀÌ¹Ç·Î for¹®À» 6¹ø¸¸ µ¹¸°´Ù.
		if((board[sy][sx] == board[y][x]) && (board[sy][sx] != 0)){
			total++; // µ¹ÀÇ °¹¼ö¸¦ ´Ã¸°´Ù.
			x += ax; // ¿­ÀÇ ÁÂÇ¥¸¦ ax¾¿ Áõ°¡
			y += ay; // ÇàÀÇ ÁÂÇ¥¸¦ ay¾¿ Áõ°¡
		} else
			return total; //µ¹ÀÌ ºÒ¿¬¼ÓµÇ¸é °¡Àå ÃÖ±Ù¿¡ ¿¬¼ÓµÈ µ¹ÀÇ °¹¼ö¸¦ ¸®ÅÏÇØÁØ´Ù.
	}
	return total;
}

int referee::decideWinner() //½ÂÆÐ °áÁ¤ ÇÔ¼ö
{
	int temp=0;

	for(int y=0; y<17; y++){
		for(int x=0; x<17; x++){

			temp = countSeries(x, y, 1, 0); //°¡·Î (¿­À» ÁÙÀÌ°í Çà °íÁ¤)
			if(temp == 6 && ((board[y][x-1] != board[y][x]) || x == 0) ) //¿¬¼ÓµÈ °°Àº»öÀÇ ¹ÙµÏµ¹ÀÌ 6ÀÌ°í,
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
			// counterseries¸¦ ÀÌ¿ëÇÏ¿© µ¹ÀÇ ¿¬¼ÓµÈ °¹¼ö¸¦ ¸®ÅÏ¹ÞÀºµÚ 6ÀÏ°æ¿ì ¹Ù·Î 1À» ¸®ÅÏÇÏ¿© °æ±â¸¦ ³¡³»°í,
			//±×·¸Áö ¾ÊÀ»°æ¿ì board[y][x]ÀÇ °ªÀÌ Èæ,¹é¿¡ µû¶ó ¹ÙµÏÆÇÀÇ °¢ °¡·ÎÁÙ¿¡ 2~5±îÁö µ¹ÀÇ ¿¬¼Ó‰ç´ÂÁö È®ÀÎÇÏ¿© °¢°¢ ¼¼ÁØ´Ù.
			temp = countSeries(x, y, 0, 1);
			if(temp == 6 && ((board[y-1][x] != board[y][x]) || y == 0) ) //¼¼·Î (ÇàÀ» ÁÙÀÌ°í ¿­ °íÁ¤)
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
			// counterseries¸¦ ÀÌ¿ëÇÏ¿© µ¹ÀÇ ¿¬¼ÓµÈ °¹¼ö¸¦ ¸®ÅÏ¹ÞÀºµÚ 6ÀÏ°æ¿ì ¹Ù·Î 1À» ¸®ÅÏÇÏ¿© °æ±â¸¦ ³¡³»°í,
			//±×·¸Áö ¾ÊÀ»°æ¿ì board[y][x]ÀÇ °ªÀÌ Èæ,¹é¿¡ µû¶ó ¹ÙµÏÆÇÀÇ °¢ ¼¼·ÎÁÙ¿¡ 2~5±îÁö µ¹ÀÇ ¿¬¼Ó‰ç´ÂÁö È®ÀÎÇÏ¿© °¢°¢ ¼¼ÁØ´Ù.
			temp = countSeries(x, y, 1, 1);
			if(temp == 6 && ((board[y-1][x-1] != board[y][x]) || (x==0 && y==0))) //¿ª´ë°¢¼± (ÇàÀ» ÁÙÀÌ°í ¿­À» ÁÙÀÌ°í°í)
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
			// counterseries¸¦ ÀÌ¿ëÇÏ¿© µ¹ÀÇ ¿¬¼ÓµÈ °¹¼ö¸¦ ¸®ÅÏ¹ÞÀºµÚ 6ÀÏ°æ¿ì ¹Ù·Î 1À» ¸®ÅÏÇÏ¿© °æ±â¸¦ ³¡³»°í,
			//±×·¸Áö ¾ÊÀ»°æ¿ì board[y][x]ÀÇ °ªÀÌ Èæ,¹é¿¡ µû¶ó ¹ÙµÏÆÇÀÇ °¢ ¿ª´ë°¢¼±¿¡ 2~5±îÁö µ¹ÀÇ ¿¬¼Ó‰ç´ÂÁö È®ÀÎÇÏ¿© °¢°¢ ¼¼ÁØ´Ù.
			temp = countSeries(x, y, -1, 1);
			if(temp == 6 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)))  //Á¤´ë°¢¼± (ÇàÀ» ÁÙÀÌ°í ¿­À» ´Ã¸®°í)
				return 1;
			else if(temp == 5 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==2)
				five++;
			else if(temp == 4 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==2)
				four++;
			else if(temp == 3 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==2)
				three++;
			else if(temp == 2 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==2)
				two++;
			else if(temp == 5 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==1)
				five1++;
			else if(temp == 4 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==1)
				four1++;
			else if(temp == 3 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==1)
				three1++;
			else if(temp == 2 && ((board[y-1][x+1] != board[y][x]) || (x==16 && y==0)) && board[y][x]==1)
				two1++;
			// counterseries¸¦ ÀÌ¿ëÇÏ¿© µ¹ÀÇ ¿¬¼ÓµÈ °¹¼ö¸¦ ¸®ÅÏ¹ÞÀºµÚ 6ÀÏ°æ¿ì ¹Ù·Î 1À» ¸®ÅÏÇÏ¿© °æ±â¸¦ ³¡³»°í,
			//±×·¸Áö ¾ÊÀ»°æ¿ì board[y][x]ÀÇ °ªÀÌ Èæ,¹é¿¡ µû¶ó ¹ÙµÏÆÇÀÇ °¢ Á¤´ë°¢¼±¿¡ 2~5±îÁö µ¹ÀÇ ¿¬¼Ó‰ç´ÂÁö È®ÀÎÇÏ¿© °¢°¢ ¼¼ÁØ´Ù.
		}
	}
	gotoxy(42, 3);
	cout <<"2°³ : Èæ - "<<two<<" ¹é - "<<two1 ;
	gotoxy(42, 4);
	cout <<"3°³ : Èæ - "<<three<<" ¹é - "<<three1 ;
	gotoxy(42, 5);
	cout <<"4°³ : Èæ - "<<four<<" ¹é - "<<four1 ;
	gotoxy(42, 6);
	cout <<"5°³ : Èæ - "<<five<<" ¹é - "<<five1 ;
	//2~5±îÁö °¢°¢ Èæ,¹é Á¶ÇÕÀ» Ãâ·ÂÇØÁØ´Ù.
	sentfive=five;
	sentfive1=five1;
	//6°³°¡ µÉ°æ¿ì 5ÀÇÁ¶ÇÕÀÌ ÁÙ¾îµéÁö ¾Ê°í ¹Ù·Î ³¡³ª´ÂÁ¡À» ¼öÁ¤ÇÏ±â À§ÇØ winner_MessageÇÔ¼ö·Î º¸³»¼­ Ãâ·ÂÇÏ±â À§ÇÑ º¯¼ö °ª ¼±¾ðÀÌ´Ù.
	five=0;
	four=0;
	three=0;
	two=0;
	five1=0;
	four1=0;
	three1=0;
	two1=0;
	//°è¼Ó ¹ÙµÏÆÇÀÌ µÎ¾îÁú¶§¸¶´Ù ÃÖ½ÅÈ­½ÃÄÑÁÖ±â À§ÇØ ¿ø·¡ÀÇ °ªÀº ÃÊ±âÈ­ ½ÃÄÑÁØ´Ù.
	return 0;
}

//½Â¸®¸Þ½ÃÁö, ´Ù½ÃÇÏ±â
int referee::winner_Message(int turn)
{
	char player[3][3] = { "", "¡Û", "¡Ü"};   
	gotoxy(42, 6);
	if(turn==2)//6°³ ¿¬°áÀÌ µÇ¾úÀ¸¹Ç·Î 5°³´Â 1 ÁÙ¿©ÁØ´Ù
	{
		if(sentfive1!=0)
			cout <<"5°³ : Èæ - "<<sentfive<<" ¹é - "<<sentfive1-1 ;
	}
	else
	{
		if(sentfive!=0)
			cout <<"5°³ : Èæ - "<<sentfive-1<<" ¹é - "<<sentfive1 ;
	}
	gotoxy(0,21);   
	cout<<player[turn]<<"'s WIN. Try again? (y,n)";   
	
	fflush(stdin);   
	cin>>ans;
	if(ans=='y'||ans=='Y')   //play new game
		return 1;   
	else
	{
		system("cls");
		return 0;  
	}

}