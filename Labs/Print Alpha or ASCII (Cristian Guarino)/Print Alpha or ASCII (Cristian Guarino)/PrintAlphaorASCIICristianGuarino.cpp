
#include "stdafx.h"
#include <iostream> // Input Output Preprocessor Directive
#include <iomanip> // Preprocessor that allows us to use setw.... 
using namespace std;


int main()
{

		system("title Print Alpha or ASCII (Cristian Guarino");
		system("color 02"); // Black Background and Green Font

		const int

			ASCII_FIRST_CHARACTER = 0, // Constant for first value of ASCII table
			ASCII_LAST_CHARACTER = 255, // Constant for last value of ASCII table

			MAX_NUM_CHARACTERS_PER_LINE = 4, // Constant for maximum number of characters per line allowed
			MIN_NUM_CHARACTERS_PER_LINE = 1; // Constant for minimum number of characters per line allowed

		char
			
			character; // Char Variable that will print characters

		int
			minLimit = 0, // Variable that will store the beginning of our range
			maxLimit = 0, // Variable that will store the end of our range
			counter, // This variable will number the characters in our ASCII table
			numberOfCharactersPerLine, // This variable will store the number of characters per line selcted by the user
			choice; // This variable will store the choice made by the user

		// BANNER

		cout
			<< "\n\t             Print the WHOLE ASCII table or the Alphabet                "
			<< "\n\t                       n characters per line                            "
			<< "\n\t                        By Cristian Guarino                       \n\n\n";


		while(true) // INFINITE LOOP
		{
		cout // LIST OF OUR CHOICES
			<< "\n\nPlease enter your choice:"
			<< "\n\t1]  Print the whole ASCII table"
			<< "\n\t2]  Print the capital letters"
			<< "\n\t3]  Print the lower letters"
			<< "\n\t4]  Print the digits"
			<< "\n\t5]  Exit the program\n";

		cout << "\nChoice: "; // We will ask the user to select from one of the choices above
		cin >> choice; 
		cin.ignore(200, '\n'); // Only the first value will be consiedered all remaining will be ingnored

		switch (choice) // This Switch case will assign our variables values based on the range selected
		{
		case 1: // This case will print the whole ASCII table
			maxLimit = ASCII_LAST_CHARACTER; 
			minLimit = ASCII_FIRST_CHARACTER;
			break;
		case 2: // This case will print only the Capital Letters
			maxLimit = 'Z';
			minLimit = 'A';
			break;
		case 3: // This case will print only the Lowercase Letters
			maxLimit = 'z';
			minLimit = 'a';
			break;
		case 4: // This case will print only the digits
			maxLimit = '9';
			minLimit = '0';
			break;
		case 5: // This case will end the program after the user hits enter
			cout << "\nThank you for using printing with us. Please hit ENTER to end the program ";
			cin.ignore(); // Everything that the user will type will be ignored
			cin.get();
			return 0; // The program will end after hitting ENTER
			break;
		default: cout << "\n\a  ***   Invalid choice"; // If the choice is neither of the cases listed it will result
			continue;                 //as error and the loop will start from the beginning
		}

		cout << "\nHow many chararcters do you want to print per line? ";
		cin >> numberOfCharactersPerLine; // User selects the number of characters he wants per line
		cin.ignore(200, '\n');

		while (numberOfCharactersPerLine < MIN_NUM_CHARACTERS_PER_LINE  || numberOfCharactersPerLine > MAX_NUM_CHARACTERS_PER_LINE)
		{ // While the number is outside of the range [1,4] this loop will show the error message and will ask for 
			cout  // a new value
				<< "\tYour number must be less than or equal to 4."
				<< "\n\tTry again: ";
			cin >> numberOfCharactersPerLine; // New value
			}

		for (counter = minLimit; (counter <= maxLimit); counter++) 
		{
			// In this loop we assigne the counter the starting value of the beginning of our range and we set our condition
			// to be less tha equal than the end of our range. The counter will keep adding one for every iteration
			// untill it reaches the limit assigned

			character = counter; // This char variable will assume the corrispondant value in the counter

			cout << setw(4) << right << counter << "   "; // This line will print out our first column with our counter
			// and decimal value corrispondant on the ASCII table

			switch (character) // This switch will help in printing all our simbols
			{ // all the escape sequences will be printend the correct way instead of being executed
			case '\t': cout << setw(4) << "\\t";
				break;
			case '\a': cout << setw(4) << "\\a";
				break;
			case '\b': cout << setw(4) << "\\b";
				break;
			case '\r': cout << setw(4) << "\\r";
				break;
			case '\n': cout << setw(4) << "\\n";
				break;
			case '\v': cout << setw(4) << "\\v";
				break;
			case 0: cout << setw(4) << "NULL";
				break;
			default: cout << setw(4) << character;
			}

			if (numberOfCharactersPerLine == 1) // If the user selects to have only one column we will only have a
				// a newline
					cout << "\n";
				else // If we have multiples columns
				{		
					if ((((counter-minLimit)+1)%numberOfCharactersPerLine) == 0)
						// We will have a new line each time the counter - the value of the beginning of our range 
						// plus 1 divided by the number of characters will be divisible evenly
						cout << "\n";
					else // Or we will have these symbols to separate the 2 column of values printed
						cout << "   ||  ";
				}
		} // END OF PRINTOUT LOOP
	} // END OF INFINITE LOOP
	system("pause");
	return 0;
}