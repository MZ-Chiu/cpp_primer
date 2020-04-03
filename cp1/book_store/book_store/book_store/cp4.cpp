#include "cp4.hpp"
#include <vector>

using std::vector;

void exercise_412(void) {
	//cout << 5 + 20 * 10 / 2 << endl;
	//int a=1, b=1, c=0, d=0;

	//if (a == b && c == d) {
	//	cout << "== higher" <<  endl;
	//}
	//else {
	//	cout << "&& higher" << endl;
	//}

	//int i = 1, j = 2, k = 3, m = 4;

	//int max_1 = i > j ? i : j;
	//int max_2 = k > m ? k : m;
	//cout << "max is " << (max_1 > max_2 ? max_1 : max_2) << endl;

	//vector<string> svec = { "ab", "cd", "ef" };
	//vector<int> ivec = { 1, 4, 8 };
	//vector<string>::iterator str_iter = svec.begin();
	//vector<int>::iterator int_iter = ivec.begin();

	//cout << *str_iter++ << endl;
	//cout << *str_iter++ << endl;
	//if (str_iter->empty()) {
	//	;
	//}

	//cout << (++*int_iter) << endl;

	// Exercise 4.7
	//vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//for (auto &i : ivec) {
	//	if (i % 2) {
	//		i *= 2;
	//	}
	//}
	//for (auto i : ivec) {
	//	cout << i << " ";
	//}
	//cout << endl;

	//vector<int> ivec = { 90, 88, 46, 65, 77 };
	//vector<string> svec;
	//for (auto i : ivec) {
	//	string grade = i > 85 ? "high" : i > 75 ? "low pass" : i > 60 ? "pass" : "fail";
	//	svec.push_back(grade);
	//}
	//for (auto i : ivec) {
	//	cout << i << "\t";
	//}
	//cout << endl;
	//for (auto s : svec) {
	//	cout << "[" << s << "]" << " ";
	//}
	//cout << endl;
}


void cp4_loop(void) {
	cout << "Welcome to cp4" << endl;
	
	exercise_412();
}
