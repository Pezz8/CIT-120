// This Program will use overloading functions to calculater the area of the circle, the rectangle and the triangle
// Function Design Overloading (Cristian Guarino)
// Programmer: Cristian Guarino
// Last Modified: 11/21/2017


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// FUNCTIONS TEST PROTOTYPES
//void triangleArea();
//void rectangleArea();
//void circleArea();

// FUNCTIONS PROTOTYPES
void printBanner(); // Fuction holding the banner of the program
void handleChoice(char choice); // Function that will keep the program open or close it based on the choice made
void mySwap(double &sideX, double &sideY); // This will swap the value in the variables
void rearrange(double &sideX, double &sideY, double &sideZ); // This function will rearrange the order of the 
															 // variables from the smallest to the greatest
bool isTriangle(double sideX, double sideY, double sideZ); // This fuction will check if the values given by the user
														   // can refer to a valid triangle
double calcArea(double radius); // This function will calculate the aria of the cirlce
double calcArea(double length, double width); // This function will calculate the area of the rectangle
double calcArea(double sideX, double sideY, double sideZ); // This function will calculate the area of the circle
double getPositiveNumber(); // This function will take a number from the user making sure it is a positive number
char getChoice(); // This function will take a choice from the user making sure that the choice is nothing but Y,y,N or n

/*
bool isTriangle(double sideX, double sideY, double sideZ);
*/
const double PI = 3.141592654; // Global Variable for PI

int main()
{

	system("color 02"); // Color for The background and the font of the program
	system("title Fuction Design Overloading (Cristian Guarino)"); // Title of the program

	cout << fixed << setprecision(6) << endl; // All results will show 6 decimal numbers

	double sideX, sideY, sideZ; // Variables for the Triangle
	double length, width; // Variables for the Rectangle
	double radius; // Variables for the Circle
	char choice; // Variable that stores the choice made by the user

	printBanner(); // Printing Banner

	while (true) // INFINITE LOOP
	{

		cout << "\nDo you want to start the program? "; // Prompt for the user

		choice = getChoice(); // Assign value to choice through the getChoice function
		handleChoice(choice); // Handle the choice made by the user

		//circleArea();

		cout << "\nGive me the radius of the circle: "; // Prompt for the user
		radius = getPositiveNumber(); // Assign value to the radius of the circle through the getPositiveNumber fucntion
		cout << "\tThe Area of the circle is " << calcArea(radius) << endl << endl; // Print out the area of the Circle

		//rectangleArea();

		cout << "Give me the leght of the rectangle: "; // Prompt for the user
		length = getPositiveNumber(); // Assign value to the lenght of the rectangle through the getPositive function
		cout << "...and the width: "; // Prompt for the user
		width = getPositiveNumber(); // Assign value to the width of the rectangle through the getPositive function
		cout << "\tThe Area of the rectangle is " << calcArea(length, width) << endl << endl; // Print out the area of the Rectangle

		//triangleArea();

		cout
			<< "\nGive me the lenght of the sides of a triangle." // Prompt for the user
			<< "\nSide 1: "; // First side of the triangle
		sideX = getPositiveNumber(); // Assign value to the first side through getPositiveNumber function
		cout << "Side 2: "; // Second side of the triangle
		sideY = getPositiveNumber(); // Assign value to the second side through getPositiveNumber function
		cout << "Side 3: "; // Third side of the triangle
		sideZ = getPositiveNumber(); // Assign value to the second side through getPositiveNumber function

		while (!isTriangle(sideX, sideY, sideZ)) // While the sides are not suitable for a trianlge ask the user for other values for the 
												 // three sides
		{
			cout
				<< "\nThe sum of two sides of a triangle must be greater than the third side"
				<< "\nTry Again. Side 1: ";
			sideX = getPositiveNumber();
			cout << "Side 2: ";
			sideY = getPositiveNumber();
			cout << "Side 3: ";
			sideZ = getPositiveNumber();
		}

		cout << "\tThe Area of the triangle is: " << calcArea(sideX, sideY, sideZ) << endl << endl; // Print the triangle area

		cout << "\t*********************\n";

		cout << "\nDo you want to start the program again? "; // Prompt for the user

		choice = getChoice(); // Assign value to choice through the getChoice function
		handleChoice(choice); // Handle the choice made by the user

	}

	system("pause");
}

void printBanner() // Function holding the banner for the program
{
	cout
		<< "\n\t\t                  Project on Designing Overloading Functions             "
		<< "\n\t\t               Find the area of a rectangle, triangle, or circle         "
		<< "\n\t\t     also does extensive input validation and uses by reference variables"
		<< "\n\t\t                             By Cristian Guarino                   \n\n\n";
}

