#include "cp6.hpp"

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

static void exrecise_6_1(void) {
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

void cp6_loop(void) {
	cout << "Welcom to cp6" << endl;

	exrecise_6_1();

}
