#include "stdafx.h"
#include <iostream>
using namespace std;

int a1[] = { 1, 2, 3, 4, 5, 6 };
int a2[] = { 3, 4, 5, 6, 1, 2 };
int match = 0;
int temp, size, check;

int main()
{
	size = sizeof(a1) / sizeof(a1[0]);
	cout << "checking size: " << size << endl;
	if (sizeof(a1) == sizeof(a2))
	{
		cout << "same size" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << endl << "loop " << i << "..." << endl;
			check = 0;
			for (int k = 0; k < size; k++)
			{
				cout << a1[k] << " = " << a2[k] << endl;
				if (a1[k] == a2[k])
					check++;
			}
			if (check == size)
				match++;
			else
			{
				cout << "no match" << endl << "shitfing..." << endl;
				temp = a2[0];
				for (int j = 0; j < size - 1; j++)
					a2[j] = a2[j + 1];
				a2[size - 1] = temp;
			}
		}
	}
	else
		cout << "not the same size" << endl;
		

	if (match != 0)
		cout << endl << "match" << endl;
	else
		cout << endl << "no match" << endl;

	return 0;
}

