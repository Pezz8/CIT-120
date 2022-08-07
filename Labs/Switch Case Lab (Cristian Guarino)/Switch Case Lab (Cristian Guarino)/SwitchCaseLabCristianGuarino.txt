// SwitchCaseLabCristianGuarino.cpp : Defines the entry point for the console application.
// This program calculates the total bill for the user depending on their monthly package and the number of songs downloaded
// The Switch Case Lab - Online music Store (Cristian Guarino)
// Programmer: Cristian Guarino
// Last Modified : 10/12/2017

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	system("title Switch Case Lab - Online music Store (Cristian Guarino)");
	system("color 02");

	cout << setprecision(2) << fixed;

	double
		user_monthly_rate, // Rate of monthly cost assigned with user Package
		user_additional_rate, // Rate assigned to additional songs cost with user Package
		
		numSongs, // Number of songs downloaded by user this month

		monthlyRate_A = 4.99, // Monthly rate for package A
		monthlyRate_B = 9.99, // Monthly rate for package B
		monthlyRate_C = 14.99, // Monthly rate for package C

		additionalSongRate_A = 0.99, // Additional song rate for package A
		additionalSongRate_B = 0.59, // Additional song rate for package B
		additionalSongRate_C = 0.29, // Additional song rate for package C

		tax = 0.06, // Tax Rate (6%)
		taxAmount = 0, // Tax amount on the bill
		totalPreTax = 0, // Taxable amount (Monthly + Additional Songs)
		totalBill = 0; // Total amount of the bill (Total Pre-Tax + Tax Amount)

	char packageChoice; // Users Package Choice 

	string numSongsPurchased; // Printout for song/s depending if plural or singular

	int
		user_free_songs, // Amount of free songs assigned to user
		user_extra_songs, // Amount of users extra songs (If numbers of songs downloaded are more than the number of monthly free songs)

		freeSongs_A = 10, // Amount of free songs for package A
		freeSongs_B = 20, // Amount of free songs for package B
		freeSongs_C = 30; // Amount of free songs for package C
		


	cout
		<< "\n\t\t                   Switch Case GROUP Lab                  "
		<< "\n\t\t                    On line music store                   "
		<< "\n\t\t         also needs nested if ... else statements         "
		<< "\n\t\t               and the conditional operator               "
		<< "\n\t\t       and the use of \"continue\" in one place ONLY      "
		<< "\n\t\t                    by Cristian Guarino             \n\n\n";

	while (true)
	{
		cout
			<< "Here are the possible option packages offered in our store:\n"
			<< "   Package A: Monthly fee $" << setw(5) << monthlyRate_A << ". " << freeSongs_A << " free songs and $" << additionalSongRate_A << " per song after that.\n"
			<< "   Package B: Monlhly fee $" << setw(5) << monthlyRate_B << ". " << freeSongs_B << " free songs and $" << additionalSongRate_B << " per song after that.\n"
			<< "   Package C: Monthly fee $" << setw(5) << monthlyRate_C << ". " << freeSongs_C << " free songs and $" << additionalSongRate_C << " per song after that.\n\n";


		cout << "Please select the option package that you have? ";
		cin >> packageChoice;
		cin.ignore(200, '\n');// User selection of listed packages


		switch (packageChoice)
		{


		case 'A': // Package A or a value assignement
		case 'a':
			user_monthly_rate = monthlyRate_A;
			user_free_songs = freeSongs_A;
			user_additional_rate = additionalSongRate_A;
			break;
		case 'B': // Package B or b value assignement
		case 'b':
			user_monthly_rate = monthlyRate_B;
			user_free_songs = freeSongs_B;
			user_additional_rate = additionalSongRate_B;
			break;
		case 'C': // Package C or c value assignement
		case 'c':
			user_monthly_rate = monthlyRate_C;
			user_free_songs = freeSongs_C;
			user_additional_rate = additionalSongRate_C;
			break;
		default:
			cout
				<< "\n\t*** Sorry we do not offer that packet!\n\n\n"; // Message shown for any choice that is not a/A, b/B, c/C.
			system("pause");
			cout << "\n     ***************************************************************\n\n";
			continue;
		}

		cout << "How many songs did you download this month? ";
		cin >> numSongs;
		cin.ignore(200, '\n');// Number of songs downloaded by the user

		if (numSongs < 0) // Number of songs needs to be a positive integer
		
			cout << "\n\t*** Sorry you cannot have a negative numbers of songs."; // Error message for negative number of songs
		
		else if (numSongs != static_cast<int>(numSongs)) // Number of songs needs to be a whole number
		
			cout << "\n\t*** Sorry your number of songs has to be a whole number."; // Error message for non integer number of songs
		
		else // If Number of songs is neither a negative number or a non-integer
		{
			{
				if (numSongs > user_free_songs) // If the Number of songs downloaded is more than the monthly free songs

					user_extra_songs = numSongs - user_free_songs; // The number of extra songs will be equal to the number of songs downloaded - the number of free songs
																   // assigned to the user with the package.
				else

					user_extra_songs = 0; // Else the number of extra songs will be 0
			}

			totalPreTax = user_monthly_rate + (user_extra_songs*user_additional_rate); // Calculating the value of the Pre-Taxable amount
			taxAmount = totalPreTax*tax; // Calculating the amount of tax that needs to be paid
			totalBill = totalPreTax + taxAmount; // Calculating the total of the bill

			cout // Message displaying the listed amount of the bill first separate (pre-tax amount and tax amount) and then total
				<< "\nYour total bill for this month is $" << setw(5) << totalPreTax  // Formatting value to occupy 5 spaces and having 2 decimal points after the dot.
				<< " + $" << setw(5) << taxAmount
				<< " (for tax) = " << fixed << totalBill << ".";

			if (user_extra_songs > 0) // If the number of extra songs is more than 0
			{
				if (user_extra_songs == 1) // If the number of extra songs is equal to 1

					numSongsPurchased = "song"; // The string variable will print "song"

				else // If the number of extra songs is not equal to 1

					numSongsPurchased = "songs"; // The string variable will print "songs"

				cout // If there are any extra songs downloaded this message will print
					<< "\n\tYou have $" << setw(5) << user_extra_songs*user_additional_rate 
					<< " extra charges for having " << user_extra_songs << " more " << numSongsPurchased
					<< "\n\tthan your monthly limint of " << user_free_songs << " free songs.";
			}
		}
		cout << "\n\n\n";
		system("pause");
		cout << "\n     ***************************************************************\n\n";
	}
	return 0;
}