double getPositiveNumber() // Functions that gets positive number from the users
{
	double positiveNumber;
	cin >> positiveNumber;
	cin.ignore(200, '\n');
	while (positiveNumber <= 0) // If the value is less than equal than zero it will ask for a different value
	{
		cout << "Positive numbers only please. Try again: ";
		cin >> positiveNumber;
		cin.ignore(200, '\n');
	}

	return positiveNumber; // Returning the correct number
}

double calcArea(double radius) // Function that calculates the area of the circle
{
	return (pow(radius, 2)*PI);
}

double calcArea(double length, double width) // Function that calculates the area of the rectangle
{
	return length*width;
}

void rearrange(double &sideX, double &sideY, double &sideZ) // Rearrange Function
{
	if (sideX > sideY) mySwap(sideX, sideY);
	if (sideX > sideZ) mySwap(sideX, sideZ);
	if (sideY > sideZ) mySwap(sideY, sideZ);
}

void mySwap(double &sideX, double &sideY) // The mySwap Function
{
	double swapX = sideY;
	sideY = sideX;
	sideX = swapX;
}

bool isTriangle(double sideX, double sideY, double sideZ) // This function checks if the sides given by the user are valid
{														  // for a triangle
	rearrange(sideX, sideY, sideZ); // Change the order of the sides in order to have the greatest side last

	if ((sideX + sideY) > sideZ) // If the sum of the 2 smaller sides is more than the larger side the values are valid
								// for a triangles
		return true;
	else
		return false; // If not it is not a triangle
}

double calcArea(double sideX, double sideY, double sideZ) // Function that calculates the area of the triangle
{
	// double semiPerimeter = (sideX + sideY + sideZ) / 2;
	return (0.25)*sqrt((sideX+sideY+sideZ)*(-sideX+sideY+sideZ)*(sideX-sideY+sideZ)*(sideX+sideY-sideZ));
	// THIS VERSION OF THE HERON'S FORMULA DOES NOT NEED A SEMIPERIMETER
	// 1/4sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c))
}

// THE FOLLOWING FUNCTIOS WERE CREATED TO BE USED IN THE MAIN FOR THE PROMPTS AND THE PRINTOUTS
/*
void triangleArea()
{
	double sideX, sideY, sideZ;

	cout
		<< "\nGive me the lenght of the sides of a triangle."
		<< "\nSide 1: ";
	sideX = getPositiveNumber();
	cout << "Side 2: ";
	sideY = getPositiveNumber();
	cout << "Side 3: ";
	sideZ = getPositiveNumber();

	rearrange(sideX, sideY, sideZ);

	while (!isTriangle(sideX, sideY, sideZ))
	{
		cout
			<< "\nThe sum of two sides of a triangle must be greater than the third side"
			<< "\nTry Again. Side 1: ";
		sideX = getPositiveNumber();
		cout << "Side 2: ";
		sideY = getPositiveNumber();
		cout << "Side 3: ";
		sideZ = getPositiveNumber();
	}

	cout << "The Area of the triangle is: " << calcArea(sideX, sideY, sideZ) << endl;

}

void rectangleArea()
{
	double length, width;

	cout << "Give me the leght of the rectangle: ";
	length = getPositiveNumber();
	cout << "Give me the width of the rectangle: ";
	width = getPositiveNumber();
	cout << "\tThe Area of the rectangle is " << calcArea(length, width) << endl << endl;
}

void circleArea()
{
	double radius;

	cout << "Give me the radius of the circle: ";
	radius = getPositiveNumber();
	cout << "\tThe Area of the circle is " << calcArea(radius) << endl << endl;
}

*/

char getChoice() // Function that will get the correct choice
{
	char a; // local variable storing the value of the choice
	cin >> a; // input
	cin.ignore(200, '\n'); // Ignore other words

	while (!(a == 'Y' || a == 'y' || a == 'n' || a == 'N')) // While the input is not Y,y,N or n keep asking 
															// for different input
	{
		cout << "Please type only Y or N: "; // Message for the user
		cin >> a; // Input
		cin.ignore(200, '\n'); // Ignore other words
	}

	return a; // Return the correnct choice
}

void handleChoice(char choice)
{
	if (choice == 'n' || choice == 'N') // If the choice is N or n the program will close else it will continue
	{
		cout << "\nDon't you love Geometry?\n\n"; 
		system("pause");
		return exit(0); // Exit fucntion
	}
}