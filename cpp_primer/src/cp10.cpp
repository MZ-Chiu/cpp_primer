#include "cp10.hpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

void ex10_1() {
	std::vector<int> iv = { 1, 2, 3,4 ,5 ,6 ,4 ,3 ,2, 1, 1 };
	int i = 1;

	cout << "Find " << i << " " << std::count(iv.cbegin(), iv.cend(), i) << endl;

	std::vector<string> sv = { "aa", "bb", "cc", "aa", "dd", "aa"};
	string s("aa");

	cout << "Find " << s << " " << std::count(sv.cbegin(), sv.cend(), s) << endl;
}

void ex10_2() {
	//// 10.3
	//std::vector<int> iv = {1, 2, 3, 4,5, 6, 7, 8, 9, 10};
	//int sum = std::accumulate(iv.cbegin(), iv.cend(), 0);
	//cout << "Sum of iv:" << sum << endl;
	//// 10.4
	//std::vector<double> vd = { 1.1, 0.5, 3.3 };
	//cout << "ex 10.04: " << std::accumulate(vd.cbegin(), vd.cend(), 0.0) << std::endl;

	// 10.5
	// 10.6
	//std::vector<int> iv = { 1, 2, 3, 4, 5, 6 };
	//std::fill_n(iv.begin(), iv.size(), 0);
	//for (auto i : iv) {
	//	cout << i << " ";
	//}
	//cout << endl;
	// 10.7
	// a. vec is empty
	// b. vec is empty
	// 10.8
	// casue the algotithm call back_insert, who will increase the container size.

	// 10.9
	std::vector<string> svec = { "the", "quick", "red", "fox", 
		"jumps", "over", "the", "slow", "red", "turtle"};
	std::sort(svec.begin(), svec.end());
	auto end_unique = std::unique(svec.begin(), svec.end());
	svec.erase(end_unique, svec.end());

	for (auto s : svec) {
		cout << s << " ";
	}
	cout << endl;

	// 10.10
	// 
}

bool isShorter(const string &a, const string &b) {
	return a.size() < b.size();
}

bool isShorter1(const string &a, std::string::size_type sz) {
	return a.size() < sz;
}

void elimDups(std::vector<string> &words) {
	std::sort(words.begin(), words.end());
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

void lambda_foo() {
	int a = 2;
	auto sum = [a](int b) {return a + b; };
	cout << sum(3) << endl;
}

void biggies(std::vector<string> &words, std::vector<string>::size_type sz) {
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), isShorter);
	auto wc = std::find_if(words.begin(), words.end(), [sz](const string &s) { return s.size() > sz; });
	std::for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
	cout << endl;
}

void biggies1(std::vector<string> &words, std::vector<string>::size_type sz) {
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), isShorter);
	auto end = std::stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() > sz; });
	auto wc = std::count_if(words.begin(), words.end(), [sz](const string &s) { return s.size() > sz; });
	cout << "There are " << wc << " words's size longger then " << sz << endl;
	std::for_each(words.begin(), end, [](const string &s) { cout << s << " "; });
	cout << endl;
}

void biggies2(std::vector<string> &words, std::vector<string>::size_type sz) {
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), isShorter);
	auto end = std::stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() > sz; });
	auto wc = std::count_if(words.begin(), words.end(), std::bind(isShorter1, std::placeholders::_1, sz));
	cout << "There are " << wc << " words's size longger then " << sz << endl;
	std::for_each(words.begin(), end, [](const string &s) { cout << s << " "; });
	cout << endl;
}

bool checkSize1(string s, std::string::size_type sz) {
	return s.size() > sz;
}

void biggies3(std::vector<string> &words, std::vector<string>::size_type sz) {
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), isShorter);
	auto end = std::stable_partition(words.begin(), words.end(), std::bind(checkSize1, std::placeholders::_1, sz));
	auto wc = std::count_if(words.begin(), words.end(), std::bind(isShorter1, std::placeholders::_1, sz));
	cout << "There are " << wc << " words's size longger then " << sz << endl;
	std::for_each(words.begin(), end, [](const string &s) { cout << s << " "; });
	cout << endl;
}

bool checkSize(unsigned a, std::string::size_type sz) {
	return sz < a;
}

void ex10_3(void) {
	// 10.11
	//std::vector<string> words = { "the", "quick", "red", "fox",
	//	"jumps", "over", "the", "slow", "red", "turtle" };
	//elimDups(words);
	//std::stable_sort(words.begin(),words.end(), isShorter);
	//std::for_each(words.begin(), words.end(), [](const string &s) { cout << s << " "; });

	// 10.12
	// 10.13
	//auto end = std::partition(words.begin(), words.end(), [](const string &s) {return s.size() > 4; });
	//std::for_each(words.begin(), end, [](const string &s) { cout << s << " "; });

	// 10.14
	//auto sum = [] (int a, int b) { return a + b; };
	//cout << sum(1, 2) << endl;

	// 10.15
	//lambda_foo();

	// 10.16
	//std::vector<string> words = { "the", "quick", "red", "fox",
	//	"jumps", "over", "the", "slow", "red", "turtle" };
	//biggies(words, 4);
	// 10.18, 10.19, 10.20
	//biggies1(words, 4);

	// 10.21
	//int a = 10;
	//auto f = [](int &a) -> bool { 
	//	if (a > 0) {
	//		--a; 
	//		return false;
	//	}
	//	else {
	//		return true;
	//	}
	//};

	//cout << "a = " << a << endl;
	//while (1) {
	//	if (f(a)) {
	//		cout << "a = " << a << endl;
	//		break;
	//	}
	//}

	// 10.22
	std::vector<string> words = { "the", "quick", "red", "fox",
		"jumps", "over", "the", "slow", "red", "turtle" };
	//biggies2(words, 4);

	// 10.23, bind can accecpt infinite number of arguments.

	// 10.24
	//string s("12345");
	//std::vector<unsigned> iv = {1, 2, 3, 4, 5, 6, 7, 8 };
	//
	//auto end = std::find_if(iv.begin(), iv.end(), std::bind(checkSize, std::placeholders::_1, s.size()));
	//cout << *end << endl;

	// 10.25
	biggies3(words, 4);
}

void cp10_loop(void) {
	cout << "Welcom to cp10" << endl;

	//ex10_1();

	//ex10_2();

	ex10_3();
}