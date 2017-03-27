#include <iostream>
#include "constant.h"

using namespace std;

double initalHeight()
{
	cout << "Enter the initial height of the tower in meters: " << endl;
	double initialHeight;
	cin >> initialHeight;
	return initialHeight;
}

double distanceFallen(int sec)
{
	return myConstants::gravity*sec*sec / 2;
}

double currentHeight(double inital_height, int sec)
{
	return inital_height - distanceFallen(sec);
}

void printCurrentHeight(double current_height, int sec)
{
	if (current_height > 0)
		cout << "At " << sec << " seconds, the ball is at height: " << current_height << " meters" << endl;
	else
		cout << "At " << sec << " seconds, the ball is on the ground." << endl;
}

int main()
{
	double initialHeight = initalHeight();

	int seconds = 0;
	double height;

	do
	{
		height = currentHeight(initialHeight, seconds);
		printCurrentHeight(height, seconds);
		seconds++;
	} while (height > 0);

	system("pause");
	return 0;
}