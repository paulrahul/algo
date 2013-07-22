#include <iostream>

using namespace std;

typedef long long int64;

#define MOD 1000000007

int mm(int64 a[][11], int64 b[][11], int64 c[][11], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (int k = 0; k < n; ++k) {
				// c[i][j] += (((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD) % MOD;
				c[i][j] += (a[i][k] * b[k][j]);
			}
			c[i][j] %= MOD;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			b[i][j] = c[i][j];
		}
	}
}

int mp(int64 c[][11], int n, int k) {
	int64 a[11][11];
	int64 b[11][11];
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			a[i][j] = (i == j) ? 0 : 1;
			b[i][j] = a[i][j];
			c[i][j] = 0;
		}
	}
	
	for (int i = 0; i < n - 1; ++i) {
		mm(a, b, c, k); 
	}
}

int main(int argc, char** argv) {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		int64 a[11][11];
		mp(a, n, k + 1);
		cout << a[0][0] << endl;
	}

	return 0;
}