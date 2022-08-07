#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

bool hasSign(string number);
bool isValidInteger(string a);
string getValidLargeInteger();
int stringLenght(string number);
int sumOfDigits(string number);
int digitToInt(char ch);
void printResults(string number, int flip, int flop, ostream &output = cout);
void printBanner(ostream &output = cout);
void printInstructions(int flip, int flop, ostream &output = cout);
void connectOutStream(ofstream &output, string filename);

