#include "cp8.hpp"
#include "cp7.hpp"
#include <fstream>
#include <sstream>

std::istream &read(std::istream &s) {
	string c;

	while (s >> c) {
		cout << c << " ";
	}
	cout << endl;
	s.clear();

	return s;
}

void ex8_1(void) {
	cout << "Enter something 1" << endl;
	std::istream &s = read(cin);

	cout << "Enter something 2" << endl;
	read(s);

}

void ex8_2(void) {
	//std::fstream f1("F:/workspace/CPP/cpp_primer/data/string.txt", std::ios::in | std::ios::out);
	//std::vector<string> s_vec;
	//string s;

	//if (!f1.is_open()) {
	//	cout << "File open fail" << endl;
	//}
	//else {
	//	//while (f1 >> s) { // get word
	//	while (getline(f1, s)) { // get linn
	//		cout << s << endl;
	//		//s_vec.push_back(s);
	//	}
	//	f1 << "HEllo" << endl;
	//}

	Sales_data item;
	std::fstream f2_in("F:/workspace/CPP/cpp_primer/data/salesData.txt", std::ios::in);
	std::ofstream f2_out("F:/workspace/CPP/cpp_primer/data/salesData2.txt", std::ios::out | std::ios::app);

	while (read(f2_in, item)) {
		print(cout, item);
		print(f2_out, item);	
	}
}

bool isValidPhoneNum(const string &num) {
	return num.size() == 11;
}

string formatPhoneNum(const string &num) {
	string s = num;
	s.insert(0, "+86");
	return s;
}

void ex8_3(void) {
	// 8.9
	//string s;

	//cout << "Enter a string" << endl;

	//getline(cin, s);
	//std::stringstream ss(s);

	//read(ss);

	// 8.10
	//std::ifstream f_in("F:/workspace/CPP/cpp_primer/data/salesData.txt");

	//string s;
	//std::vector<string> svec;
	//while (getline(f_in, s)) {
	//	svec.push_back(s);
	//}
	//for (auto s : svec) {
	//	std::stringstream ss(s);
	//	read(ss);
	//}

	// 8.11
	//string line;
	//std::stringstream record;
	//std::vector<personInfo> phoneBook;

	//cout << "Enter some personInfo(name phone1 phone2...)" << endl;
	//while (getline(cin, line)) {
	//	string phone;
	//	personInfo info;

	//	record.str(line);
	//	record >> info.name;
	//	while (record >> phone) {
	//		info.phones.push_back(phone);
	//	}
	//	record.clear();
	//	phoneBook.push_back(info);
	//}

	//cout << "name\t" << "phone" << endl;
	//for (auto info : phoneBook) {
	//	cout << info.name << "\t";
	//	for (auto phone : info.phones) {
	//		cout << phone << "\t\t";
	//	}
	//	cout << endl;
	//}

	// 8.13
	string line;
	std::stringstream record;
	std::vector<personInfo> phoneBook;
	std::ifstream f_in("F:/workspace/CPP/cpp_primer/data/phoneBook.txt");
	std::ofstream f_out("F:/workspace/CPP/cpp_primer/data/phoneBook1.txt", std::ios::app);

	cout << "Reading phoneBook..." << endl;
	while (getline(f_in, line)) {
		string phone;
		personInfo info;

		record.str(line);
		record >> info.name;
		while (record >> phone) {
			info.phones.push_back(phone);
		}
		record.clear();
		phoneBook.push_back(info);
	}

	cout << "name\t\tphone(Correct phone num will be write to new file)" << endl;
	for (auto info : phoneBook) {
		std::ostringstream formatted, badNums;

		for (const auto phone : info.phones) {
			if (isValidPhoneNum(phone)) {
				formatted << formatPhoneNum(phone) << " ";
			}
			else {
				badNums << phone << " ";
			}
		}
		if (badNums.str().empty()) {
			cout << info.name << "\t\t" << formatted.str() << endl;
			f_out << info.name << "\t\t" << formatted.str() << endl;
		}
		else {
			std::cerr << info.name << "\t\t#invalid phone num: " << badNums.str() << endl;
		}
	}
}

void cp8_loop(void) {
	cout << "Welcom to cp8" << endl;

	//ex8_1();
	
	//ex8_2();
	
	ex8_3();
}
