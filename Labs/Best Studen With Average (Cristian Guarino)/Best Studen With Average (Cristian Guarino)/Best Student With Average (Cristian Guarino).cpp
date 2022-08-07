#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void printBanner(ostream &output = cout);


int main()
{

	string studentFirstName;

	int numberOfStudents;

	printBanner();

	cout << "Please enter the number of Students in your class: ";
	cin >> numberOfStudents;
	cin.ignore(200, '\n');

	cout << "Please enter the name of Student #" << studentNumber << 






	return 0;
}

void printBanner(ostream &output)
{
	output
		<< "          This lab will calculate the avarege score of each student            "
		<< "                  a show the student with the best average.                    "
		<< "                           By Cristian Guarino                                 ";
}

int loadArray(double doubleArray[], int size, int minScore, int maxScore, string prompt, int logicalSize) {
	for (int i = 0; i < size; i++) {
		cout << prompt << i + 1 << ": ";
		double score = getDoubleLessThan(maxScore);
		if (score < minScore) {
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