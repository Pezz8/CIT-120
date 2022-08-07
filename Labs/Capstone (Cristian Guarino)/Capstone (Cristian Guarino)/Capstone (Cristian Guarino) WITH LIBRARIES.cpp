// This program evaluates if a program is divisible by 3 or 5 or both and return a message accordingly
// Capstone (Cristian Guarino)
// Programmer: Cristian Guarino
// Last modified: December 13, 2017

#include "myFunctions.h"

int main()
{
	system("color 02");
	system("title Flip Flop Capstone (Cristian Guarino)	WITH LIBRARIES");

	string number, fileName;
	ofstream output;
	const int 
		FLIP = 3,
		FLOP = 5;

	printBanner(); // PRINT BANNER TO CONSOLE
	printInstructions(FLIP, FLOP); // PRINT BANNER TO CONSOLE

	cout << "What is the filename you want to store your output: ";
	getline(cin >> ws, fileName);

	connectOutStream(output, fileName); // CONNECTING TO FILE

	printBanner(output); // PRINT BANNER TO FILE
	printInstructions(FLIP, FLOP, output); // PRINT INSTRUCTIONS TO FILE

	cout << "\nWhat is your Number: ";
	number = getValidLargeInteger();

	while (!cin.fail()) {  // DONE

		output << "\tYour number was " << number << endl; // PRINT THE NUMBER VALUE TO THE FILE

		printResults(number, FLIP, FLOP); // PRINTING RESULTS TO CONSOLE
		printResults(number, FLIP, FLOP, output); // PRINTING RESULTS TO FILE

		system("pause");
		cout << "\n\nWhat is your Number: ";
		number = getValidLargeInteger();
	}
	cin.clear();
	output.close();

	cout << "\n\t*** Program about to end. Your output can be found in " << fileName << endl << "Hit ENTER to terminate";
	cin.get();
	return 0;
}