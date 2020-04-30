#include "cp8.hpp"

std::istream &read(std::istream &s) {
	char c;

	while (s >> c) {
		cout << c;
	}
	cout << endl;
	s.clear();

	return s;
}

void ex8_1(void) {
	cout << "Enter something 1" << endl;
	std::istream &s = read(cin);

	cout << "Enter something 2" << endl;
	read(s);

}

void cp8_loop(void) {
	cout << "Welcom to cp8" << endl;

	char c1, c2, c3;

	cin >> c1;
	cout << c1 << endl;
	cin >> c2;
	cout << c2 << endl;
	cin >> c3;
	cout << c3 << endl;
	//ex8_1();

}
