#include "cp9.hpp"
#include <vector>
#include <list>
#include <deque>

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

void ex9_1(void) {
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
	int somevalue = 2;
	std::vector<int> ivec = { 1, 2, 3, 2, 4, 5, 6, 7, 8 };
	auto iter = ivec.begin();
	auto mid = iter + (ivec.end() - iter) / 2;

	while (iter < mid) {
		if (*iter == somevalue) {
			iter = ivec.insert(iter, 2 * somevalue);
			iter++;
			mid = ivec.begin() + (ivec.end() - ivec.begin()) / 2 ;
		}
		iter++;
	}
	for (auto i : ivec) {
		cout << i << " ";
	}
	cout << endl;
}

void cp9_loop(void) {
	cout << "Welcom to cp9" << endl;

	ex9_1();
}