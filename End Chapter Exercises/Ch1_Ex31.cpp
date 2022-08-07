// Ch1Ex31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double totalRetailSale;
	double retailPrice;
	double taxAmount;
	double taxRate;

	cout << "Insert Item's Price: " << "$";
	cin >> retailPrice;
	cout << "Insert Tax Rate: " << "$";
	cin >> taxRate;
	taxAmount = retailPrice*(taxRate / 100);
	totalRetailSale = retailPrice + taxAmount;
	cout << "Total Price: " << "$" << setw(8) << totalRetailSale << endl;
	return 0;
}
