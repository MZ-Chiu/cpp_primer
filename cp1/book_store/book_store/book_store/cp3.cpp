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
}

void cp3_loop(void) {
	cout << "Welcom to cp3\n";
	
	vector_test();
}
