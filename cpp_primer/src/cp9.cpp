#include "cp9.hpp"
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <fstream>
#include <sstream>

bool find_in_container(std::vector<int>::iterator begin,
					   std::vector<int>::iterator end, 
					   int n) {

	while (begin != end) {
		if (*begin++ == n) {
			return true;
		}
	}
	return false;
}

void ex9_1_2_3(void) {
	// 9.2
	//std::list<std::deque<int> > dq_list;

	// 9.3
	//std::vector<int> i_vec = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//std::deque<int> dq_vec = { 1, 2, 3, 4, 5, 6, 7, 8 };

	//i_vec.insert(i_vec.cbegin(), 0);
	//dq_vec.push_front(0);

	//int a = 0;
	//if (find_in_container(i_vec.begin(), i_vec.end(), a)) {
	//	cout << "find: " << a << endl;
	//}
	//else {
	//	cout << "can't find: " << a << endl;
	//}

	// 9.3.1
	// 9.18
	//string s;
	//std::deque<string> s_deque;

	//cout << "Enter someting.." << endl;
	//while (cin >> s) {
	//	s_deque.push_back(s);
	//}
	//for (auto i : s_deque) {
	//	cout << i << " ";
	//}
	//cout << endl;

	// 9.20
	//std::list<int> i_list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//std::deque<int> i_deq_odd, i_deq2_even;

	//cout << "list: ";
	//for (auto i : i_list) {
	//	if (i % 2 == 0) {
	//		i_deq2_even.push_back(i);
	//	}
	//	else {
	//		i_deq_odd.push_back(i);
	//	}
	//	cout << i << " ";
	//}
	//cout << endl;

	//cout << "odd: ";
	//for (auto i : i_deq_odd) {
	//	cout << i << " ";
	//}
	//cout << endl;

	//cout << "even: ";
	//for (auto i : i_deq2_even) {
	//	cout << i << " ";
	//}
	//cout << endl;

	// 9.22
	//int somevalue = 2;
	//std::vector<int> ivec = { 1, 2, 3, 2, 4, 5, 6, 7, 8 };
	//auto iter = ivec.begin();
	//auto mid = iter + (ivec.end() - iter) / 2;

	//while (iter < mid) {
	//	if (*iter == somevalue) {
	//		iter = ivec.insert(iter, 2 * somevalue);
	//		iter++;
	//		mid = ivec.begin() + (ivec.end() - ivec.begin()) / 2 ;
	//	}
	//	iter++;
	//}
	//for (auto i : ivec) {
	//	cout << i << " ";
	//}
	//cout << endl;
}

