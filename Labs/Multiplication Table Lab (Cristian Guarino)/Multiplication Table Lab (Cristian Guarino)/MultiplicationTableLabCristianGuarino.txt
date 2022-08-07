// MultiplicationTableLabCristianGuarino.cpp : Defines the entry point for the console application.
// This lab will print on the monitor the multiplication table up to the limit selected by the user
// Multiplication Table Lab (Cristian Guarino)
// Programmer: Cristian Guarino
// Last Modified: October, 20 2017

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	system("color 02");
	system("title Print The Multiplication Table (Cristian Guarino)");

	cout
		<< "\n\t\t        Print the Multiplication Table           "
		<< "\n\t\t          up to a user defined limit             "
		<< "\n\t\t             By Cristian Guarino           \n\n\n";

	const int

		MIN_LIMIT = 1, // Minimum Limit allowed by the user
		MAX_LIMIT = 12; // Maximum limit allowe by the user

	int
		numbersH, // Counter for Horizontal Numbers
		numbersV, // Counter for Vertical Numbers
		limit, // Limit for multiplication table assigned by the user
		multiplication; // Variable that stores the result of the multiplication between the Horizonta and the Vertical Numbers

	char
		symbols = 177; // Char Variable that we will use to print our border

	while (true) // Beginning of Infinite Loop
	{

		cout << "\nUp to what number do you want to print the multiplication table? "; // Prompt to user to select the limit wanted for the multiplication table
		cin >> limit; // Assigning value to the variable 
		cin.ignore(200, '\n');

		while (limit < MIN_LIMIT || limit > MAX_LIMIT) // The variable limit needs to be between the Maximum and the Minimun limit allowed
		{

			cout 
				<< "\tYour number must be " << (limit < MIN_LIMIT ? "greater than " : "less than ") << "or equal to " << (limit < MIN_LIMIT ? MIN_LIMIT : MAX_LIMIT)
				<< "\n\tTry again: "; // Prompt to the user to select an other limit
			cin >> limit;
			cin.ignore(200, '\n');
		}

		for (numbersV = -1; numbersV <= limit; numbersV++)
			// This loop will print the vertical numbers
			// The initial value of will be -1 so that we will have the top extra lines of values from 1-12 that the switch will convert to positive numbers
			// Also having an initial value of -1 will give us a vertical and horizontal line of zeros that we will convert to symbols to draw our border

		{
			switch (numbersV) // This switch will change our unwanted numbers from the table
			{
			case -1:cout << setw(3) << "     "; // If the number in column is equal to -1 it will print 5 a blank spaces
				break;
			case 0: cout << setw(3) << "    " << symbols; // If the number in the column is equal to 0 it will switch it to 4 blank spaces and the symbol we will use as a vertical border
				break;
			default: cout << setw(3) << numbersV << " " << symbols; // If the number in the column is any other number it will print the number a blank space and the symbol we will use as a vertical border
			}

			for (numbersH = 1; numbersH <= limit; numbersH++) // This loop will print the result of the moltiplication (the rows)
			{
				multiplication = numbersH*numbersV; // The multiplication is the result from multiplying the Horizontal Numbers and the Vertical Numbers
				if (multiplication < 0) // If the result of the multiplication is a negative number it will conver it to positive numbers
					cout << setw(6) << multiplication*(-1);
				else if (multiplication == 0)
				{// If the result of the multiplication is 0 it will print 6 symbols that will fill the sull lenght of our line and be our horizontal border
					cout << setfill(symbols) << setw(6) << symbols;
					cout << setfill(' ');
				}
				else
					cout << setw(6) << multiplication; // If the result is neither of these condition it will print
		
			}
			cout << endl; // At the end of each iteration we will have a new line that will allow us to print the next iteration in the next line
		}

		cout << "\nDon't you love math! So lets do it again!\n\n"; // At the end of all the iteration our multiplication table will be printed on the monitor and we will display this message
		system("pause");

	} // End of Infinite loop
	return 0;
}

