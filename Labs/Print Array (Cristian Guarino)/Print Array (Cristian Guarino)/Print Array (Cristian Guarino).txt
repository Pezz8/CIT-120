#include <iostream>
#include <iomanip>
using namespace std;

void printArray(const int arrayInt[], int lg, int start = 0, int perline = 1);
void loadArray(int arrayInt[], int size);
void loadPrimeArray(int arrayPrime[], int size);
bool isPrimeNumber(int number);

int main()
{
	const int ODD_A_SIZE = 30;
	int oddArray[ODD_A_SIZE];
	int primArray[ODD_A_SIZE];
	int start;
	int perLine;

	cout << "\nPlease enter the start point: ";    // use the getPosInt
	cin >> start;
	cin.ignore(200, '\n');

	cout << "\nPlease enter the number of values per Line: ";
	cin >> perLine;  // use the getPosInt
	cin.ignore(200, '\n');
	
	// loadArray(oddArray, ODD_A_SIZE);
	loadPrimeArray(primArray, ODD_A_SIZE);
	printArray(oddArray, ODD_A_SIZE, start, perLine);

	cout << endl << endl;

	loadArray(oddArray, ODD_A_SIZE);
	printArray(oddArray, ODD_A_SIZE, start, perLine);

	system("pause");
	return 0;
}

void printArray(const int oddArray[], int lg, int start, int perLine) {
	for (int i = start; i < lg; i++)
	{
		cout << "oddArray["<< setw(2) << i << "]" << " = " << setw(3) << oddArray[i] << " " ;

		if ((((i - start) + 1) % perLine) == 0)   //  move to the previous statement and make conditional operator
			cout << "\n";
	}
}

void loadArray(int oddArray[], int size) {    //  done
	for (int i = 0; i < size; i++)
		oddArray[i] = i * 2 + 1;
}

void loadPrimeArray(int arrayPrime[], int size) 
{
	for (int i = 0, j = 2; i < size; i++, j++)
	{
		while (!isPrimeNumber(j))
		{
			j++;
		}
		arrayPrime[i] = j;
	}
}


bool isPrimeNumber(int number)
{
	for (int i = 2; i <= number / 2; ++i)
	{
		if (number%i == 0)
			return false;
	}
	return true;
}