void ex9_3(void) {
	//9.24
	//std::vector<int> iv = {99, 88, 77};

	//cout << iv.at(0) << endl;
	//cout << iv[0] << endl;
	//cout << iv.front() << endl;
	//cout << *iv.begin() << endl;
	//cout << iv.back() << endl;

	//9.25
	//auto it = iv.end();
	//iv.erase(it, it);
	//for (auto i : iv) {
	//	cout << i << " ";
	//}
	//cout << endl;

	// 9.26
	//int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	//std::vector<int> iv;
	//std::list<int> il;

	//std::copy(ia, ia + sizeof(ia) / sizeof(ia[0]), std::back_inserter(il));
	//iv.assign(ia, ia + sizeof(ia) / sizeof(ia[0]));
	//auto it = iv.begin();
	//auto it2 = il.begin();

	//cout << "Make iv remain odd:" << endl;
	//while(it != iv.end()) {
	//	if (*it % 2 == 0) {
	//		it = iv.erase(it);
	//	}
	//	else {
	//		it++;
	//	}
	//}
	//cout << "Make il remain even:" << endl;
	//while (it2 != il.end()) {
	//	if (*it2 % 2) {
	//		it2 = il.erase(it2);
	//	}
	//	else {
	//		it2++;
	//	}
	//}
	//cout << "Out put iv:" << endl;
	//for (auto i : iv) {
	//	cout << i << " ";
	//}
	//cout << endl;
	//cout << "Out put il:" << endl;
	//for (auto i : il) {
	//	cout << i << " ";
	//}
	//cout << endl;

	//9.27
	//std::forward_list<int> flst = { 0, 1, 4, 2, 67, 21 ,3, 12, 34, 2, 1, 12, 12, 12, 32 ,57, 32};
	//auto prev = flst.before_begin();
	//auto curr = flst.begin();
	// //auto end = flst.end();//err, update in while loop, cause erase will make end unuseful

	//while (curr != flst.end()) {
	//	if (*curr % 2) {
	//		curr = flst.erase_after(prev);
	//	}
	//	else {
	//		prev = curr++;
	//	}
	//}
	//for (auto it : flst) {
	//	cout << it << " ";
	//}
	//cout << endl;

	//9.28
	//std::forward_list<string> str_flist = { "111", "222", "333", "444"};
	//auto prev = str_flist.before_begin();
	//auto curr = str_flist.begin();

	//while (curr != str_flist.end()) {
	//	if (*curr == "555" || ++curr == str_flist.end()) {
	//		str_flist.insert_after(curr, "xxx");
	//		break;
	//	}
	//}

	//for (auto it : str_flist) {
	//	cout << it << " ";
	//}
	//cout << endl;

	// 9.29
	//std::vector<int> iv(10, 9);

	//iv.resize(15);
	//for (auto i : iv) {
	//	cout << i << " ";
	//}
	//cout << endl;

	//iv.resize(5);
	//for (auto i : iv) {
	//	cout << i << " ";
	//}
	//cout << endl;

	//9.31
	//std::forward_list<int> flist = {1,2,3,4,5,6,7,8,9};
	//auto prev = flist.before_begin();
	//auto curr = flist.begin();

	//while (curr != flist.end()) {
	//	if (*curr % 2 == 0) {
	//		curr = flist.erase_after(prev);
	//	}
	//	else {
	//		prev = curr = flist.insert_after(curr, *curr);
	//		++curr;
	//	}
	//}
	//for (auto i : flist) {
	//	cout << i << " ";
	//}
	//cout << endl;

	//9.33
	//std::vector<int> iv(10, 1);
	//auto curr = iv.begin();

	//while (curr != iv.end()) {
	//	++curr;
	//	++curr;
	//}
	//cout << "End" << endl;

    //9.34
	std::vector<int> iv = {12, 32, 1, 111, 54, 123, 82, 12, 17, 12, 97, 32};
	auto curr = iv.begin();

	while (curr != iv.end()) {
		if (*curr % 2) {
			curr = iv.insert(curr, *curr);
			++curr;
		}
		++curr;
	}
	for (auto i : iv) {
		cout << i << " ";
	}
	cout << endl;
}

void ex9_4(void) {
	;
}

void string_replace(string &str, const string &old_str, const string &new_str) {
	auto pos = str.find(old_str);

	if (pos != string::npos) {
		auto it = str.begin() + pos;

		str.erase(pos, old_str.size());
		str.insert(pos, new_str.c_str());
	}
}

void string_replace2(string &str, const string &old_str, const string &new_str) {
	auto pos = str.find(old_str);

	if (pos != string::npos) {
		str.replace(pos, old_str.size(), new_str);
	}
}

string name_complete(const string &name, const string &prefix, const string &subfix) {
	//return prefix + " " + name + subfix;
	string s(name);

	//s.insert(s.begin(), prefix.begin(), prefix.end());
	//s.append(subfix.begin(), subfix.end());

	s.insert(0, prefix.c_str());
	s.insert(s.size(), subfix.c_str());
	return s;
}

void find_character(const string &s, string &find) {
	string number("0123456789");
	find.clear();
	string::size_type pos = 0;

	while ((pos = s.find_first_not_of(number, pos)) != string::npos) {
		find.push_back(s[pos]);
		++pos;
	}
}

void find_number(const string &s, string &find) {
	string number("0123456789");
	find.clear();
	string::size_type pos = 0;

	while ((pos = s.find_first_of(number, pos)) != string::npos) {
		find.push_back(s[pos]);
		++pos;
	}
}

