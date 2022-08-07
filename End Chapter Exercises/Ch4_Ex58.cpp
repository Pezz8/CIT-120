// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	cout << "Enter your 3 test scores and I will "
		<< "avarege them:";
	int score1, score2, score3;
	cin >> score1 >> score2 >> score3;
	double avarage;
	avarage = (score1 + score2 + score3) / 3.0;
	bool perfectScore = 0;
	if (avarage == 100)
		perfectScore = true;
	cout << "Your avarage is " << avarage << endl;
	
	if (perfectScore)
	{
		cout << "Congratulations!\n";
		cout << "That's a perfect score.\n";
		cout << "You deserve a pat on the back!\n";
	}
	system("pause");
	return 0;

}

