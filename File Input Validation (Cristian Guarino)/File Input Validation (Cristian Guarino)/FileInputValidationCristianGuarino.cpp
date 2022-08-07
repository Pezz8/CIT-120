
// FileInputValidationCristianGuarino.cpp : Defines the entry point for the console application.
// This program reads two numbers from a file adds them and gives the avarage to the user
// File Input Validation (Cristian Guarino)
// Programmer: Cristian Guarino
// Last Modified: October 25, 2017


#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int main()
{
	system("title File Input Validation (Cristian Guarino)"); // Title
	system("color 02"); // Color Black background and Green font

	// Banner

	cout
		<< "\n\t           This program asks the user for the name of a file that          "
		<< "\n\t                          contains two numbers,                            "
		<< "\n\t                  and prints on the monitor their average                  "
		<< "\n\t                           by Cristian Guarino                       \n\n\n";

	ifstream inputFile; 
	string fileName; // This string will store the value assigned by the user
	int firstNumber, // This variable will store the first number read from the file
		secondNumber; // This variable will store the second number read from the file

	cout << "\nWhat file contains your data? "; // Prompt to user
	getline(cin >> ws, fileName); // User input the name of the file selected

	inputFile.open(fileName); // Opening file


	// Validating our input with an if statement
	/*
	if (inputFile.fail())
	{
		system("color 17");
		cout << "\aFailed to open file: \"" << fileName << "\". Thanks for using our program! \nGoodbye!\n";
		system("pause");
		return 0;
	}
	*/

	while (inputFile.fail()) // While the program is failing to open the file this error message will show
	{
		system("color 17"); // The program will change color and beep
		cout << "\aFailed to open file: \"" << fileName << "\". Please provide a different file name: ";
		getline(cin >> ws, fileName);// The user will provide a different file name untill it will succeed to open
		inputFile.open(fileName);
	}
	

	system("color 02"); //Restoring original color

	inputFile >> firstNumber >> secondNumber; // Reading first and second number from file

	inputFile.close(); // Closing program
	
	cout // Display the numbers read and the avarege of the two numbers read
		<< "The avarage of " << firstNumber << " and " << secondNumber << " is: " 
		<< static_cast<double>(firstNumber+secondNumber)/2 << endl << endl; // The result of the expression will be a double

	system("pause"); // Pause before closing the program
	return 0; // Program is closed
}




