#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cout << "Enter limit: ";
	int n;
	cin >> n;
	
	bool isNonPrime[n + 1];
	int lim = pow(n, 0.5);
	
	isNonPrime[1] = true;
	for (int i = 2; i <= lim; ++i) {
		for (int j = i * i; j <= n; j += i) {
			isNonPrime[j] = true;
		}
	}
	
	for (int i = 2; i <= n; ++i) {
		if (!isNonPrime[i]) cout << i << " ";
	}

	return 0;
}