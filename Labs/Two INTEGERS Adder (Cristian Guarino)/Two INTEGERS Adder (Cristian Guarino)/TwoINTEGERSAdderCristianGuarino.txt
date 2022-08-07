// This program will add two integers and display the result
// Two INTEGERS Adde
// Programmer : Cristian Guarino
// Last Modified : September 25, 2017

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	system("title Two INTEGERS Adder (Cristian Guarino)");
	system("color 02");

	int num1;
	int num2;

	cout << "\n\t            Two INTEGERS Adder         \n";
	cout << "\t           by Cristian Guarino       \n\n\n";
	cout << "Please insert an INTEGER: ";
	cin >> num1;
	cin.ignore(20, '\n');
	cout << "Please insert an other INTEGER: ";
	cin >> num2;
	cin.ignore(20, '\n');
	cout << "\nThe sum of " << num1 << " and " << num2 << " is: " << num1 + num2 << endl;
	cout << "\t\"" << num1 << " + " << num2 << "\"" <<  " = " << num1 + num2 << endl << endl;
	system("pause");
	return 0;
}

