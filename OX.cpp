//Version 1.00

#include <stdio.h>
#include <cstdlib>


//Clear Screen Function
void clearscreen()
{
	int i = 0;
	for ( i = 0; i < 20; i++)
		putchar('\n');
}

//Print Board Function
void printBoard(char pos1, char pos2, char pos3, char pos4, char pos5, char pos6, char pos7, char pos8, char pos9, char turn, char mark, bool end, bool cpu)
{
	printf("\n\n            %c | %c | %c", pos7, pos8, pos9);
	printf("\n           ---+---+---");
	printf("\n            %c | %c | %c", pos4, pos5, pos6);
	printf("\n           ---+---+---");
	printf("\n            %c | %c | %c\n", pos1, pos2, pos3);
	if (end == false)
	{
	printf("\n\n        Player %c (%c)\n", turn, mark);
	printf("   Choose an empty position(.) 1 - 9:\n");
	}
}
//Check End Game Function
void checkEnd(char pos1, char pos2, char pos3, char pos4, char pos5, char pos6, char pos7, char pos8, char pos9, char turn, char mark, bool &end, bool cpu,char discard, bool &draw)
{
	if(pos1 == pos2 && pos2 == pos3 && pos1 != '.')
			end = true;
			
		else if(pos1 == pos5 && pos5 == pos9 && pos1 != '.')
			end = true;
		
		else if(pos1 == pos4 && pos4 == pos7 && pos1 != '.')
			end = true;

		else if(pos2 == pos5 && pos5 == pos8 && pos2 != '.')
			end = true;

		else if(pos3 == pos5 && pos5 == pos7 && pos3 != '.')
			end = true;

		else if(pos3 == pos6 && pos6 == pos9 && pos3 != '.')
			end = true;

		else if(pos4 == pos5 && pos5 == pos6 && pos4 != '.')
			end = true;

		else if(pos7 == pos8 && pos8 == pos9 && pos7 != '.')
			end = true;

		else if(pos1 != '.' && pos2 != '.' && pos3 != '.' && pos4 != '.' && pos5 != '.' && pos6 != '.' && pos7 != '.' && pos8 != '.' && pos9 != '.')
		{//Draw match
			end = true;
			draw = true;
			clearscreen();
			printBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu);
			printf("\n\n        No winners this time!!!\n\n          Press any Key\n\n\n");
			discard = getchar();			
		}
}

//Random character for CPU player Function
char getRandomCharacter(char ch1, char ch2)
{
	return static_cast<char>(ch1 + rand() % (ch2 - ch1 + 1));
}

