
// FileInputValidationCristianGuarino.cpp : Defines the entry point for the console application.
// This pro

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	system("title File Input Validation (Cristian Guarino)");
	system("color 02");

	cout
		<< "\n\t           This program asks the user for the name of a file that          "
		<< "\n\t                          contains two numbers,                            "
		<< "\n\t                  and prints on the monitor their average                  "
		<< "\n\t                           by Cristian Guarino                       \n\n\n";


	ifstream inputFile;

	string
		fileName;

	int firstNumber,
		secondNumber;

	cout << "\nWhat file contains your data? ";
	cin >> fileName;

	inputFile.open(fileName);

	while (inputFile.fail())
	{
		system("color 17");
		cout << "\aFailed to open file: \"" << fileName << "\". Please provide a different file name: ";
		cin >> fileName;
		inputFile.open(fileName);
	}

	system("color 02");


	inputFile >> firstNumber;
	inputFile >> secondNumber;

	inputFile.close();
	
	cout << "The avarage of " << firstNumber << " and " << secondNumber << " is: " << static_cast<double>(firstNumber+secondNumber)/2 << endl << endl;

	system("pause");
	return 0;
}




