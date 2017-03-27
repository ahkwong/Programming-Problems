#include <iostream>
#include "io.h"

using namespace std;

int main()
{
	int input1 (readNumber());
	int input2 = readNumber();

	int result (input1 + input2);

	writeAnswer(result);

	system("pause");
	return 0;
}