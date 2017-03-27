#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("filename.txt");

	//check for error
	if (inFile.fail())
	{
		cerr << "Error Openning File" << endl;
		exit(1);
	}

	string item;
	int count = 0;

	//Read a file until reached the end
	while (!inFile.eof())
	{
		inFile >> item;
		count++;
	}

	cout << count << " items found!" << endl;

	inFile.close();

	system("PAUSE");

	return 0;
}