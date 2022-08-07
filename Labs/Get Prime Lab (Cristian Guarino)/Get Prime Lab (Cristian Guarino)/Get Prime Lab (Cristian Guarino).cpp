// PrimeNumbersFunction.cpp : Defines the entry point for the console application.
//


#include <iostream>
using namespace std;

bool isPrimeNumber(int number);
bool isPositiveInteger(double number);
int getPrimeNumber();


int main()
{
	double number;

	while (true)
	{
		cout << "Type a number and I will tell you if is prime or not: ";
		number = getPrimeNumber();
	



		//		while (isPositiveInteger(number) == false)
		/*
		while (!isPositiveInteger(number))
		{
			cout << "Please enter a Positive Integer: ";
			cin >> number;
			cin.ignore(200, '\n');
		}
		
		while (!isPrimeNumber(number))
			{
				cout
					<< "Your Number is not a Prime Number"
					<< "\nPlease enter a Prime number: ";
				cin >> number;
				cin.ignore(200, '\n');
			}
		*/
		cout << "The number " << number << " is Prime\n";
		system("pause");
	}
	return 0;
}

/*
bool isPrimeNumber(int number)
{
bool status=false;

for (int i = 2; i <= number/2; ++i)
{
if (number%i == 0)
{
status = true;
break;
}
}
return status;
}
*/
bool isPrimeNumber(int number)
{
	for (int i = 2; i <= number / 2; ++i)
	{
		if (number%i == 0 || number ==1)
			return false;
	}
	return true;
}

/*
bool isPositiveInteger(double number)
{
bool status;
if ((number < 0) || (number != static_cast<int>(number)))
status = false;
else
status = true;
return status;
}
*/
bool isPositiveInteger(double number)
{
	return (number > 0 && number == static_cast<int>(number));
}

int getPrimeNumber()
{
	int primeNumber;
	cin >> primeNumber;
	cin.ignore(200, '\n');

	while (!isPrimeNumber(primeNumber))
	{
		cout << "Please type a Prime number: ";
		cin >> primeNumber;
		cin.ignore(200, '\n');
	}
	return primeNumber;
}