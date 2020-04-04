#include "cp5.hpp"
#include <algorithm>

void exercise_5_2(void) {
	//string s("string");
	//for (string::iterator i = s.begin(); i != s.end(); i++)
	//{
	//	cout << *i << endl;
	//}

	//string::iterator i = s.begin();
	//while (i != s.end()) {
	//	cout << *i++ << endl;
	//}

	string s;
	string s1;
	int vowel = 0;

	cout << "Enter string, count voewl" << endl;
	cin >> s;
	/* 
	   C++ algorithms do not grow their target container automatically. 
	   You must either make the space yourself, or use a inserter adaptor.
	*/
	/* 1. Use resize */
	//s1.resize(s.length());
	//std::transform(s.begin(), s.end(), std::back_inserter(s1), tolower);
	/* 2. Use back_inserter */
	std::transform(s.begin(), s.end(), std::back_inserter(s1), tolower);
	for (auto i : s1) {
		switch (i) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			vowel++;
			break;
		}
	}
	cout << "vowel in [" << s << "]= " << vowel << endl;
}

void cp5_loop(void) {
	cout << "Welcom to cp5" << endl;

	exercise_5_2();
}