#include <iostream>
#include <chrono>

using namespace std; 

int main() {
	// gets high resolution start time 
	auto start_time = chrono::high_resolution_clock::now();

	// my code here 
	
	// gets high resolution stop time
	auto end_time = chrono::high_resolution_clock::now();
	//calculates the difference between start and stop times in microseconds 
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
	// counts how many microseconds were in the duration
	long microseconds = duration.count();

	cout << " Time taken by code segment: " << microseconds << "microseconds." << endl;
	return 0;
}