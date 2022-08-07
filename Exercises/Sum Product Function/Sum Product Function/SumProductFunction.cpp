// SumProductFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

double number1, number2;

double sum(double, double);
double product(double, double);

int main()
{
	while (true)
	{
		cout << "What is the first number? ";
		cin >> number1;
		cout << "What is the second number? ";
		cin >> number2;
		cout
			<< "The sumProduct of " << number1 << " and " << number2 << " is "
			<< ((number1 < 0 && number2 < 0) || (number1 > 0 && number2 > 0) ? sum(number1, number2) : product(number1, number2))
			<< endl;
		system("pause");
	}
    return 0;
}

double sum(double number1, double number2)
{
	return number1 + number2;
}

double product(double number1, double number2)
{
	return number1*number2;
}

