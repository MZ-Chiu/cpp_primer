#pragma once
#include <vector>
#include "common.hpp"

class Sales_data {
	// Don't use friend function as possible
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);

private:
	string   bookNo_;
	uint32_t unit_sole_;
	double   revenue_;

public:
	Sales_data(const string &book, uint32_t n, double p) : bookNo_(book), unit_sole_(n), revenue_(n * p) {
		cout << "Constructor 1" << endl;
	}
	Sales_data() : unit_sole_(0) {
		//cout << "Constructor 2" << endl;
	}
	Sales_data(std::istream &is) { 
		is >> bookNo_;
		//cout << "Constructor 3" << endl;
	}

	string isbn() const { return bookNo_; };
	bool compare(const Sales_data &item1, const Sales_data &item2) { return item1.isbn() == item2.isbn(); }
	Sales_data &combine(const Sales_data &item);
};

std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);

class Person {
public:
	string name_;
	string addr_;

public:
	Person(string name, string addr) : name_(name), addr_(addr) {}
	Person(std::istream &is) { read(is); }

	void print() const { cout << "name: " << name_ << ", address: " << addr_ << endl; }
	void read(std::istream &is) { is >> name_ >> addr_; }
};

class Screen {
	friend class Window_mgr;

public:
	typedef string::size_type pos;

	Screen() = default;
	Screen(pos height, pos width, char c) : height_(height), width_(width), contents_(height * width, c) { }

	void display(void);
	char get() const { return contents_[cursor_]; }
	char get(pos h, pos w) const { return contents_[h * width_ + w]; }
	Screen &set(char c) { contents_[cursor_] = c; return *this; }
	Screen &move(pos h, pos w) { cursor_ = h * width_ + w; return *this; }
	pos size(void) const { return height_ * width_; };

private:
	pos cursor_ = 0;
	pos height_ = 0;
	pos width_ = 0;
	string contents_;

};

class Window_mgr {
public:
	using screen_idx = std::vector<Screen>::size_type;

	Window_mgr &clear(screen_idx idx);

	void display(screen_idx idx) { screens[idx].display(); };

	Window_mgr &add(Screen s) { screens.push_back(s); return *this; }

private:
	std::vector<Screen> screens;
};

class Y;

class X {
	Y *py;
};

class Y {
	X x;
};

void cp7_loop(void);
