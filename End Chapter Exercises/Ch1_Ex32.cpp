+// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double startingBalance;
	double depositAmount;
	double withdrawalsAmount;
	double interestRate;
	double interestAmount;
	double currentBalance;
	double totalBalance;

	cout << "Insert Starting Balance: " << "$";
	cin >> startingBalance;
	cout << "Insert Total Deposits: " << "$";
	cin >> depositAmount;
	cout << "Insert Total Withrawals: " << "$";
	cin >> withdrawalsAmount;
	cout << "Insert Interest Rate: ";
	cin >> interestRate;
	currentBalance = startingBalance + depositAmount - withdrawalsAmount;
	interestAmount = currentBalance*(interestRate / 100);
	totalBalance = currentBalance + interestAmount;
	cout << "Your Total Balance is: " << "$" << totalBalance << endl;

    return 0;
}

