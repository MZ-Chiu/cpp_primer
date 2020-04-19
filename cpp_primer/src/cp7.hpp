#pragma once
#include "common.hpp"

class Sales_data {
	// Don't use friend function as possible
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);

public:
	string   bookNo_;
	uint32_t unit_sole_;
	double   revenue_;

public:
	Sales_data(const string &book, uint32_t n, double p) : bookNo_(book), unit_sole_(n), revenue_(n * p) {
		cout << "Constructor 1" << endl;
	}
	Sales_data() : unit_sole_(0) {
		cout << "Constructor 2" << endl;
	}
	Sales_data(std::istream &is) { 
		is >> bookNo_;
		cout << "Constructor 3" << endl;
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

void cp7_loop(void);
