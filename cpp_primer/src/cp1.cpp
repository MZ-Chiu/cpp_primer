#include "cp1.hpp"
#include "slaes_item.hpp"

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
	if (std::cin >> totol_item) {
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
