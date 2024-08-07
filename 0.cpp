/*
Bryce H.
CSE 2383, Data Structures 
Dr. Jones
01/17/2024
Challenge 0 
*/

// Directive
#include <iostream>
#include <string> 

using namespace std;

int main() {
	
	string I;
	
	// Asking user to enter a character 
	cout << " Please enter your favorite Ice Cream flavor: ";
	cin >> I;

	//Conditional Statement 
		if (I == "Vanilla" || I == " Cookies n' Cream") {
			cout << " You are the goat!" << endl;
		}
		else{
			cout << "eww, Vanilla dominated flavors are superior!" << endl;
		}
	//Termination
	return 0;
}