#include "cp4.hpp"
#include <vector>

using std::vector;

void cp4_loop(void) {
	cout << "Welcome to cp4" << endl;
	
	vector<int> ivec = {1, 2, 3, 4};

	cout << *ivec.begin() << endl;
	cout << *(ivec.begin()) << endl;
}
