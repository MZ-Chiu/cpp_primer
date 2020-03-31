#include "cp4.hpp"

void cp4_loop(void) {
	cout << "Welcom to cp4" << endl;

	cout << "Enter a num, judge odd/even" << endl;

	int n = 0;
	cin >> n;
	if (n % 2) {
		cout << "Even number" << endl;
	}
	else {
		cout << "Odd number" << endl;
	}

}