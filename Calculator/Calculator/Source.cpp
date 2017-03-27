#include <iostream>

using namespace std;

int multiply(int, int);
int divide(int, int);
int add(int, int);
int sub(int, int);
char op = 'c';
int x, y;

int main()
{
	while (op != 'e')
	{
		cout << "+,-,*,/,e?\n";
		cin >> op;
		switch (op)
		{
		case '+':
			cin >> x;
			cin >> y;
			cout << x << '+' << y << '=' << add(x, y) << endl;
			break;
		case '-':
			cin >> x;
			cin >> y;
			cout << x << '-' << y << '=' << sub(x, y) << endl;
			break;
		case '*':
			cin >> x;
			cin >> y;
			cout << x << '*' << y << '=' << multiply(x, y) << endl;
			break;
		case '/':
			cin >> x;
			cin >> y;
			cout << x << '/' << y << '=' << divide(x, y) << endl;
			break;
		case 'e':
			op = 'e';
			break;
		default:
			cout << "Wrong command." << endl;
		}
	}
	system("PAUSE");
	return 0;
}

int multiply(int x, int y)
{
	return x * y;
}
int divide(int x, int y)
{
	return x / y;
}
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}