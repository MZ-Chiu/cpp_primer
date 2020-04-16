#include "cp6.hpp"
#include <vector>
#include <initializer_list>

using std::vector;

static int fact(int n) {
	int ret = 1;

	while (n > 1) {
		ret *= n--;
	}
	return ret;
}

static double square(double x) {
	return x * x;
}

static double myabs(double x) {
	return x > 0 ? x : -x;
}

static void exercise_6_1(void) {
	int n = 0;

	cout << "Enter a num to caculate factorial" << endl;
	cin >> n;
	cout << n << "!=" << fact(n) << endl;

	double x = 0.0;
	cout << "Enter a num to caculate abs" << endl;
	cin >> x;
	cout << x << "'s abs = " << myabs(x) << endl;

	//cout << "2.5^2=" << square(2.5) << endl;
}

static void my_swap(int &a, int &b) {
	int tmp = b;

	b = a;
	a = tmp;
}

//static void foo(int) {
//	;
//}

static void change_val(int a, vector<int>::iterator b, vector<int>::iterator e) {
	for ( ; b != e; ++b) {
		*b = a;
	}
}

static int compare(int a, const int *b) {
	return a > *b ? a : *b;
}

static void swap_pointer(int *&a, int *&b) {
	int *tmp = a;

	a = b;
	b = tmp;
}

//static void my_printf(int(&arr)[10]) {
//	for (auto i : arr) {
//		cout << i << " ";
//	}
//}

static void my_printf(const int arr[10]) {
	for (size_t i = 0; i != 10; i++)
	{
		cout << arr[i] << " ";
	}
}

static void sum_elem(std::initializer_list<int> lst) {
	int sum = 0;
	for (auto i : lst) {
		sum += i;
	}
	cout << "sum int: " << sum << endl;
}

static void sum_string(std::initializer_list<string> lst) {
	string sum;
	for (auto s : lst) {
		sum = sum + s + " ";
	}
	cout << "sum string: " << sum << endl;
}

static bool str_subrange(const string &str1, const string &str2) {
	if (str1.size() == str2.size())
	{
		return str1 == str2;
	}

	auto size = str1.size() <= str2.size() ? str1.size() : str2.size();
	for (decltype(size) i = 0; i < size; ++i)
	{
		if (str1[i] != str2[i]) {
			return false;
		}
	}
	return true;
}
static void factorial_int(vector<int> ivec) {
	if (ivec.size() > 0) {
		cout << "ivec size = " << ivec.size() << endl;
		ivec.pop_back();
		factorial_int(ivec);
	}
	return;
 }

static void exercise_6_2(void) {
	//int x = 1, y = 2;
	//my_swap(x, y);
	//cout << "x = " << x << ", y = " << y << endl;

	//vector<int> a = { 1, 2, 3, 4, 5, 6 };
	//change_val(1, a.begin(), a.end());
	//for (auto i : a)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;

	//int a = 1, b = 2;
	//int c = compare(a, &b);
	//cout << c << endl;

	//int *pa = &a;
	//int *pb = &b;

	//cout << *pa << " " << *pb << endl;
	//swap_pointer(pa, pb);
	//cout << *pa << " " << *pb << endl;

	//int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	//my_printf(a);

	//sum_elem({ a[0], a[1], a[2] });
	//sum_string({ "Hello", "initiliazer", "list"});

	//if (str_subrange("string1", "strin")) {
	//	cout << "Is subtring" << endl;
	//}
	//else {
	//	cout << "Not subtring" << endl;
	//}

	vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7 };
	factorial_int(ivec);
}

//typedef string str_arrT[3];
using str_arrT = string[3];
using int_arrT = int[3];

string s_arr1[] = { "str1", "str2", "str3" };
string s_arr2[] = { "str4", "str5", "str6" };

int i_odd[] = { 1, 3, 5 };
int i_even[] = { 2, 3, 4 };

static string (*string_pointer()) [3]{
		return &s_arr1;
}

static str_arrT *string_pointer1()
{
	return &s_arr2;
}

static int_arrT &int_arr_reference() {
	//return i_odd;
	return i_even;
}

static void exercise_6_3() {
	string (*p_s_arr)[3] = string_pointer();
	for (auto s : *p_s_arr) {
		cout << s << endl;
	}

	str_arrT *p = string_pointer1();
	for (auto s : *p) {
		cout << s << endl;
	}

	int_arrT &ip = int_arr_reference();
	for (auto i : ip) {
		cout << i << endl;
	}
}

int foo1(int a, int b) {
	return a + b;
}

int foo2(int a, int b) {
	return a - b;
}

int foo3(int a, int b) {
	return a * b;
}

int foo4(int a, int b) {
	return a / b;
}

typedef decltype(foo1) *pf;

void exercise_6_7(void) {
	vector<pf> pf_vec = { foo1, foo2, foo3, foo4 };

	for (auto i : pf_vec) {
		cout << i(8, 2) << endl;
	}
}

void cp6_loop(void) {
	cout << "Welcom to cp6" << endl;

	//exercise_6_1();
	 
	//exercise_6_2();

	//exercise_6_3();

	exercise_6_7();
}
