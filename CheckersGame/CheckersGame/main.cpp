#include <iostream>

using namespace std;

#define ROWS 8
#define COLS 8
#define Error -1

enum Piece
{
	INVALID,		//0
	EMPTY,			//1
	WHITE,			//2
	BLACK,			//3
	WHITE_CROWN,	//4
	BLACK_CROWN		//5
};

//converting data to symbol on board
char dataToSymbol(int data)
{
	switch (data)
	{
	case Piece::INVALID:
		return ' ';
	case Piece::EMPTY:
		return ' ';
	case Piece::WHITE:
		return 'w';
	case Piece::BLACK:
		return 'b';
	case Piece::WHITE_CROWN:
		return 'W';
	case Piece::BLACK_CROWN:
		return 'B';
	default:
		return ' ';
	}
}

//standard 8x8 board
void printboard(int data[ROWS][COLS])
{
	cout << "\t+---+---+---+---+---+---+---+---+" << endl;
	for (int i = 0; i < ROWS ; i++)
	{
		cout << (i + 1) << "\t|";
		for (int j = 0; j < COLS ; j++)
		{
			cout << " " << dataToSymbol(data[i][j]) << " |";
		}
		cout << endl<< "\t+---+---+---+---+---+---+---+---+" << endl;
	}
	cout << "\t  a   b   c   d   e   f   g   h" << endl;
}

//swap numbers on data board
void swap(int data[ROWS][COLS], char c1, char c2, int n1, int n2)
{
	cout << "Moving piece " << (char)(c1 + 'a') << n1 + 1 << " to " << (char)(c2 + 'a') << n2 + 1 << endl;
	int temp;
	temp = data[n1][c1];
	data[n1][c1] = data[n2][c2];
	data[n2][c2] = temp;
}

int playersTurn(int data[ROWS][COLS], string player, char c1, int n1, char c2, int n2)
{
	//check if input is within bound
	//if not return -1 and ask again
	int charToData1 = c1 - 'a'; //converting ascii with a=0
	int charToData2 = c2 - 'a';
	if (charToData1 < 0 || charToData1 > COLS - 1)
	{
		cout << "First character input out of bound" << endl;
		return Error;
	}
	if (charToData2 < 0 || charToData2 > COLS - 1)
	{
		cout << "Second character input out of bound" << endl;
		return Error;
	}
	if (n1 < 0 || n1 > ROWS - 1)
	{
		cout << "First number input out of bound" << endl;
		return Error;
	}
	if (n2 < 0 || n2 > ROWS - 1)
	{
		cout << "Second number input out of bound" << endl;
		return Error;
	}

	//check if the player is moving his piece
	if (player == "WHITE")
	{
		if (data[n1][charToData1] != Piece::WHITE
			&& data[n1][charToData1] != Piece::WHITE_CROWN)
		{
			cout << data[n1][charToData1] << endl;
			cout << "You have selected a non-white piece." << endl;
			return Error;
		}
	}
	else
	{ //player == BLACK
		if (data[n1][charToData1] != Piece::BLACK
			&& data[n1][charToData1] != Piece::BLACK_CROWN)
		{
			cout << "You have selected a non-black piece." << endl;
			return Error;
		}
	}

	//check if the player is moving into a valid empty space
	if (data[n2][charToData2] != Piece::EMPTY)
	{
		cout << "You must move to a empty space." << endl;
		return Error;
	}

	//check if player is moving the piece in the correct direction for uncrowned piece
	if (player == "WHITE")
	{
		//making sure if WHITE is moving upward
		if (n1 < n2)
		{
			cout << "Uncrowned white piece must move upward." << endl;
			return Error;
		}
	}
	else
	{ //player == BLACK
		//making sure if BLACK is moving downward
		if (n1 > n2)
		{
			cout << "Uncrowned black piece must move downward." << endl;
			return Error;
		}
	}

	//check if it is a regular move (up or down diagonally 1 space)
	if (n1 - n2 == -1 || n1 - n2 == 1)
	{
		if (charToData1 - charToData2 == -1 || charToData1 - charToData2 == 1)
		{
			swap(data, charToData1, charToData2, n1, n2);
			return 0;
		}
	}

	//check if it is a jump move (up or down diagonally 2 spaces)
	if (n1 - n2 == -2 || n1 - n2 == 2)
	{
		if (charToData1 - charToData2 == -2 || charToData1 - charToData2 == 2)
		{
			//finding the middle man between the jump
			int middleman_x, middleman_y;
			if (n1 < n2) middleman_x = n1 + 1; //moving downward
			else		 middleman_x = n1 - 1; //moving upward
			if (charToData1 < charToData2) middleman_y = charToData1 + 1; //moving right
			else						   middleman_y = charToData1 - 1; //moving left
			//checking the middle man is an enemy for WHITE player
			if ((player == "WHITE"&&data[middleman_x][middleman_y] != Piece::BLACK) &&
				(player == "WHITE"&&data[middleman_x][middleman_y] != Piece::BLACK_CROWN))
			{
				cout << "You can only jump over an enemy piece." << endl;
				return Error;
			}

			//checking the middle man is an enemy for BLACK player
			if ((player == "BLACK"&&data[middleman_x][middleman_y] != Piece::WHITE) &&
				(player == "BLACK"&&data[middleman_x][middleman_y] != Piece::WHITE_CROWN))
			{
				cout << "You can only jump over an enemy piece." << endl;
				return Error;
			}

			//then the move is valid
			//setting middle man to empty space
			data[middleman_x][middleman_y] = 1;
			swap(data, charToData1, charToData2, n1, n2);

			//if successful jump, player might move again for another jump

			return 0;			
		}
	}

	return 0;	 // if it's a valid move
	return Error;// if it's a invalid move
}

