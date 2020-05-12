#include "cp10.hpp"
#include <vector>
#include <algorithm>
#include <numeric>


void ex10_1() {
	std::vector<int> iv = { 1, 2, 3,4 ,5 ,6 ,4 ,3 ,2, 1, 1 };
	int i = 1;

	cout << "Find " << i << " " << std::count(iv.cbegin(), iv.cend(), i) << endl;

	std::vector<string> sv = { "aa", "bb", "cc", "aa", "dd", "aa"};
	string s("aa");

	cout << "Find " << s << " " << std::count(sv.cbegin(), sv.cend(), s) << endl;
}

void ex10_2() {
	std::vector<int> iv = {1, 2, 3, 4,5, 6, 7, 8, 9, 10};

	int sum = std::accumulate(iv.cbegin(), iv.cend(), 0);
	cout << "Sum of iv:" << sum << endl;

	//std::vector<double> vd = { 1.1, 0.5, 3.3 };
	//std::cout << "ex 10.04: "
	//	<< std::accumulate(vd.cbegin(), vd.cend(), 0)
	//	<< std::endl;
}

void cp10_loop(void) {
	cout << "Welcom to cp10" << endl;

	//ex10_1();

	ex10_2();
}