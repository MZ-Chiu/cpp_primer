#include "cp11.hpp"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <list>
#include <utility>

bool foo(int l, int r) {
	return l < r;
}

class Families {
	using Child = std::pair<string, string>;
	using Children = std::vector<Child>;
	using Member = std::map<string, Children>;

public:
	Families &add(string f, string l, string b) { members[f].emplace_back(l, b); return *this; }
	void print() { 
		for (auto member : members) {
			cout << member.first << endl;
			for (auto child : member.second) {
				cout << "name " << child.first << " birthday " << child.second << endl;
			}
			cout << endl;
		}
	}

private:
	Member members;
};

void ex11_1_2(void) {
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
	//using f = bool (*)(int l, int r);
	////typedef bool (*f)(int l, int r);
	//std::multiset<int, f> multi_xx(foo);

	// 11.12, 11.13
	//std::vector<std::pair<string, int>> pair_vec;
	//string word;
	//int num;

	//cout << "Enter English and Arabic numerals: " << endl;
	//while (cin >> word >> num) {
	//	//pair_vec.push_back(std::pair<string, int>(word, num));
	//	//pair_vec.push_back(std::make_pair(word, num));
	//	//pair_vec.push_back({ word, num });
	//	pair_vec.emplace_back(word, num);
	//}
	//for (auto num_pair : pair_vec) {
	//	cout << num_pair.first << ":" << num_pair.second << endl;
	//}
	//cout << endl;

	// 11.14
	Families fa;
	string f, l, b;

	while (cin >> f >> l >> b) {
		fa.add(f, l, b);
	}
	fa.print();
}

void ex11_3(void) {
	// 11.15
	std::map<int, std::vector<int>> int_map;
	//std::map<string, string> s_map = { "xxx", "yyy" };
	/* mapped_type is std::vector<int>, key_type is int, value_type is pair<int, std::vector<int>> */
	//std::map<int, std::vector<int>>::mapped_type xx;
	//std::map<int, std::vector<int>>::key_type yy;
	//std::map<int, std::vector<int>>::value_type zz;

	// 11.16
	//std::map<int, string> map;
	//map[11] = "qiu";
	//cout << map[11] << endl;
	//auto it = map.begin();
	//it->second = "zhang";
	//cout << map[11] << endl;

	// 11.17
	/* third is illegal no push_back in set. */

	// 11.18
	//std::map<string, size_t>::iterator wc_it;

	// 11.19

	// 11.20
	std::map<string, size_t> dictionary;
	string word;
	cout << "Enter some words :" << endl;
	while (cin >> word) {
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		transform(word.begin(),word.end(), word.begin(), ::tolower);
		auto ret = dictionary.insert({word, 1});
		if (!ret.second) {
			++ret.first->second;
		}

	}
	for (auto pair : dictionary) {
		cout << pair.first << " occur " << pair.second << (pair.second > 1 ? " times" : "time") << endl;
	}
}

void cp11_loop(void) {
	cout << "Welcom to cp11" << endl;

	//ex11_1_2();

	ex11_3();
}