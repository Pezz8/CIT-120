// DayOfTheWeekLabCristianGuarino.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	char dayInitial; // Variable that store the value inputted by the user of the day selected

	string dayName; // Variable the stores the name that will be printed on the monitor after the user's choice

	system("title Day of the Week with Validation (Cristian Guarino");
	system("color 02");
	

	cout  // BANNER 
		<< "\n              Find the day of the week usind switch case             " 
		<< "\n                 validate input FIRST using while loop               "
		<< "\n                         by Cristian Guarino                       \n";

	cout  // INSTRUCTIONS
		<< "\n ****************************************************************************"
		<< "\n *  You should have ONLY ONE input validation loop to check if the day code *"
		<< "\n *  Make sure you that loop test ALL possible UNACCEPTABLE situaions        *"
		<< "\n *  If unacceptable input is foud                                           *"
		<< "\n *            change the console color to b1 and                            *"
		<< "\n *            beep to attract the user's attention                          *"
		<< "\n *  Consider using the conditional operator to customize your feedback      *"
		<< "\n *            (i.e. digit vs special char) INSIDE that loop.                *"
		<< "\n *  AFTER you validate that the input is valid                              *"
		<< "\n *            restore the console color and                                 *"
		<< "\n *            check if is NOT capital and convert if needed                 *"
		<< "\n *  You are NOT allowed to use                                              *"
		<< "\n *            the ASCII values of ANY character                             *"
		<< "\n *            any library functions, like the                               *"
		<< "\n *            isdigit, isupper, toupper, isalnum, isalpha, etc.             *"
		<< "\n ****************************************************************************";

	cout  // LIST OF CODES REPPRESENTING DAYS OF THE WEEK
		<< endl << endl
		<< "\n  Day codes are:       "
		<< "\n  \'M\' for Monday     "
		<< "\n  \'T\' for Tuesday    " 
		<< "\n  \'W\' for Wednesday  "
		<< "\n  \'H\' for Thursday   "
		<< "\n  \'F\' for Friday     "
		<< "\n  \'S\' for Weekend  \n";

	while (true) // INFINITE LOOP
	{

		cout << "\n\nPlease enter the code of the day of the week you want: "; // Asking the user to select code from the choices listed above

		cin >> dayInitial; // Assigning a value to the variable that will store the choice
		cin.ignore(200, '\n'); // This will ignore everything else after the first character

		while (!(dayInitial >= 'a' && dayInitial <= 'z') && !(dayInitial >= 'A' && dayInitial <= 'Z')) // Loop that will start if the value assigned is not a LETTER
		{
			system("color b1"); // Change the color
			
			if (dayInitial >= '0' && dayInitial <= '9') // Condition for Error Message if the choice is any DIGITS
				cout << "  \aYou can NOT have DIGITS for days in this program."; // Error Message
			else // Condition for Error Message if the choice is NEITHER a LETTER or a DIGIT
				cout
				<< "\a  You can NOT have SPECIAL CHARACTERS for days code in this program."; // Error Message

			cout << "\n  Please give a letter code: "; // Assign a different value to exit the loop
			cin >> dayInitial;
			cin.ignore(200, '\n');
		}

		system("color 02"); // Restore initial color after loop exit

		if (dayInitial >= 'a' && dayInitial <= 'z') // Condition for letters that need to be capitalized
		{
			dayInitial -= 'a' - 'A'; // Subtracting the the value, equal to the differance of a Lowercase letter and the equivalent Capital, in order to change it to a Capital Letter

			cout
				<< "\n  Remember that proper noun starts with capital." // Message to remember to use capital letters
				<< "\n  You should have typed \'" << dayInitial << "\'\n";
		}

		switch (dayInitial)
		{
		case 'M': dayName = "Monday"; // If the choice is M or m the day printed on the monitor will be Monday
			break;
		case 'T': dayName = "Tuesday"; // If the choice is T or t the day printed on the monitor will be Tuesday
			break;
		case 'W': dayName = "Wednesday"; // If the choice is W or w the day printed on the monitor will be Wednesday
			break;
		case 'H': dayName = "Thursday"; // If the choice is H or h the day printed on the monitor will be Thursday
			break;
		case 'F': dayName = "Friday"; // If the choice is F or f the day printed on the monitor will be Friday
			break;
		case 'S': dayName = "Weekend."; // If the choice is S or s the day printed on the monitor will be Weekend
			break;
		default: dayName = "No such day"; // If the choice is any other letter the day printed on the monitor will be No such day
		}

		cout << "\n  ***\tYour day is: " << dayName << ".\n"; // Message printed on the monitor

		
	}
	return 0;
}

