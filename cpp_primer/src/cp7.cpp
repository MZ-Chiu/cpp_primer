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

void Screen::display(void) {
	pos size = width_ * height_;
	pos align = cursor_ % width_;

	for (pos n = 0; n < align; ++n) {
		cout << " ";
	}
	for ( ; cursor_ < size; ++cursor_) {
		cout << contents_[cursor_];
		if( (cursor_ + 1) % width_ == 0)
			cout << endl;
	}
}
Window_mgr &Window_mgr::clear(screen_idx idx) {
	Screen &s = screens[idx];
	s.cursor_ = 0;
	s.contents_ = string(s.height_ * s.width_, 'o');

	return *this;
}

void ex7_3(void) {
	Screen s1(6, 8, '*');

	cout << "Dispaly org" << endl;
	s1.display();
	
	cout << "Dispaly atert move(3, 7)" << endl;
	s1.move(3, 7).display();

	cout << "Dispaly atert move(0, 0)" << endl;
	s1.move(0, 0).display();

	cout << "Dispaly atert move(2, 2).set('#')" << endl;
	s1.move(2, 2).set('#').display();

	cout << "Dispaly atert win_mgr.add(s1).clear(0);" << endl;
	Window_mgr win_mgr;
	s1.move(0, 0);
	win_mgr.add(s1).clear(0).display(0);
}
void cp7_loop(void) {
	cout << "Welcom to cp7" << endl;

	//ex7_1();

	//ex7_2();

	ex7_3();
	 
}
