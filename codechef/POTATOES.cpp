#include <iostream>
#include <vector>

using namespace std;

void GetPrimes(vector<int>* ret) {
	vector<bool> is_prime(3000, true);

	for (int i = 2; i <= 60; ++i) {
		if (is_prime[i]) {
			for (int j = i * i; j <= 3000; j += i) {
				is_prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= 3000; ++i) {
		if (is_prime[i]) {
			ret->push_back(i);
			if (i > 2000) {
				break;
			}
		}
	}
}

int main() {
	vector<int> primes;
	GetPrimes(&primes);
	int len = primes.size();

	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int done = a + b;
		
		int ans = -1;
		for (int i = 0; i < len && ans <= 0; ++i) {
			ans = primes[i] - done;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}