//Cpu Player Function
void cpuPlayer(char &pos1, char &pos2, char &pos3, char &pos4, char &pos5, char &pos6, char &pos7, char &pos8, char &pos9, char turn, char mark, bool &end, bool cpu, char move, char discard)
{	
	clearscreen();
	printBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu);

	//Check for win position
	if (pos1 == 'O' && pos2 == 'O' && pos3 == '.')
		pos3 = mark;
	else if (pos2 == 'O' && pos3 == 'O' && pos1 == '.')
		pos1 = mark;
	else if (pos1 == 'O' && pos3 == 'O' && pos2 == '.')
		pos2 = mark;
	else if (pos4 == 'O' && pos5 == 'O' && pos6 == '.')
		pos6 = mark;
	else if (pos5 == 'O' && pos6 == 'O' && pos4 == '.')
		pos4 = mark;
	else if (pos4 == 'O' && pos6 == 'O' && pos5 == '.')
		pos5 = mark;
	else if (pos7 == 'O' && pos8 == 'O' && pos9 == '.')
		pos9 = mark;
	else if (pos8 == 'O' && pos9 == 'O' && pos7 == '.')
		pos7 = mark;
	else if (pos7 == 'O' && pos9 == 'O' && pos8 == '.')
		pos8 = mark;
	else if (pos1 == 'O' && pos4 == 'O' && pos7 == '.')
		pos7 = mark;
	else if (pos4 == 'O' && pos7 == 'O' && pos1 == '.')
		pos1 = mark;
	else if (pos1 == 'O' && pos7 == 'O' && pos4 == '.')
		pos4 = mark;
	else if (pos2 == 'O' && pos5 == 'O' && pos8 == '.')
		pos8 = mark;
	else if (pos5 == 'O' && pos8 == 'O' && pos5 == '.')
		pos5 = mark;
	else if (pos2 == 'O' && pos8 == 'O' && pos2 == '.')
		pos2 = mark;
	else if (pos3 == 'O' && pos6 == 'O' && pos9 == '.')
		pos9 = mark;
	else if (pos6 == 'O' && pos9 == 'O' && pos6 == '.')
		pos6 = mark;
	else if (pos3 == 'O' && pos9 == 'O' && pos3 == '.')
		pos2 = mark;
	else if (pos1 == 'O' && pos5 == 'O' && pos9 == '.')
		pos9 = mark;
	else if (pos5 == 'O' && pos9 == 'O' && pos1 == '.')
		pos1 = mark;
	else if (pos1 == 'O' && pos9 == 'O' && pos5 == '.')
		pos5 = mark;
	else if (pos3 == 'O' && pos5 == 'O' && pos7 == '.')
		pos7 = mark;
	else if (pos5 == 'O' && pos7 == 'O' && pos3 == '.')
		pos3 = mark;
	else if (pos3 == 'O' && pos7 == 'O' && pos5 == '.')
		pos5 = mark;

	//Blocking player1
	if (pos5 == 'X' && pos1 == '.' && pos2 == '.' && pos3 == '.' && pos4 == '.' && pos6 == '.' && pos7 == '.' && pos8 == '.' && pos9 == '.')
		pos1 = mark;
	else if (pos5 == 'X' && pos1 == 'O' && pos2 == '.' && pos3 == '.' && pos4 == '.' && pos6 == '.' && pos7 == '.' && pos8 == '.' && pos9 == 'X')
		pos3 = mark;
	else if (pos5 == '.')
		pos5 = mark;
	else if (pos1 == 'X' && pos2 == 'X' && pos3 == '.')
		pos3 = mark;
	else if (pos2 == 'X' && pos3 == 'X' && pos1 == '.')
		pos1 = mark;
	else if (pos1 == 'X' && pos3 == 'X' && pos2 == '.')
		pos2 = mark;
	else if (pos4 == 'X' && pos5 == 'X' && pos6 == '.')
		pos6 = mark;
	else if (pos5 == 'X' && pos6 == 'X' && pos4 == '.')
		pos4 = mark;
	else if (pos4 == 'X' && pos6 == 'X' && pos5 == '.')
		pos5 = mark;
	else if (pos7 == 'X' && pos8 == 'X' && pos9 == '.')
		pos9 = mark;
	else if (pos8 == 'X' && pos9 == 'X' && pos7 == '.')
		pos7 = mark;
	else if (pos7 == 'X' && pos9 == 'X' && pos8 == '.')
		pos8 = mark;
	else if (pos1 == 'X' && pos4 == 'X' && pos7 == '.')
		pos7 = mark;
	else if (pos4 == 'X' && pos7 == 'X' && pos1 == '.')
		pos1 = mark;
	else if (pos1 == 'X' && pos7 == 'X' && pos4 == '.')
		pos4 = mark;
	else if (pos2 == 'X' && pos5 == 'X' && pos8 == '.')
		pos8 = mark;
	else if (pos5 == 'X' && pos8 == 'X' && pos2 == '.')
		pos2 = mark;
	else if (pos2 == 'X' && pos8 == 'X' && pos5 == '.')
		pos5 = mark;
	else if (pos3 == 'X' && pos6 == 'X' && pos9 == '.')
		pos9 = mark;
	else if (pos6 == 'X' && pos9 == 'X' && pos3 == '.')
		pos3 = mark;
	else if (pos3 == 'X' && pos9 == 'X' && pos6 == '.')
		pos6 = mark;
	else if (pos1 == 'X' && pos5 == 'X' && pos9 == '.')
		pos9 = mark;
	else if (pos5 == 'X' && pos9 == 'X' && pos1 == '.')
		pos1 = mark;
	else if (pos1 == 'X' && pos9 == 'X' && pos5 == '.')
		pos5 = mark;
	else if (pos3 == 'X' && pos5 == 'X' && pos7 == '.')
		pos7 = mark;
	else if (pos5 == 'X' && pos7 == 'X' && pos3 == '.')
		pos3 = mark;
	else if (pos3 == 'X' && pos7 == 'X' && pos5 == '.')
		pos5 = mark;
	else
	{
CpuPlayer: //loop for random move
		move = getRandomCharacter( 49, 57);

		if (move >= 49 && move <= 57)
		{
			if (move == 49 && pos1 == '.')
				pos1 = mark;
			else if (move == 50 && pos2 == '.')
				pos2 = mark;
			else if (move == 51 && pos3 == '.')
				pos3 = mark;
			else if (move == 52 && pos4 == '.')
				pos4 = mark;
			else if (move == 53 && pos5 == '.')
				pos5 = mark;
			else if (move == 54 && pos6 == '.')
				pos6 = mark;
			else if (move == 55 && pos7 == '.')
				pos7 = mark;
			else if (move == 56 && pos8 == '.')
				pos8 = mark;
			else if (move == 57 && pos9 == '.')
				pos9 = mark;
			else
			{
				goto CpuPlayer; //Restart loop for random move
			}
		}
	}
}

