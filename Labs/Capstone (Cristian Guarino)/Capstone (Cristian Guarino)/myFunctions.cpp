#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "myFunctions.h"
using namespace std;

bool hasSign(string number) {
	if (number[0] == '+' || number[0] == '-')
		return true;
	return false;
}

bool isValidInteger(string number) {
	if (hasSign(number) && number[1] == '\0') return false;
	for (int i = (hasSign(number) ? 1 : 0); number[i] != '\0'; i++)
		if (number[i] < '0' || number[i] >'9')
			return false;
	return true;
}

string getValidLargeInteger() {
	string largeInteger;
	getline(cin >> ws, largeInteger);

	while (!isValidInteger(largeInteger))
	{
		cout << "\tPlease enter a legal number.\n" << "\nWhat is your number: ";
		getline(cin >> ws, largeInteger);
	}
	return largeInteger;
}

int sumOfDigits(string number) {
	int sum = 0;
	for (int i = (hasSign(number) ? 1 : 0); i < stringLenght(number); i++) {
		sum += digitToInt(number[i]);
	}
	return sum;
}

int stringLenght(string number) {
	int i = 0;
	while (number[i] != '\0')
		i++;
	return i;
}

int digitToInt(char ch) {
	return ch - '0';
}

int lastDigitValue(string number) {
	return digitToInt(number[stringLenght(number) - 1]);
}

void printResults(string number, int flip, int flop, ostream &output) {

	output << "\n\t" << (sumOfDigits(number) % flip == 0 ? "Flip " : "") << (lastDigitValue(number) % flop == 0 ? "Flop " : "");

	output << "\n\n\tDebugging couts in printResults function: \n";
	output
		<< "\tThe int value of the last digit in \"number\"\n"
		<< "\t\t(here call the corresponding function) is " << lastDigitValue(number) << ".\n"
		<< "\tThe sum of digits in \"number\" \n"
		<< "\t\t(here call the corresponding function) is " << sumOfDigits(number) << ".\n"
		<< "\n\t*****************************************\n\n";
}

void printBanner(ostream &output) {
	output
		<< "\n\t                           Flip Flop                             "
		<< "\n\t   for VERY Large Numbers that would overflow any type of int    "
		<< "\n\t            accepts signs at the beginning of the num            "
		<< "\n\t                        Sample Solution                          "
		<< "\n\t                        Using Functions                          "
		<< "\n\t                      by Cristian Guarino                  \n\n\n";
}

void printInstructions(int flip, int flop, ostream &output) {
	output
		<< "\nThis program prints :" << endl
		<< "\t\"Flop\" if a number is divisible by " << flop << endl
		<< "\t\"Flip\" if a number is divisible by " << flip << " and" << endl
		<< "\t\"Flip Flop\" if divisible by BOTH " << flip << " and " << flop << endl
		<< "\tNothing if divisibe by NEITHER" << endl << endl;
}

void connectOutStream(ofstream &output, string fileName) {
	output.open(fileName);
	while (output.fail())
	{
		cout << "\aFailed to open file: \"" << fileName << "\". Please provide a different file name: ";
		getline(cin >> ws, fileName);
		output.open(fileName);
	}
}