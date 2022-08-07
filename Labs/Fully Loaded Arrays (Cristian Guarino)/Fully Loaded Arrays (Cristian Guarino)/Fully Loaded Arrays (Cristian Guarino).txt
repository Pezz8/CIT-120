#include <iostream>
#include <iomanip>
#include <stdlib.h> // Library that holds the random function.
#include <ctime> // Library that enables the program to consider the time on the pc for the rndm calculation
using namespace std;

void printBanner(); // Print the banner of the program. PROTOTYPE
// This function will print all the values of the array.
void printArray(const int intArray[], int size, int perLine=5, int start =0); // PROTOTYPE
// This function will assign random numbers to the array.
void loadRndmArray(int intArray[], int size); // PROTOTYPE

int main()
{
	const int 
		LRG_A_SIZE = 100, // Size of the larger array. 
		SML_A_SIZE = 12; // Size of the smaller array.
	int
		smlArray[SML_A_SIZE], // Small array
		lrgArray[LRG_A_SIZE], // Large array
		perLine; // The variable that will hold the numbers of values printed on each line

	printBanner(); // Printing Banner

	cout << "******************       SMALL array      ********************\n\n"; 
	cout << "I am about to fully load smallArray with random generated numbers ...\n\n"; // Debugging
	loadRndmArray(smlArray, SML_A_SIZE); // Loading Random Numbers in the smlArray with the correct size

	cout << "I am about to call printArray (with the default value for the perLine)...\n"; // Debugging
	printArray(smlArray, SML_A_SIZE); // Printing smlArray with the correct size and the default values.

	cout << endl << endl; 

	system("pause"); // Pause

	cout << "\n\n******************       BIG array        ********************\n\n";
	cout << "I am about to fully load bigArray with random generated numbers ...\n\n"; // Debugging
	loadRndmArray(lrgArray, LRG_A_SIZE); // Loading Random Numbers in the lrgArray with the correct size
	cout << "Finished loading bigArray...\n\n"; // Debugging

	cout << "I am about to call printArray (with 8 perLine)...\n"; // Debugging
	perLine = 8; // This will make the function print 8 values on each line
	printArray(lrgArray, LRG_A_SIZE, perLine); // Printing lrgArray

	cout << endl << endl << endl;

	system("pause"); // Pause
	return 0; // End of the Program
}

// Banner Function
void printBanner() {
	cout
		<< "\n\t\t          This is a lab on completely filled arrays           "
		<< "\n\t\t               with randomly generated numbers                "
		<< "\n\t\t      the SAME load function is used to load BOTH arrays      "
		<< "\n\t\t     the SAME print funciton is used to print both arrays     "
		<< "\n\t\t                     By Cristian Guarino                \n\n\n";
}

// Print Array Function
void printArray(const int intArray[], int end, int perLine, int start) {
	for (int i = start; i < end; i++)
	{	/*cout << setw(8) << intArray[i] << "  ";
		if ((((i - 0) + 1) % perLine) == 0)
			cout << "\n";*/
		cout << setw(7) << intArray[i] << (((((i - 0) + 1) % perLine) == 0) ? '\n' : ' ');
	}
}

// Loading Random Numbers into arrays function
void loadRndmArray(int intArray[], int size) {
	srand(time(0));
	for (int i = 0; i < size; i++)
		intArray[i] = rand();
}