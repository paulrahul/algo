#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	bool arr[10001];
	int primes[1500];
	int lim = 10000 / 2;
	arr[0] = arr[1] = true; //non-prime
	for (int i = 2; i <= lim; ++i) {
		int p = i * 2;
		while (p <= 10000) {
			arr[p] = true; // non-prime
			p += i;
		}
	}

	int p = 0;
	for (int i = 2; i < 10001; ++i) {
		if (!arr[i]) {
			primes[p++] = i;
		}
	}
	
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		
		int ret = 0;		
		for (int i = 0; i < p && primes[i] < n; ++i) {
			int a = primes[i];
			int b = n - a;
			
			if ((b & 1) == 0 && !arr[b/2]) {
				//cout << a << " " << b/2 << endl;
				ret++;
			}
		}
		
		cout << ret << endl;
	}
	
	return 0;
}