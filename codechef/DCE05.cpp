#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	double n;
	while (t--) {
		cin >> n;
		cout << setprecision(11) << pow(2, floor(log2(n))) << endl;
	}

	return 0;
}