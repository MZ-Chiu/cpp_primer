#include "cp13.hpp"

void ex13_1(void) {
	// 13.1
	/*
	A copy constructor is a constructor which first parameter is a **reference** to the class type and 
	any additional parameters have **default values**.

	When copy initialization happens and that copy initialization requires either the copy constructor or the move constructor.

	- Define variables using an `=`
	- Pass an object as an argument to a parameter of nonreference type
	- Return an object from a function that has a nonreference return type
	- Brace initialize the elements in an array or the members of an aggregate class
	- Some class types also use copy initialization for the objects they allocate.
	*/

	// 13.2
	/*
	If declaration like that, the call would never succeed to call the copy constructor, 
	`Sales_data rhs` is an argument to a parameter, thus, we'd need to use the copy constructor to copy the argument, 
	but to copy the argument, we'd need to call the copy constructor, and so on indefinitely.
	*/

	// 13.3
	/*
	when we copy a `StrBlob`, the `shared_ptr` member's use_count add one.
	when we copy a `StrBlobPrts`, the `weak_ptr` member's use_count isn't changed.(cause the count belongs to `shared_ptr`)
	*/
	// 13.4
	/*
		```cpp
		Point global;
		Point foo_bar(Point arg) // 1, copy initialize
		{
			Point local = arg, *heap = new Point(global); // 2 copy initialize, 3 copy initialize
			*heap = local;
			Point pa[4] = { local, *heap }; // 4, 5 copy initialize
			return *heap; // 6 copy initialize
		}
	```
	*/

}

void cp13_loop(void) {
	cout << "Welcom to cp13" << endl;

	ex13_1();
}