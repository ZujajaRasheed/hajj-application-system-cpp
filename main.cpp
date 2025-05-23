#include<iostream>
#include<string>
#include"Hajj.h"
using namespace std;



int main()
{

	// Allocate memory for an array of 5 Confirmation objects
	Confirmation* confirmations = new Confirmation[5];

	// Call the menu function for each Confirmation object
	for (int i = 0; i < 5; i++) {
		confirmations[i].menu();
	}

	//  free the allocated memory
	delete[] confirmations;



 return 0;
}