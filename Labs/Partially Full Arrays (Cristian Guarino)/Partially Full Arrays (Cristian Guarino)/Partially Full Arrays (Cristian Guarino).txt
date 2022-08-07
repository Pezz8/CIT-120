// This program This Program loads an array of double with students' scores and calculate basic statistics
// Partially Full Arrays (Cristian Guarino)
// Programmer : Cristian Guarino
// Last Modified: 12/04/2017

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int loadArray(double doubleArray[], int size, int minScore, int maxScore, string prompt, int logicalSize = 0);
int getDoubleLessThan(int maxScore, string input = "score");
double findHighestValue(const double doubleArray[], int logicalSize);
double findLowestValue(const double doubleArray[], int logicalSize);
double calcAverage(const double doubleArray[], int logicalSize);
void printBanner(int size, int perLine = 5, ostream& output = cout);
void printStatistics(const double doubleArray[], int logicalSize, ostream& output = cout);
void printArray(const double doubleArray[], int elementsToPrint, int start = 0, int perLine = 5, ostream& output = cout);

int main()
{
	const int 
		PHYSICAL_A_SIZE = 30, 
		MIN_SCORE = 0, 
		MAX_SCORE = 100;
	double studentsArray[PHYSICAL_A_SIZE];
	int logicalSize;
	string
		studentPrompt = "Enter Score for Student ",
		input;

	system("color 02");
	system("title Partially Fully Array (Cristian Guarino)");

	printBanner(PHYSICAL_A_SIZE);

	cout
		<< "Enter the students' score. Enter a negative value to stop.\n"
		<< "\t[Physical size of the array is "<< PHYSICAL_A_SIZE << "].\n\n";

	logicalSize = loadArray(studentsArray, PHYSICAL_A_SIZE, MIN_SCORE, MAX_SCORE, studentPrompt);
	cout << endl;

	cout << "\nThe logical size of the Array is: " << logicalSize << endl;

	cout << "\nHit Enter to see Array: ";
	cin.get();

	if (logicalSize > 0) {
		printArray(studentsArray, logicalSize);

		printStatistics(studentsArray, logicalSize);
	}
	else
		cout << "\nThe Array is Empty!";

	cout << endl << endl;
	system("pause");
	return 0;
}

int loadArray(double doubleArray[], int size, int minScore, int maxScore, string prompt, int logicalSize) {
	for (int i = 0; i < size; i++){
		cout << prompt << i + 1 << ": ";
		double score = getDoubleLessThan(maxScore);
		if (score < minScore){
			cout << "\nDone loading Scores!";
			return logicalSize;
		}
		else {
			doubleArray[i] = score;
			logicalSize++;
		}
	}
	return logicalSize;
}

int getDoubleLessThan(int maxScore, string input){
	int validScore;
	cin >> validScore;
	cin.ignore(200, '\n');

	while (validScore > maxScore)
	{
		cout << "Please type a valid "<< input << ": ";
		cin >> validScore;
		cin.ignore(200, '\n');
	}
	return validScore;
}

void printArray(const double doubleArray[], int elementsToPrint, int start, int perLine, ostream& output){
		for (int i = 0; i < elementsToPrint; i++)
			output << setw(7) << doubleArray[i] << (((i - start) + 1) % perLine == 0 ? '\n' : ' ');
}

double findHighestValue(const double doubleArray[], int logicalSize) {
	double highest = doubleArray[0];
	for (int i = 1; i < logicalSize; i++) {
		if (doubleArray[i] > highest) {
			highest = doubleArray[i];
		}
	}
	return highest;
}

double findLowestValue(const double doubleArray[], int logicalSize) {
	double lowest = doubleArray[0];
	for (int i = 1; i < logicalSize; i++) {
		if (doubleArray[i] < lowest) {
			lowest = doubleArray[i];
		}
	}
	return lowest;
}

double calcAverage(const double doubleArray[], int logicalSize) {
	double total = 0;
	for (int i = 0; i < logicalSize; i++)
		total += doubleArray[i];
	return total / logicalSize;
}

void printBanner(int size, int perLine, ostream& output) {
	output 
		<< "\n\t\t         This Program loads an array of double with students' scores                                 "
		<< "\n\t\t                using a negative value as the loop's sentinel                                        "
		<< "\n\t\t                         calculate basic statistics                                                  "
		<< "\n\t\t             setting physical size to " << size << " and default perline to " << perLine << ". \n\n\n";
}

void printStatistics(const double doubleArray[], int logicalSize, ostream& output) {
	output << "\n\n\tThe Highest score is: " << findHighestValue(doubleArray, logicalSize);
	output << "\n\tThe Lowest score is: " << findLowestValue(doubleArray, logicalSize);
	output << "\n\tThe Average score is: " << calcAverage(doubleArray, logicalSize);
}