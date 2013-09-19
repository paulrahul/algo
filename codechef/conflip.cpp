#include <iostream>

using namespace std;

int main() {
	int i, n, q, g, t;

	cin >> t;
	while (t--) {
		cin >> g;
		for (int j = 0; j < g; ++j) {
			cin >> i >> n >> q;

			// Get the state of 1st coin after n flips.
			// Odd number of flips changes the state.
			int f = (n & 1) ? 1 + (i % 2) : i;
			
			// Now see if the odd numbered coins or the even
			// numbered coins will represent Q state.
			bool odd = (q == f);

			if (odd) {
				cout << n / 2 + n % 2 << endl;
			} else {
				cout << n / 2 << endl;
			}
		}
	}

	return 0;
}
