// This program will rearrange the data from the file and rearrange from the smallest to the largest
// Rearrange Function Lab by (Cristian Guarino)
// Programmer: Cristian Guarino
// Last Modified : 11/13/2017


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void printBanner(); // printBanner Prototype
void mySwap(int &xValue, int &yValue); // mySwap Function Prototype
void rearrange(int &xValue, int &yValue, int &zValue); // rearrange Fuction Prototype
void connectStream(ifstream &inputFile, string fileName);


int main()
{
	system("title Rearrange Function Lab (Cristian Guarino)"); // Program Title
	system("color 02"); // Program background color and font color

	int xValue, yValue, zValue; // Variables that will store the read from the file

	string fileName = "Data Set.txt"; // Variable that will store the name of the file that holds the values
	ifstream inputFile;

	// BANNER

	printBanner(); // Calling the printBanner function to print the banner
	connectStream(inputFile, fileName); // Calling the connectStream function to retrieve the data from the file

	// INTERACTIVE VERSION	
	/*
	cout << "Please enter the x value: ";
	cin >> xValue;
	cout << "Please enter the y value: ";
	cin >> yValue;
	cout << "Please enter the z value: ";
	cin >> zValue;

	cout
	<< "\nThis is the order before the values get rearranged "
	<< endl <<  xValue << " " << yValue << " " << zValue;
	rearrange(xValue, yValue, zValue);
	cout
	<< "\nThis is the order after the values get rearranged "
	<< endl <<  xValue << " " << yValue << " " << zValue << endl;
	*/

	// HARDWIRED VERSION
	/*

	xValue = 1; yValue = 2; zValue = 3;

	cout
		<< "\nThis is the order before the values get rearranged "
		<< endl <<  xValue << " " << yValue << " " << zValue;
	rearrange(xValue, yValue, zValue);
	cout
		<< "\nThis is the order after the values get rearranged "
		<< endl <<  xValue << " " << yValue << " " << zValue << endl;

	xValue = 1; yValue = 3; zValue = 2;

	cout
		<< "\nThis is the order before the values get rearranged "
		<< endl << xValue << " " << yValue << " " << zValue;
	rearrange(xValue, yValue, zValue);
	cout
		<< "\nThis is the order after the values get rearranged "
		<< endl << xValue << " " << yValue << " " << zValue << endl;

	xValue = 2; yValue = 1; zValue = 3;

	cout
		<< "\nThis is the order before the values get rearranged "
		<< endl << xValue << " " << yValue << " " << zValue;
	rearrange(xValue, yValue, zValue);
	cout
		<< "\nThis is the order after the values get rearranged "
		<< endl << xValue << " " << yValue << " " << zValue << endl;

	xValue = 2; yValue = 3; zValue = 1;

	cout
		<< "\nThis is the order before the values get rearranged "
		<< endl << xValue << " " << yValue << " " << zValue;
	rearrange(xValue, yValue, zValue);
	cout
		<< "\nThis is the order after the values get rearranged "
		<< endl << xValue << " " << yValue << " " << zValue << endl;

	xValue = 3; yValue = 1; zValue = 2;

	cout
		<< "\nThis is the order before the values get rearranged "
		<< endl << xValue << " " << yValue << " " << zValue;
	rearrange(xValue, yValue, zValue);
	cout
		<< "\nThis is the order after the values get rearranged "
		<< endl << xValue << " " << yValue << " " << zValue << endl;

	xValue = 3; yValue = 2; zValue = 1;

	*/

	// HARDWIRED VERSION WITH LOOP
	/*
	cout
		<< left << "        " << setw(8) << "x" << setw(8) << "y" << setw(8) << "z" << endl
		<< "        " << setfill('=') << setw(17) << "=" << setfill(' ');

	for (int i = 1; i < 6; i++)
	{
		switch (i)
		{
		case 1: xValue = 1; yValue = 2; zValue = 3;
			break;
		case 2: xValue = 1; yValue = 3; zValue = 2;
			break;
		case 3: xValue = 2; yValue = 1; zValue = 3;
			break;
		case 4: xValue = 2; yValue = 3; zValue = 1;
			break;
		case 5: xValue = 3; yValue = 1; zValue = 2;
			break;
		case 6: xValue = 3; yValue = 2; zValue = 1;
			break;
		}
		cout
			<< "\nStart:  " << left << setw(8) << xValue << setw(8) << yValue << setw(8) << zValue << endl;
		rearrange(xValue, yValue, zValue);
		cout
			<< "End:    " << setw(8) << xValue << setw(8) << yValue << setw(8) << zValue << endl;
	}
	*/

	// FILE INPUT VERSION

	system("color 02"); // Restoring original color
	while (inputFile >> xValue >> yValue >> zValue) // The loop will keep reading values untill there are none to read
	{
		cout // Display the values before the rearrange function
			<< "\nBefore the call: x = " << xValue << " y = " << yValue << " z = " << zValue << endl
			<< xValue << yValue << zValue;

		rearrange(xValue, yValue, zValue);

		cout // Display the values after the rearrange fuction
			<< "\nAfter the call: x = " << xValue << " y = " << yValue << " z = " << zValue << endl
			<< xValue << yValue << zValue << endl;
	}
	inputFile.close(); // Close File

	cout << endl;

	system("pause"); // Pause before the the hardwired loop

	// HARDWIRED VERSION WITH LOOP

	cout
		<< "\n\n       HARDWIRED testing (using a for loop and a table format)\n\n";

	cout
		<< left << "\t" << setw(8) << "x" << setw(8) << "y" << setw(8) << "z" << endl
		<< "        " << setfill('=') << setw(17) << "=" << setfill(' ');

	for (int i = 1; i < 6; i++)
	{
		switch (i)
		{
		case 1: xValue = 1; yValue = 2; zValue = 3;
			break;
		case 2: xValue = 1; yValue = 3; zValue = 2;
			break;
		case 3: xValue = 2; yValue = 1; zValue = 3;
			break;
		case 4: xValue = 2; yValue = 3; zValue = 1;
			break;
		case 5: xValue = 3; yValue = 1; zValue = 2;
			break;
		case 6: xValue = 3; yValue = 2; zValue = 1;
			break;
		}
		cout
			<< "\nStart:  " << left << setw(8) << xValue << setw(8) << yValue << setw(8) << zValue << endl;
		rearrange(xValue, yValue, zValue);
		cout
			<< "End:    " << setw(8) << xValue << setw(8) << yValue << setw(8) << zValue << endl;
	}

	cout << endl;
	system("pause");
}

