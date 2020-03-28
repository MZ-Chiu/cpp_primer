#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "cp2.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

void reference_test(void) {
	int val = 10;
	int &rval = val;
	/* C++ primer, chapter 5, declatre a reference's reference is illegal */
	int &rrval = rval;

	val = 11;
	std::cout << "val " << val << std::endl;
	std::cout << "rval " << rval << std::endl;
	std::cout << "rrval " << rrval << std::endl;
	rrval = 12;
	std::cout << "val " << val << std::endl;
	std::cout << "rval " << rval << std::endl;
	std::cout << "rrval " << rrval << std::endl;
}

void const_test(void) {
	const int a = 1;
	//const int b;// Error must initialize
}

void string_test(void) {
	string word;
	cout << "String test" << endl;

	cout << "Out put uninitialize string" << word << endl;

	//string word;
	//cout << "cin string test" << endl;
	//while (cin >> word) {
	//	cout << word << endl;
	//}

	//string line;
	//cout << "getline test" << endl;
	//while (getline(cin, line)) {
	//	if (!line.empty()) {
	//		cout << line << endl;
	//	}
	//}

	// Out put bigger string
	//string str1, str2;
	//cout << "input two string, will output bigger string" << endl;
	//cin >> str1 >> str2;
	//string big_str = str1 > str2 ? str1 : str2;
	//cout << big_str << endl;

	//cout << "input two string, will output longger string" << endl;
	//cin >> str1 >> str2;
	//string longger_str = str1.size() > str2.size() ? str1 : str2;
	//cout << longger_str << endl;

	// string concatenate
	//cout << "string concatenate" << endl;
	//while (cin >> word) {
	//	cout << word << " ";
	//}
	//cout << endl;
	
	// string test for loop
	//string str("Some string, hello!!");
	//for (decltype(str.size()) index = 0; index < str.size() && !isspace(str[index]); index++)
	//{
	//	str[index] = toupper(str[index]);
	//}
	//cout << str << endl;

	//decimalism to hex
	//string deci2hex("0123456789ABCDEF");
	//int n;
	//string hex_str;

	//cout << "Enter a decimalism string: ";
	//while (cin >> n) {
	//	hex_str += deci2hex[n];
	//	hex_str += " ";
	//}
	//cout << "Convert to hex string: " << hex_str << endl;

	// Exercise 3.2.3
	//string str;
	//cin >> str;
	//for (char &c : str)
	//{
	//	c = 'X';
	//}
	//cout << str;

	const string cstr("Keep out!");
	// auto will ignode top-const, and reserve bottom-const
	for (auto &c : cstr)
	{
		cout << c << endl;
	}
}

void vector_test(void) {
	cout << "welcom to cp3\n";

	//std::vector<string> svec;
	//string word;

	//cout << "Enter some word" << endl;
	//while (cin >> word) {
	//	svec.push_back(word);
	//}
	//
	////for (decltype(svec.size()) i = 0; i < svec.size(); i++)
	//for (auto i : svec)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;

	//std::vector<unsigned int> grade(11, 0);
	//unsigned int n = 0;

	//cout << "Enter some score [0:100], we will caculate the member of every 10 score increase " << endl;
	//while (cin >> n) {
	//	grade[n / 10]++;
	//}

	//for (size_t i = 0; i < 11; i++)
	//{
	//	if (i != 10) {
	//		cout << "[" << i * 10 << " : " << i * 10 + 9 << "] " << grade[i] << endl;
	//	}
	//	else {
	//		cout << "[100] " << grade[i] << endl;
	//	}
	//}

	// Exercise 3.17
	//std::vector<string> svec;
	//string word;

	//cout << "Enter some word, transform to upper" << endl;
	//while (cin >> word) {
	//	svec.push_back(word);
	//}
	//for (auto &s : svec)
	//{
	//	transform(s.begin(), s.end(), s.begin(), toupper);
	//}
	//for (auto s : svec)
	//{
	//	cout << s << " ";
	//}
	//cout << endl;

	// Exercise 3.20
	std::vector<unsigned> ivec;
	unsigned n = 0;

	cout << "Enter some number, get the sum of n_begin + n_end" << endl;
	while (cin >> n) {
		ivec.push_back(n);
	}
	while(ivec.size())
	{
		unsigned n1 = 0, n2 = 0, sum = 0;

		n1 = ivec[0];
		n2 = ivec[ivec.size() - 1];
		sum = n1 + n2;
		if (ivec.size() - 1 == 0){
			sum /= 2;
		}
		cout << sum << endl;

		if (ivec.size() <= 2) {
			break;
		}
		ivec.erase(ivec.begin());
	    ivec.pop_back();
	}
}

void cp2_loop(void) {
	std::cout << "Welcom to cp2\n";

	//reference_test();

	//const_test();

	//string_test();

	vector_test();
}