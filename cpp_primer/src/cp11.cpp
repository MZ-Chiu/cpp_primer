#include "cp11.hpp"
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <list>
#include <utility>
#include <fstream>

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

class Families1 {
	using Child = std::pair<string, string>;
	using Member = std::multimap<string, Child>;

public:
	Families1 &add(string f, string l, string b) { members.insert({ f, {l, b} }); return *this; }
	//Families1 &add(string f, string l, string b) { members.emplace(f, Child ( l, b )); return *this; }
	void print() {
		for (auto member : members) {
			cout << member.first << " ";
			cout << member.second.first << "'s birthday is " << member.second.second << endl;
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

std::map<string, string> make_trans_map(std::ifstream &map_file) {
	std::map<string, string> trans_map;
	string key, value;

	while (map_file >> key && std::getline(map_file, value)) {
		if (value.size() > 1) {
			trans_map[key] = value.substr(1);
		}
		else {
			cout << "No value for key" << endl;
		}
	}

	return trans_map;
}

void word_transform(std::ifstream &map_file, std::ifstream &in_file) {
	std::map<string, string> trans_map = make_trans_map(map_file);
	string text;

	while (std::getline(in_file, text)) {
		std::stringstream ss(text);
		string word;

		while (ss >> word) {
			auto it = trans_map.find(word);
			if (it != trans_map.end()) {
				cout << (*it).second << " ";
			}
			else {
				cout << word << " ";
			}
		}
		cout << endl;
	}

}

void ex11_3(void) {
	// 11.15
	//std::map<int, std::vector<int>> int_map;
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
	//std::map<string, size_t> dictionary;
	//string word;
	//cout << "Enter some words :" << endl;
	//while (cin >> word) {
	//	word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
	//	transform(word.begin(),word.end(), word.begin(), ::tolower);
	//	auto ret = dictionary.insert({word, 1});
	//	if (!ret.second) {
	//		++ret.first->second;
	//	}

	//}
	//for (auto pair : dictionary) {
	//	cout << pair.first << " occur " << pair.second << (pair.second > 1 ? " times" : "time") << endl;
	//}

	// 11.21
	// Count the word occurs times.

	// 11.22
	//std::map<string, std::vector<int>> s2ivec_map;
	//std::pair<std::map<string, std::vector<int>>::iterator, bool> ret = s2ivec_map.insert({"xxx", std::vector<int> (2, 3)});

	// 11.23
	//Families1 fa1;
	//string f, l, b;

	//cout << "Entern some people first name, last name, birthday:" << endl;
	//while (cin >> f >> l >> b) {
	//	fa1.add(f, l, b);
	//}
	//fa1.print();
	
	// 11.24, 11.25, 11.26

	// 11.27
	// use count in multi-map/multi-set, as for associative container use find instead of count.

	// 11.28
	//std::map<string, std::vector<int>> map;
	//map["xx"] = std::vector<int>{1, 2, 3};
	////auto it = map.find("xx");
	//std::map<string, std::vector<int>>::iterator it = map.find("xx");

	// 11.29
	/*
	If the element is not in the multimap, then lower_bound
	and upper_bound will return equal iterators; both will
	refer to the point at which the key can be inserted without
	disrupting the order.

	If no matching element is found, then both the first and
	second iterators refer to the position where this key can
	be inserted.
	*/

	// 11.30
	/* mapped */

	// 11.31, 11.32
	//std::multimap<string, string> author_book;
	//string book;
	//string author;

	//cout << "Enter author and book" << endl;
	//while (cin >> author >> book)
	//{
	//	author_book.emplace(author, book);
	//}
	//cin.clear();

	//cout << "Enter author to delete" << endl;
	//cin >> author;

	//auto pos = author_book.equal_range(author);
	//author_book.erase(pos.first, pos.second);
	//for (auto it : author_book) {
	//	cout << it.first << "'s book: " << it.second << endl;
	//}

	// 11.33 - 11.36
	//std::ifstream map_file("../data/ex11_33_map_file.txt");
	//std::ifstream in_file("../data/ex11_33_in_file.txt");
	//word_transform(map_file, in_file);

	// 11.37
	/*
		unordered container
			advantage :insert, find, erase element in constant time.
			disadvantage : element not ordered in container
		ordered container
			advantage : element is ordered in container
			disadvantage : ops not constant time
	*/

    // 11.38
	std::unordered_map<string, size_t> dictionary;
	string word;
	cout << "Enter some words :" << endl;
	while (cin >> word) {
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
		transform(word.begin(),word.end(), word.begin(), ::tolower);
		++dictionary[word];
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