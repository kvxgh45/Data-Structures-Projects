#include <iostream>

using namespace std; 

int main() {
	int max_ct = 15;
	int max_rand = 1000;

	srand(time(nullptr));
	for (int i = 0; i < max_ct; i++) {
		cout << rand() % max_rand << endl;
	}
	return 0;
}