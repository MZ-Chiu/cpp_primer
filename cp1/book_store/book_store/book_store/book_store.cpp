// book_store.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "slaes_item.hpp"
#include "cp2.hpp"
#include "cp3.hpp"
#include "cp4.hpp"
#include "cp5.hpp"
#include "cp6.hpp"

void count_repetion_num(void) {
	int new_val = 0;
	int old_val = 0;
	bool first_num = true;
	int cnt = 1;

	std::cout << "Welcome to count_repetion_num, please enter some numbers\n";
	while (std::cin >> new_val) {
		if (first_num) {
			old_val = new_val;
			first_num = false;
			continue;
		}
		if (new_val == old_val) {
			cnt++;
		}
		else {
			std::cout << "Number " << old_val << " enter " << cnt << "times\n";
			cnt = 1;
		}
		old_val = new_val;
	}
	std::cout << "Number " << old_val << " enter " << cnt << "times\n";
}

void add_two_item(void) {
	Sales_item item1, item2;
	std::cout << "Entern 2 sales item:\n";
	std::cin >> item1 >> item2;

	if (item1.isbn() == item2.isbn()) {
		std::cout << (item1 + item2) << std::endl;
	}
	else {
		std::cout << "two item have different IBSN\n";
	}
}
void bookstore_loop(void) {
	std::cout << "\nWelcome to bookstore\n";

	//add_two_item();

	Sales_item new_item, totol_item;

	std::cout << "Enter some item to caculate\n";
	if(std::cin >> totol_item){
		while (std::cin >> new_item) {
			if (new_item.isbn() == totol_item.isbn()) {
				totol_item += new_item;
			}
			else {
				std::cout << "Sta: " << totol_item.isbn() << std::endl;
				std::cout << totol_item << std::endl;
				totol_item = new_item;
			}
		}
		std::cout << "Sta: " << totol_item.isbn() << std::endl;
		std::cout << totol_item << std::endl;
	}
	else {
		std::cout << "No item enter\n";
	}
}

void cp1_loop(void) {

	std::cout << "chapter 1\n";
	/* Count the repetion numbers */
	//count_repetion_num();

	/* Bookstore */
	bookstore_loop();
}


/*
 * main function
 */
int main()
{
    std::cout << "Hello C++ primer\n";

	//cp1_loop();

	//cp2_loop();

	//cp3_loop();

	//cp4_loop();

	//cp5_loop();

	cp6_loop();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
