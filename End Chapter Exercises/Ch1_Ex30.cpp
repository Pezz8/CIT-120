// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double tcredit;
	double ucredit;
	double acredit;

	cout << "Enter the costumer's maximum credit.";
	cin >> tcredit;
	cout << "Enter the amount of credit used by the costumer.";
	cin >> ucredit;
	acredit = tcredit - ucredit;
	cout << "Costumer's available credit: " << acredit;
	return 0;
}
