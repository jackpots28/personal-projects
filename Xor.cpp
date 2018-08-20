// Xor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	cout << convert(3);
	
	ifstream inFS;
	vector<long> plainText;
	vector<long> keyText;
	vector<long> cipherText;
	int N = 0; //size of buffer (plaintext)
	int M = 0; //size of buffer for other stream (key)
	int i = 0; //iterator
	int j = 0; //iterator

	//---------------------------------------------------------------


	//--Input for PLAIN TEXT
	inFS.open("plainText.txt"); 
	if (!inFS.is_open()) {  
		cout << "Could not open file plainText.txt.\n";
		return 1;
	}
	inFS >> N;
	plainText.resize(N);
	
	
	i = 1;
	while (i <= N) {
		inFS >> plainText.at(i - 1);
		i = i + 1;
	}
	inFS.close();


	//--------------------------------------------------------------
	//--------------------------------------------------------------


	//--Input for KEY TEXT
	inFS.open("key.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file key.txt.\n";
		return 1;
	}
	inFS >> M;
	keyText.resize(M);

	j = 1;
	while (j <= M) {
		inFS >> keyText.at(j - 1);
		j = j + 1;
	}
	inFS.close();

	//-------------------------------------------------------------


	cipherText.resize(M);

	//--Compares the two vectors and Xor's them
	for (int n1 = 0; n1 < plainText.size(); n1++) {
		if (plainText.at(n1) == keyText.at(n1)) {
			cipherText.at(n1) = 0;
		}
		else {
			cipherText.at(n1) = 1;
		}
	}
	

	//--Outputs cipher text
	cout << "\nCipher text: ";
	i = 0;
	while (i < N) {
		cout << cipherText.at(i) << " ";
		++i;
	}
	cout << endl;

	//--END
	


    return 0;
}

