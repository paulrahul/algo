#include <iostream>

using namespace std;

double mypow(int a, int n) {
	if (n == 0) return 1;
	if (n == 1) return a;

	double t = mypow(a, n / 2);
	return t * t * mypow(a, n % 2);
}

int main() {
	cout << mypow(3, 2) << endl;
	cout << mypow(3, 100) << endl;

	return 0;
}
