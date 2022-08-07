// PrimeNumbersFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double number;

bool primeNumber(int);
bool positiveInteger(double);

int main()
{
	while (true)
	{
		cout << "Type a number and I will tell you if is prime or not: ";
		cin >> number;
		cin.ignore(200, '\n');

		while (positiveInteger(number) == false)
		{
			cout << "Please enter a Positive Integer: ";
			cin >> number;
			cin.ignore(200, '\n');
		}

		cout << "The number " << number << " is " << (primeNumber(number) ? "" : "not ") << "Prime" << endl;
		system("pause");
	}
    return 0;
}

bool primeNumber(int number)
{
	bool status;
	if ((number % 2 == 0) || (number % 3 == 0) || (number % 4 == 0) || (number % 5 == 0) || (number % 6 == 0) || (number % 7 == 0)||(number % 8 == 0)||(number % 9 == 0))
		status = false;

	else
		if ((number / 1 == number) && (number / number == 1))
				status = true;

	return status;
}

bool positiveInteger(double number)
{
	bool status;
	if ((number < 0)||(number != static_cast<int>(number)))
		status = false;
	else
		status = true;
	return status;
}

