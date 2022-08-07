// This program will use a function to swap the the values assigned to x and y
// MySwap Lab by (Cristian Guarino)
// Programmer: Cristian Guarino
// Last Modified : 11/06/2017


#include <iostream>
using namespace std;

void mySwap(double &, double &);

int main()
{
	double 
		xValue,
		yValue;

	cout
		<< "\n\t\t         mySwap Function               "
		<< "\n\t\t         and driver Lab                "
		<< "\n\t\t       by Cristian Guarino       \n\n\n";

	while (true)
	{
		cout << "Enter a number for x: ";
		cin >> xValue;
		cin.ignore(200, '\n');

		cout << "Enter a number for y: ";
		cin >> yValue;
		cin.ignore(200, '\n');

		cout
			<< "\nBEFORER the function call: x = " << xValue << " y = " << yValue << endl
			<< "\tI'm calling the \"mySwap\" function ...";

		mySwap(xValue, yValue);

		cout
			<< "\nAFTER the function call: x = " << xValue << " y = " << yValue << endl << endl << endl;

		system("pause");
	}
	
	return 0;
}

void mySwap(double &xValue, double &yValue)
{
	double swapX = yValue;
	yValue = xValue;
	xValue = swapX;
}