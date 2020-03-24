#include <iostream>
#include "cp2.hpp"

void reference_test(void) {
	int val = 10;
	int &rval = val;
	/* C++ primer, chapter 5, declatre a reference's reference is illegal */
	int &rrval = rval;

	val = 11;
	std::cout << "val " << val << std::endl;
	std::cout << "rval " << rval << std::endl;
	std::cout << "rrval " << rrval << std::endl;
	rrval = 12;
	std::cout << "val " << val << std::endl;
	std::cout << "rval " << rval << std::endl;
	std::cout << "rrval " << rrval << std::endl;
}

void const_test(void) {
	const int a = 1;
	//const int b;// Error must initialize
}

void cp2_loop(void) {
	std::cout << "Welcom to cp2\n";

	reference_test();

	const_test();
}