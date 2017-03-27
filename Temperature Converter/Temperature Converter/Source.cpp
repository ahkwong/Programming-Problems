#include <iostream>

using namespace std;

#define LOWER_LIMIT 0
#define UPPER_LIMIT 50000

float lower_limit = -1;
float upper_limit = -1;
float step = 0;

float CtoF(float);

int main()
{
	while (lower_limit < (int)LOWER_LIMIT)
	{
		cout << "Please give a lower limit (limit >= 0): ";
		cin >> lower_limit;
	}
	while ((upper_limit <= lower_limit) || (upper_limit > (int)UPPER_LIMIT))
	{
		cout << "Please give a upper limit (" << lower_limit << " > limit <= 50000): ";
		cin >> upper_limit;
	}
	while ((step <= 0) || (step > upper_limit))
	{
		cout << "Please give a step (0 < step <= " << upper_limit << "): ";
		cin >> step;
	}
	cout << endl << "Celsius\t\tFahrenheit" << endl;
	float temp = lower_limit;
	while (temp <= upper_limit)
	{
		cout << temp << "\t\t" << CtoF(temp) << endl;
		temp = temp + step;
	}
	system("PAUSE");
	return 0;
}

float CtoF(float x)
{
	return x * 9 / 5 + 32;
}