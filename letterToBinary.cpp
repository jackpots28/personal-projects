// letterToBinary.cpp : Defines the entry point for the console application.
// Jack Sims - July 7, 2018
//

//#include <stdio>
#include <stdlib.h>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;



int main(){
	
	stringstream ss; // string stream to convert string to char

	vector<char>list; // vector for containing letters to convert
	vector<int>binList;
	
	// declarations for inputs and initials 
	char input = ' ';
	string endIn = "ENDOUT";
	char end = ' ';

	// apart of string stream for string to char conversion
	ss << endIn;
	ss >> end;

	cout << "Enter list of letters (\"endOUT\" to end): " << endl;

	// loop for vector input
	while (input != end) {
		cin >> input;
		list.push_back(input);
		binList.resize(list.size());
	}


	// outer "if" used for if condition of 'quit' is met
	if (input == end){
		// lists the contents of vector
		for (int i = 0; i < list.size() - 1; i++) {
			cout << list.at(i) << " ";
		}
		cout << endl << endl;

		// inner loop for converting chars to binary ascii then out-putting it to seperate lines
		for (int j = 0; j < list.size() - 1; j++) {
			char buffer[1500];
			(int)list.at(j);
			
			binList.at(j) = _itoa_s(list.at(j), buffer, 2);
			//printf("Binary: %s\n", buffer); - old output statement
			cout << "Binary conversion of: " << (char)list.at(j) << " -> " << buffer << endl;
		}		
	}
	

    return 0;
}

