#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define MOD 1000000007

double mymod(double a, double m) {
	double q = floor(a / m);
	return a - (m * q);
}

double mypow1(double a, int e) {
	double ret = 1;
	
	int etmp = 0;
	double tmp;
	
	while (etmp < e) {
		etmp++;
		tmp = (a * ret);
		//cout << setprecision(15) << tmp << " " << etmp << endl;
		ret = mymod(tmp, MOD);
		if (ret == 0) break;
	}

	return ret;
}

double mypow(double a, int e) {
	if (e == 0) return 1;
	
	double ret = 1;
	while (e > 0) {
		if (e % 2 == 1) {
			ret = mymod((mymod(ret, MOD) * mymod(a, MOD)), MOD);
		}
		e >>= 1;
		a = mymod((mymod(a, MOD) * mymod(a, MOD)), MOD);
	}
	
	return ret;
}

int main(int argc, char** argv) {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		
		if (k == 1) {
			if (n % 2 == 1) {
				cout << 0 << endl;
			} else {
				cout << 1 << endl;
			}
		} else if (n == 2) {
			cout << k << endl;
		} else if (n == 3) {
			cout << k * (k - 1) << endl;
		} else {
			// here n > 3 && k > 1
			double amodn = mypow1(k, n - 3);
			double bmodn = mymod((((k - 1) * (k - 1)) + k), MOD);
			double result = mymod((amodn * bmodn), MOD);
			cout << n << " " << k << " = ";
			cout << setprecision(15) << result << endl;
		}
	}

	return 0;
}