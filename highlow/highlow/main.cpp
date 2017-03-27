#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int RandomNumber()
{
	srand(static_cast<unsigned int>(time(0)));
	return rand()%100;
}

int main()
{
	bool play = true;

	do
	{
		cout << "Let's play a game. I'm thinking a number. " <<
			"You have 7 tries to guess what it is." << endl;
		int randomNumber = RandomNumber();
		int guessCount = 7;
		while (guessCount > 0)
		{
			cout << "Guess #" << guessCount << ": ";
			int userNumber = -1;
			cin >> userNumber;
			if (userNumber < randomNumber)
			{
				cout << "Your guess is too low." << endl;
				guessCount--;
			}
			if (userNumber > randomNumber)
			{
				cout << "Your guess is too high." << endl;
				guessCount--;
			}
			if (userNumber == randomNumber)
			{
				cout << "Correct! You win!" << endl;
				guessCount = -1;
			}
		}
		if (guessCount == 0)
		{
			cout << "Sorry, you lose. The correct number was " << 
				randomNumber << "." << endl;
		}

		char op;
		do
		{
			cout << "Would you like to play again (y/n)? ";
			cin >> op;
		} while (op != 'y' && op != 'n');

		if (op == 'n')
		{
			play = false;
		}

	} while (play);

	cout << "Thank you for playing." << endl;

	system("pause");
	return 0;
}