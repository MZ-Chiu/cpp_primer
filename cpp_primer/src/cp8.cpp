#include "cp8.hpp"
#include <fstream>

std::istream &read(std::istream &s) {
	string c;

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

void ex8_2(void) {
	std::fstream f1("F:/workspace/CPP/cpp_primer/data/string.txt", std::ios::in | std::ios::in);
	std::vector<string> s_vec;
	string s;

	if (!f1.is_open()) {
		cout << "File open fail" << endl;
	}
	else {
		//while (f1 >> s) { // get word
		while (getline(f1, s)) { // get linn
			cout << s << endl;
			//s_vec.push_back(s);
		}
	}
}

void cp8_loop(void) {
	cout << "Welcom to cp8" << endl;

	//ex8_1();
	
	ex8_2();

}