int checkForWin(int data[ROWS][COLS])
{
	//counting number of pieces both players have
	int numberOfWhitePieces = 0;
	int numberOfBlackPieces = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (data[i][j] == Piece::WHITE || data[i][j] == Piece::WHITE_CROWN)
			{
				numberOfWhitePieces++;
			}
			if (data[i][j] == Piece::BLACK || data[i][j] == Piece::BLACK_CROWN)
			{
				numberOfBlackPieces++;
			}
		}
	}

	//check if there are no more white piece
	if (numberOfWhitePieces == 0)
	{
		printboard(data);
		cout << "Player Black wins." << endl;
		return -1;
	}

	//check if there are no more black piece
	if (numberOfBlackPieces == 0)
	{
		printboard(data);
		cout << "Player White wins." << endl;
		return -1;
	}
	return 0;
}

int main()
{
	int data[ROWS][COLS] = {{ 0,3,0,3,0,3,0,3 },
							{ 3,0,3,0,3,0,3,0 },
							{ 0,1,0,3,0,3,0,3 }, 
							{ 1,0,3,0,1,0,1,0 }, 
							{ 0,1,0,2,0,1,0,1 },
							{ 2,0,1,0,2,0,2,0 }, 
							{ 0,2,0,2,0,2,0,2 }, 
							{ 2,0,2,0,2,0,2,0 } };
	bool play = true;
	while (play)
	{
		char letter1, letter2;
		int number1, number2;
		string player;

		//Player WHITE is user
		while (1)
		{
			printboard(data);
			player = "WHITE";
			cout << "Player White's Turn: Enter character then number for valid input (ie a6)" << endl;
			cin >> letter1 >> number1;
			cout << "to: ";
			cin >> letter2 >> number2;
			if (playersTurn(data, player, letter1, number1-1, letter2, number2-1) == 0)
				break;
			cout << "Invalid move, try again." << endl;
		}

		//check for win
		if (checkForWin(data) != 0)
		{
			play = false;
			break;
		}

		//Player Black
		while (1)
		{
			printboard(data);
			player = "BLACK";
			cout << "Player Black's Turn: Enter character then number for valid input (ie a6)" << endl;
			cin >> letter1 >> number1;
			cout << "to: ";
			cin >> letter2 >> number2;
			if (playersTurn(data, player, letter1, number1 - 1, letter2, number2 - 1) == 0)
				break;
			cout << "Invalid move, try again." << endl;
		}

		//Player BLACK is computer
		/*while (1)
		{
			//locate all the black pieces
			//locate all the empty space
			//randomly move a black piece to an empty space
			break;
		}*/

		//check for win
		if (checkForWin(data) != 0)
		{
			play = false;
			break;
		}

		//exit
		if (letter1 == 'z')
			play = false;
	}

	system("pause");
	return 0;
}