void mySwap(int &xValue, int &yValue)
{
	int swapX = yValue;
	yValue = xValue;
	xValue = swapX;
}

void rearrange(int &xValue, int &yValue, int &zValue)
{
	if (xValue > yValue) mySwap(xValue, yValue);
	if (xValue > zValue) mySwap(xValue, zValue);
	if (yValue > zValue) mySwap(yValue, zValue);
}

void printBanner()
{
	cout
		<< "\n\t\t    Lab on \"Driver testing Rearrange function.\"            "
		<< "\n\t\t   Rearrange ANY number of sets of three numbers             "
		<< "\n\t\t      from a given input file \"Data Set.txt\"               "
		<< "\n\t\t                by Cristian Guarino.                   \n\n\n";
}

void connectStream(ifstream &inputFile, string fileName)
{
	cout
		<< "\nTest test data set MUST be in a file called \"Data Set.txt\"\n";
	inputFile.open(fileName); // Opening "Data Set.txt"
	while (inputFile.fail()) // In case that the file fails to open start this loop
	{
		system("color 17"); // Change color
		cout << "\aFailed to open file: \"" << fileName << "\". Please provide a different file name: "; // ERROR MESSAGE
		getline(cin >> ws, fileName); // Enter a valid file name
		inputFile.open(fileName);
	}
}