/* Find the longest word in input stream, which don't contain s1/s2 */
void find_longest_word(std::istream &is, const string &s1, const string &s2) {
	string word;
	string result;
	string::size_type pos = 0;

	while (is >> word) {
		if (word.find_first_of(s1 + s2) == string::npos) {

			if (word.size() > result.size()) {
				result = word;
			}
		}
	}
	if (!result.empty()) {
		cout << "Longest word withou [" << s1 << "] and [" << s2 << "] is: " << result << endl;;
	}
	else {
		cout << "Not result" << endl;
	}
}

int cacul_sum_in_svec(std::vector<string> &sv) {
	int sum = 0;

	for (auto s : sv) {
		sum += std::stoi(s);
	}
	return sum;
}

Date::Date(const string &s) {
	const std::vector<string> month_vec = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	int result = 0;
	size_t pos = 0;
	string format_str = s;

	auto find_month = [&] (const string &s) {
		for (std::vector<string>::size_type i = 0; i != month_vec.size(); ++i) {
			if (month_vec[i].find(s.substr(0, 3)) != string::npos) {
				return i + 1;
			}
		}
		return 0u;
	};

	auto get_date = [&] (int type) {
		std::istringstream iss(format_str);
		string subs;

		if (type == 1 || type == 3) {
			iss >> subs;
			_month = find_month(subs);
			iss >> subs;
			_day = stoi(subs);
			iss >> subs;
			_year = stoi(subs);
		} else if (type == 2) {
			iss >> subs;
			_day = stoi(subs);
			iss >> subs;
			_month = stoi(subs);
			iss >> subs;
			_year = stoi(subs);
		}
	};

	if ( (pos = s.find(",")) != string::npos ) {
		// 1st type string: January 1, 1900
		format_str.replace(pos, 1, " ");
		get_date(1);
	}
	else if ((pos = s.find("/")) != string::npos) {
		// 2nd type string: 1/1/1900
		format_str.replace(pos, 1, " ");
		if ((pos = s.find("/", ++pos)) != string::npos) {
			format_str.replace(pos, 1, " ");
		}
		else {
			result = -1;
		}
		get_date(2);
	}
	else {
		// 3nd type string: Jan 1 1900
		get_date(3);
	}
	if (result < 0) {
		cout << "Err string: " << s << endl;
	}
	else {
		cout << "year: " << _year << " month: " << _month << " day: " << _day << endl;
	}
}

void ex9_5(void) {
	//9.41
	/*std::vector<char> cv = { 'a', 'b', 'c', 'd', 'e', 'f'};
	string s(cv.begin(), cv.end());
	cout << s << endl;*/

	//9.42
	//string s;
	//char c;
	//s.reserve(10);

	//while (cin >> c) {
	//	s.push_back(c);
	//}

	//9.43
	//string str("though"), str2("though"), old_str("tho"), new_str("thro");
	//string_replace(str, old_str, new_str);
	//cout << str << endl;

	// 9.44
	//string_replace2(str2, old_str, new_str);
	//cout << str2 << endl;

	//9.45
	//string s = name_complete("qiu", "Mr. ", "mingz");
	//cout << s << endl;

	//9.47
	//string s("ab2c3d7R4E6");
	//string find;
	//find_number(s, find);
	//cout << find << endl;
	//find_character(s, find);
	//cout << find << endl;

	// 9.49
	//string s1("abc"), s2("xyz");
	//std::ifstream ifs("F:/workspace/CPP/cpp_primer/data/longest_word.txt", std::ios::in);
	//find_longest_word(ifs, s1, s2);

	// 9.50
	//std::vector<string> sv(5, "55");
	//cout << "Sum of sv is: " << cacul_sum_in_svec(sv) << endl;

	// 9.51
	Date date1("January 1, 1900");
	Date date2("1/12/1900");
	Date date3("Oct 1 1900");
}

void cp9_loop(void) {
	cout << "Welcom to cp9" << endl;

	//ex9_1_2_3();

	//ex9_3();

	//ex9_4();

	ex9_5();
}