// TheClubAdmissionLab.cpp : Defines the entry point for the console application.
// This program will check the person's eligibility to enter the club.
// The Club Admission Lab
// Programmer: Cristian Guarino
// Last Modified: 02/10/2017

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	system("title The Club Admission Lab (Cristian Guarino)");
	system("color 02");

	const int
		MAX_AGE = 40,
		MIN_AGE = 21;
	double age;
	string fullName;

	cout
		<< "\n\t\t                  The \"Club Admission\" Lab                                           "
		<< "\n\t\t                note that the age is a double                                          "
		<< "\n\t\t                    needs an if ... else                                               "
		<< "\n\t\t               loops for ever for easy testing                                         "
		<< "\n\t\t              uses named consts for easy updates                                       "
		<< "\n\t\t      ONLY costumers with age in [" << MIN_AGE << ", " << MAX_AGE << ") are allowed in "
		<< "\n\t\t                    by Cristian Guarino                                          \n\n\n";

	while (true)
	{
		cout << "\nWhat is your FULL NAME? ";
		cin >> ws;
		getline(cin, fullName);

		cout << "How old are you \"" << fullName << "\"? ";
		cin >> age;
		cin.ignore(200, '\n');

		if (age >= MIN_AGE && age < MAX_AGE)
		{
			cout << "\n\tWelcome to the club " << fullName << "!" << endl << endl;
		}
		else
		{
			cout
				<< "\n\tSorry you need to be between " << MIN_AGE << " (Inclusive) and " << MAX_AGE << " (Exclusive)"
				<< "\n\tto be eligible to enter this establishment" << endl << endl;
		}

		cout << "Next Costumer Please!\n";
		system("pause");

	}


	return 0;
}
