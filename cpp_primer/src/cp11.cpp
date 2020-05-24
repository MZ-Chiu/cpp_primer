#include "cp11.hpp"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <list>

bool foo(int l, int r) {
	return l < r;
}

void ex11_1(void) {
	// 11.1
	/*
		The different between map and vector is:
		1. map have to member, vector have one.
		2. map is a associative container, vector is sequence container.

	*/

	// 11.2
	/*
		list : Double linked list, support constant time insert and remove of element in anywhere in the container.
		vector : Dynamic array.
		map : Dictionary.
		set : Keep element.
	*/

	// 11.3, 11.4
	//std::map<string, size_t> dictionary;
	//string word;
	//cout << "Enter some words :" << endl;
	//while (cin >> word) {
	//	word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
	//	transform(word.begin(),word.end(), word.begin(), ::tolower);
	//	++dictionary[word];
	//}
	//for (auto pair : dictionary) {
	//	cout << pair.first << " occur " << pair.second << (pair.second > 1 ? " times" : "time") << endl;
	//}

	// 11.5, 11.6

	// 11.7
	//std::map<string, std::vector<string>> families;
	//string line;

	//cout << "Enter some family:" << endl;
	//while (std::getline(cin , line)) {
	//	std::stringstream ss(line);
	//	string family_name;
	//	string child_name;

	//	ss >> family_name;
	//	while (ss >> child_name) {
	//		families[family_name].push_back(child_name);
	//	}
	//}
	//for (auto family : families) {
	//	cout << family.first << ":";
	//	std::for_each(family.second.cbegin(), family.second.cend(), [](auto name) { cout << name << " "; });
	//	cout << endl;
	//}

	// 11.8

	// 11.9
	//std::map<string, std::list<int>> word_pos;
	//int row = 0;
	//string line;

	//cout << "Enter a few line of text:" << endl;
	//while (std::getline(cin, line))
	//{
	//	std::stringstream ss(line);
	//	string word;
	//	
	//	++row;
	//	while (ss >> word) {
	//		word_pos[word].push_back(row);
	//	}
	//}
	//for (auto pair : word_pos) {
	//	cout << pair.first << " occur in row : ";
	//	for (auto i : pair.second)
	//	{
	//		cout << i << " ";
	//	}
	//	cout << endl;
	//}

	// 11.10

	// 11.11
	using f = bool (*)(int l, int r);
	//typedef bool (*f)(int l, int r);
	std::multiset<int, f> multi_xx(foo);
}

void cp11_loop(void) {
	cout << "Welcom to cp11" << endl;

	ex11_1();
}