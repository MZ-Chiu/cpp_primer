#include "cp9.hpp"
#include <vector>
#include <list>
#include <deque>
#include <forward_list>

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
	std::forward_list<string> str_flist = { "111", "222", "333", "444"};
	auto prev = str_flist.before_begin();
	auto curr = str_flist.begin();
	auto end = str_flist.end();

	while (curr != end) {
		if (*curr == "444" || ++curr == end) {
			str_flist.insert_after(curr, "xxx");
			break;
		}
	}

	for (auto it : str_flist) {
		cout << it << " ";
	}
	cout << endl;
}

void cp9_loop(void) {
	cout << "Welcom to cp9" << endl;

	//ex9_1_2_3();

	ex9_3();
}