int main()
{	
Restart: //Restart Game point
	bool cpu = false;
	bool end = false;
	bool draw = false;
	char tempCpu = '0';
	char pos1 = '.'; char pos2 = '.'; char pos3 = '.'; char pos4 = '.'; char pos5 = '.'; char pos6 = '.';
	char pos7 = '.'; char pos8 = '.'; char pos9 = '.';
	char move = 'a';
	char discard = '0';
	char quit = '0';
	char turn = '1';
	char mark = 'X';
	
//Instructions text
	clearscreen();
	printf("\n         Instructions to play Noughts and Crosses:\n\n");
	printf("\n    Choose an empty position(.), and select a number\n       from 1 to 9, as on the sample board below:");
	
	printf("\n\n         Empty Board            Numbers/Positions");
	printf("\n\n          . | . | .                7 | 8 | 9");
	printf("\n         ---+---+---              ---+---+---");
	printf("\n          . | . | .                4 | 5 | 6");
	printf("\n         ---+---+---              ---+---+---");
	printf("\n          . | . | .                1 | 2 | 3\n");

	printf("\n\n            Press Enter to start the game!\n");
	printf("\n        Press 'c' to play against the computer!\n");
	printf("\n                Press 'q' to quit!\n\n");
	tempCpu = getchar();
	discard = getchar();
	if(tempCpu == 'c')
		cpu = true;
	if(tempCpu == 'q')
		goto Quit;
//Game Loop
while (end == false && move != 'q')
{	
Player1: //Start point of player 1
	clearscreen();
	printBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu);
	move = getchar();
	discard = getchar();

	if (move >= 49 && move <=57)
	{
		if (move == 49 && pos1 == '.')
			pos1 = mark;
		else if (move == 50 && pos2 == '.')
			pos2 = mark;
		else if (move == 51 && pos3 == '.')
			pos3 = mark;
		else if (move == 52 && pos4 == '.')
			pos4 = mark;
		else if (move == 53 && pos5 == '.')
			pos5 = mark;
		else if (move == 54 && pos6 == '.')
			pos6 = mark;
		else if (move == 55 && pos7 == '.')
			pos7 = mark;
		else if (move == 56 && pos8 == '.')
			pos8 = mark;
		else if (move == 57 && pos9 == '.')
			pos9 = mark;
		else
		{
			printf("\n  Invalid move from Player %c(%c),\n    press any key to try again!\n\n", turn, mark);
			discard = getchar();
			goto Player1; //Restart player1 move
		}
	}
	else if (move == 'q')
		goto Quit;
	else
	{
		printf("\n  Invalid move from Player %c(%c),\n    press any key to try again!\n\n", turn, mark);
		discard = getchar();
		goto Player1; //Restart player1 move
	}
	//Check for end of game
	checkEnd(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu, discard, draw);

	if (end == true && draw == false)
	{//print the board and winner
		clearscreen();
		printBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu);
		printf("\n\n       Player %c (%c)Wins!\n\n", turn, mark);
		goto Quit;
	}
	else if (end == true && draw == true)
		goto Quit;
	
	//Change of turn and mark to player 2
	if (cpu == true)
	{
		turn = 'C';
		mark = 'O';
	}
	else
	{
		turn = '2';
		mark = 'O';
	}
	if(cpu == false)
	{
Player2:  //Start point of player 2
		clearscreen();
		printBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu);
		move = getchar();
		discard = getchar();
			
		if (move >= 49 && move <= 57)
		{
			if (move == 49 && pos1 == '.')
				pos1 = mark;
			else if (move == 50 && pos2 == '.')
				pos2 = mark;
			else if (move == 51 && pos3 == '.')
				pos3 = mark;
			else if (move == 52 && pos4 == '.')
				pos4 = mark;
			else if (move == 53 && pos5 == '.')
				pos5 = mark;
			else if (move == 54 && pos6 == '.')
				pos6 = mark;
			else if (move == 55 && pos7 == '.')
				pos7 = mark;
			else if (move == 56 && pos8 == '.')
				pos8 = mark;
			else if (move == 57 && pos9 == '.')
				pos9 = mark;
			else
			{
				printf("\n    Invalid move from Player %c(%c),\n      press any key to try again!\n\n", turn, mark);
				discard = getchar();
				goto Player2; //Restart player2 move
			}
		}
		else if (move == 'q')
			goto Quit;
		else
		{
			printf("\n    Invalid move from Player %c(%c),\n      press any key to try again!\n\n", turn, mark);
			discard = getchar();
			goto Player2; //Restart player2 move
		}
		//Check for end of game
		checkEnd(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu, discard, draw);

		if (end == true && draw == false)
		{//print the board and winner
			clearscreen();
			printBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu);
			printf("\n\n       Player %c (%c)Wins!\n\n", turn, mark);
			goto Quit;
		}
		else if (end == true && draw == true)
			goto Quit;

	//Change of turn and mark back to player 1
		turn = '1';
		mark = 'X';
	}
	else //CPU Player
	{
		clearscreen();
		cpuPlayer(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu, move, discard);

	//Check for end of game
		checkEnd(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu, discard, draw);

		if (end == true && draw == false)
	{//print the board and winner
		clearscreen();
		printBoard(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9, turn, mark, end, cpu);
		printf("\n\n       Player %c (%c)Wins!\n\n", turn, mark);
		goto Quit;
	}
	else if (end == true && draw == true)
		goto Quit;

	//Change of turn and mark back to player 1
		turn = '1';
		mark = 'X';
	}
}
Quit:
//Restart or quit
printf("\n\n    To play again press 'Y' to quit press any other key\n\n");
quit = getchar();
discard = getchar();

if(quit == 'y')
	goto Restart;
}
