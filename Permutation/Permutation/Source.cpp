#include <iostream>
#include <string>

using namespace std;

string swtch(string word, int x, int y)
{
	string newstring = word;
	newstring[x] = newstring[y];
	newstring[y] = word[x]; //avoids temp variable
	return newstring;
}

void permute(string word, int place)
{
	if (place == word.length() - 1)
	{
		cout << word << endl;
	}
	for (int nextchar = place; nextchar < word.length(); nextchar++)
	{
		permute(swtch(word, place, nextchar), place + 1);
	}
}

int main()
{
	string word;
	cout << "Enter a word: " << endl;
	cin >> word;
	permute(word, 0);
	system("PAUSE");
	return 0;
}