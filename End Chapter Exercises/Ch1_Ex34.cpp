// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int j = 10;
	int k = 2;
	int l = 4;

	j = k*j;
	l = k*l;
	k = j + l;

	cout << k << endl;
	system("pause");
    return 0;
}

