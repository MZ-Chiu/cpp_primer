#include "cp5.hpp"
#include <vector>
#include <algorithm>

using std::vector;

static void exercise_5_3_part1(void) {
	string s_in_all;
	string s_in;
	string s_out;
	int vowel = 0;
	int space = 0;
	int tab = 0;
	int line_break = 0;

	cout << "Enter string, count voewl" << endl;
	while (std::getline(cin, s_in)) {
	//while ((cin >> std::noskipws >> s_in)) { // break when receive line break
		s_in_all += s_in;
		/*
		   C++ algorithms do not grow their target container automatically.
		   You must either make the space yourself, or use a inserter adaptor.
		*/
		/* 1. Use resize */
		s_out.resize(s_in.length());
		std::transform(s_in.begin(), s_in.end(), s_out.begin(), tolower);
		/* 2. Use back_inserter */
		//std::transform(s_in.begin(), s_in.end(), std::back_inserter(s_out), tolower);
		for (auto i : s_out) {
			switch (i) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vowel++;
					break;

				case ' ':
					space++;
					break;

				case '\t':
					tab++;
					break;

				case '\n':
					line_break++;
					break;
			}

		}
	}
	cout << "vowel :" << vowel << endl;
	cout << "space :" << space << endl;
	cout << "tab :" << tab << endl;
	cout << "line_break :" << line_break << endl;
}

static void exercise_5_3_part2(void) {
	char c = EOF;
	char c_last = EOF;
	int vowel = 0;
	int space = 0;
	int tab = 0;
	int line_break = 0;
	int fx_cnt = 0;
	bool f_flag = false;

	cout << "Enter string, count specified character" << endl;
	while ((c = cin.get()) != EOF) {
		c = tolower(c);

		if (c_last == 'f') {
			if (c == 'f' || c == 'i' || c == 'l') {
				fx_cnt++;
			}
		}
		c_last = c;

		switch (c) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				vowel++;
				break;

			case ' ':
				space++;
				break;

			case '\t':
				tab++;
				break;

			case '\n':
				line_break++;
				break;
		}
	}
	cout << "vowel :" << vowel << endl;
	cout << "space :" << space << endl;
	cout << "tab :" << tab << endl;
	cout << "line_break :" << line_break << endl;
	cout << "fx_cnt :" << fx_cnt << endl;
}

static void exercise_5_3(void) {
	exercise_5_3_part1();
	//exercise_5_3_part2();
}

static void exercise_5_2(void) {
	//string s("string");
	//for (string::iterator i = s.begin(); i != s.end(); i++)
	//{
	//	cout << *i << endl;
	//}

	//string::iterator i = s.begin();
	//while (i != s.end()) {
	//	cout << *i++ << endl;
	//}
}

static void exercise_5_4_part1(void) {
	vector<string> svec;
	string s_in;
	string s_tmp;
	string s_repet_max;
	int repet_cnt = 1;
	int repet_cnt_max = 1;

	cout << "Count repet string" << endl;

	while (cin >> s_in) {
		svec.push_back(s_in);
	}
	for (auto iter : svec) {
		if (!s_tmp.empty()) {
			if (s_tmp == iter) {
				repet_cnt++;
			}
			else {
				//cout << "[" << iter <x< "]" << "repet " << repet_cnt << " times" << endl;
				if (repet_cnt_max < repet_cnt) {
					repet_cnt_max = repet_cnt;
					s_repet_max = iter;
				}
				repet_cnt = 1;
			}
		}
		s_tmp = iter;
	}
	if (repet_cnt_max > 1) {
		cout << "[" << s_repet_max << "]" << "repet MOST " << repet_cnt_max << " times" << endl;
	}
	else {
		cout << "No repet string" << endl;
	}
}

static void exercise_5_4_part2(void) {
	//vector<int> ivec1 = { 1, 2, 3, 4, 5, 6 };
	//vector<int> ivec2 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//int min = ivec1.size() < ivec2.size() ? ivec1.size() : ivec2.size();
	//string str = ivec1.size() < ivec2.size() ? "ivec1" : "ivec2";

	//size_t i = 0;
	//for ( ; i < min; i++)
	//{
	//	if (ivec1[i] != ivec2[i]) {
	//		break;
	//	}
	//}
	//if (i == min) {
	//	cout << "substring is:" << str << endl;
	//}
	//else {
	//	cout << "No substring" << endl;
	//}

	cout << "Find shoter string" << endl;
	string s1, s2;
	cin >> s1 >> s2;
	do {
		cout << "Shorter string is: [" << (s1.length() < s2.length() ? s1 : s2) << "]" << endl;
	} while (cin >> s1 >> s2);
}

static void exercise_5_4(void) {
	//exercise_5_4_part1();
	exercise_5_4_part2();
}

void cp5_loop(void) {
	cout << "Welcom to cp5" << endl;

	//exercise_5_2();
	//exercise_5_3();
	exercise_5_4();
}