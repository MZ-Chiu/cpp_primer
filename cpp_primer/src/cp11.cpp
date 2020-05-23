#include "cp11.hpp"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cctype>

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
	std::map<string, size_t> dictionary;
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

	ex11_1();
}