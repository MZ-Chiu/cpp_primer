#include "cp3.hpp"
#include <vector>

using std::vector;

void vector_test(void) {
	vector<vector<int>> ivec;
	//vector<string> svec = ivec;

	// construct a vector
	vector<string> s1_vec(10, "null");
	// list initialize.
	vector<string> s2_vec{ "hello", "vector" };
	// try list initialize fail, use construct initialize.
	vector<string> s3_vec{ 10, "null" };
	// try list initialize fail, use construct initialize.
	vector<string> s4_vec{ 10 };

	for (auto v : s3_vec)
	{
		cout << v << " ";
	}
	cout << endl;

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
	//for (auto i = grade.begin(); i != grade.end(); i++) {
	//	cout << *i << endl;
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
	//std::vector<unsigned> ivec;
	//unsigned n = 0;

	//cout << "Enter some number, get the sum of n_begin + n_end" << endl;
	//while (cin >> n) {
	//	ivec.push_back(n);
	//}
	//while(ivec.size())
	//{
	//	unsigned n1 = 0, n2 = 0, sum = 0;

	//	n1 = ivec[0];
	//	n2 = ivec[ivec.size() - 1];
	//	sum = n1 + n2;
	//	if (ivec.size() - 1 == 0){
	//		sum /= 2;
	//	}
	//	cout << sum << endl;

	//	if (ivec.size() <= 2) {
	//		break;
	//	}
	//	ivec.erase(ivec.begin());
	//    ivec.pop_back();
	//}

	// Exercise 3.4.1
	//std::vector<int> ivec;

	//for (size_t i = 0; i < 10; i++)
	//{
	//	ivec.push_back(i);
	//}
	//for (auto &i : ivec) 
	//{
	//	i *= 2;
	//}
	//for (auto i = ivec.begin(); i != ivec.end(); ++i) {
	//	cout << *i << " ";
	//}
	//cout << endl;
}

void array_test(void) {
	//int a[10] = { 0 };
	//int b[10] = { 0 };

	//for (size_t i = 0; i < 10; i++)
	//{
	//	a[i] = i;
	//}

	//memcpy(b, a, sizeof(a));
	//for (size_t i = 0; i < 10; i++)
	//{
	//	cout << b[i] << " ";
	//}
	//cout << endl;

	//std::vector<int> avec;
	//std::vector<int> bvec;

	//for (size_t i = 0; i < 10; i++)
	//{
	//	avec.push_back(i);
	//}
	//bvec = avec;
	//for (auto i : bvec) {
	//	cout << i << " ";
	//}
	//cout << endl;

	//Exercise 3.5.3
	//int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int b[10] = { 1, 2, 6, 7, 8, 9, 3, 4, 5, 10 };
	//int min_size = sizeof(a) > sizeof(b) ? sizeof(a) : sizeof(b);
	//min_size /= sizeof(a[0]);
	//int *p1 = &a[1];
	//int *p2 = &a[4];

	//p1 += p2 - p1;
	//cout << *p1 << endl;

	//for (auto &i : a) {
	//	i = 0;
	//}
	//for (auto i : a) {
	//	cout << i << " ";
	//}
	//for (size_t i = 0; i < min_size; i++)
	//{

	//}
	//cout << endl;

	//std::vector<int> avec;
	//std::vector<int> bvec;

	//for (size_t i = 0; i < 10; i++)
	//{
	//	avec.push_back(2 * i);
	//	bvec.push_back(2 * i);
	//}
	//bvec.push_back(0);
	//if (bvec == avec) {
	//	cout << "avec == bvec" << endl;
	//}
	//else {
	//	cout << "avec != bvec" << endl;
	//}
}

void cp3_loop(void) {
	cout << "Welcom to cp3\n";

	//vector_test();

	//array_test();
}
