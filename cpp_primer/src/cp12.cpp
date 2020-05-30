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


void ex12_1(void) {
	// 12.1 - 12.5
	strBlob sb({ "a", "an" });
	sb.push_back("im qmz");
	sb.print();
	cout << sb.front() << " " << endl;
	cout << sb.back() << " " << endl;

	const strBlob csb({ "aa", "aan" });
	//csb.push_back("xyz");

}

void cp12_loop(void) {
	cout << "Welcom to cp12" << endl;

	ex12_1();
}