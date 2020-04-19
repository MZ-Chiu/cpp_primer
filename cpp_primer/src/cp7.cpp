#include "cp7.hpp"

std::istream &read(std::istream &is, Sales_data &item) {
	double p = 0.0;

	is >> item.bookNo_ >> item.unit_sole_ >> p;
	item.revenue_ = p * item.unit_sole_;

	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
	os << item.bookNo_ << " " << item.unit_sole_ << " " << item.revenue_ << endl;
	return os;
}

Sales_data &Sales_data::combine(const Sales_data &item) {

	if (!compare(*this, item)) {
		cout << "Please enter the same ISBN to combine" << endl;;
	}
	revenue_ += item.revenue_;
	unit_sole_ += item.unit_sole_;

	return *this;
}

void ex7_1(void) {
	Sales_data item1("book1", 2, 3.0);

	print(cout, item1);

	cout << "Enter a Sales data item2, combine to item1:" << endl;
	Sales_data item2;
	read(cin, item2);

	item1.combine(item2);
	print(cout, item1);

	Sales_data item3(cin);
}

void ex7_2(void) {
	Person p1("qiu", "shenzhen");
	cout << "Enter a person:" << endl;
	Person p2(cin);

	p1.print();
	p2.print();
}

void cp7_loop(void) {
	cout << "Welcom to cp7" << endl;

	//ex7_1();

	ex7_2();
	 
}
