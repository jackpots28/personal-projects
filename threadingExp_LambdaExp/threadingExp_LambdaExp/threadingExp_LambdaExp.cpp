// threadingExp_LambdaExp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>

using namespace std;

template <typename t1>
void printVecLst(vector<t1>& pVect) {
	for_each(pVect.begin(),
		pVect.end(),
		[](t1& element) {cout << element << " "; }
	);
}



// test for threading...
/*
template <typename t2>
void printV(vector<t2>& vect) {
	for_each(vect.begin(),
		vect.end(),
		[](t2& element) {cout << element << " "; }
	);
}
*/


int main()
{
	vector<int> intVect;
	// vector<int> intThdVect;
	vector <char> chrList;

	for (int i = 0; i < 10; ++i) {
		intVect.push_back(i);
	}

	/*
	for (int j = 0; j < 20; ++j) {
		intThdVect.push_back(j);
	}
	*/

	for (char cI = 'a'; cI < 'k'; ++cI) {
		chrList.push_back(cI);
	}

	/*
	cout << "Printing vector of Integers uing thread: " << endl;
	thread t1(printV<int>, intThdVect);
	t1.join();
	cout << endl << endl;
	*/

	cout << "Printing vector of Integers: " << endl;
	thread intThdObj(printVecLst<int>, intVect);
	intThdObj.join();
	cout << endl << endl;

	cout << "Pring list of Chars: " << endl;
	thread chrThdObj(printVecLst<char>, chrList);
	chrThdObj.join();
	cout << endl << endl;

    return 0;
}

