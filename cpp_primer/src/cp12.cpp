#include "cp12.hpp"
#include <vector>
#include <memory>

class strBlob
{
public:
	strBlob() : data(std::make_shared<std::vector<string>> ()) {};
	strBlob(std::initializer_list<string> il) : data(std::make_shared<std::vector<string>>(il)) {};
	strBlob &push_back(const string &s) { data->push_back(s); return *this; }
	//const strBlob &push_back(const string &s) const { data->push_back(s); return *this; }

	void print() {
		for (auto s : *data)
		{
			cout << s << " ";
		}
		cout << endl;
	};
	const string &front(void) { return data->front(); }
	const string &back(void) { return data->back(); }

private:
	std::shared_ptr<std::vector<string>> data;
};

std::vector<int> *new_vector() {
	return new std::vector<int>;
}

std::shared_ptr<std::vector<int>> make_shared_vector() {
	return std::make_shared<std::vector<int>>();
}

void fill_vector(std::vector<int> *p) {
	int n = 0;
	cout << "This is new, enter some numbers:" << endl;
	cin.clear();
	while (cin >> n) {
		p->push_back(n);
	}

	for (auto i : *p) {
		cout << i << " ";
	}
	cout << endl;
}

void fill_vector(std::shared_ptr<std::vector<int>> p) {
	int n = 0;
	cout << "This is share pointer, enter some numbers:" << endl;
	cin.clear();
	while (cin >> n) {
		p->push_back(n);
	}

	for (auto i : *p) {
		cout << i << " ";
	}
	cout << endl;
}

class fd
{
public:
	fd() : fs_ref(0) {};
	~fd() { if (fs_ref > 0) disconnect(); };

	void connect() { ++fs_ref; cout << "connect " << fs_ref << endl; };
	void disconnect() { /*if (fs_ref > 0) --fs_ref; cout << "disconnect " << fs_ref << endl;*/ };

private:
	int fs_ref;
};

void ex_12_14(void) {
	fd my_fd;
	std::shared_ptr<fd> ();

	my_fd.connect();
	cout << "End of ex_12_14" << endl;
}
void ex12_1(void) {
	// 12.1 - 12.5
	//strBlob sb({ "a", "an" });
	//sb.push_back("im qmz");
	//sb.print();
	//cout << sb.front() << " " << endl;
	//cout << sb.back() << " " << endl;

	//const strBlob csb({ "aa", "aan" });
	////csb.push_back("xyz");

	// 12.6, 12.7
	//std::vector<int> *p_vec = new_vector();
	//std::shared_ptr<std::vector<int>> p_share_vec = make_shared_vector();

	//fill_vector(p_vec);
	//fill_vector(p_share_vec);
	//delete p_vec;
	//p_vec = NULL;

	// 12.8
	/* return pointer for bool, error */

	// 12.9
	/* old r will cause memoty leakage */
	/* old r2 will be released automatically */

	// 12.10
	/* Correct */

	// 12.11
	/* An error was generated at run time: double free prossibility cause corruption */

	// 12.12
	/*
		a. correct
		b. illegal, plant pointer can't convert to shared_ptr implicity 
		c. illegal, plant pointer can't convert to shared_ptr implicity
		d. runtime error
	*/

	// 12.13
	/* Runtime error, double free */

	// 12.14
	ex_12_14();

}

void cp12_loop(void) {
	cout << "Welcom to cp12" << endl;

	ex12_1();
}