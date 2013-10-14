#include <iostream>

using namespace std;

int main() {
	int t, n;
	int orig[60];
	int nu[60];
	int a[60];
	int e[60];
	int prev_e;

	cin >> t;
	while (t--) {
		cin >> n;
		
		for (int i = 0; i < n; ++i) {
			cin >> orig[i];
		}

		for (int i = 0; i < n; ++i) {
			cin >> nu[i];
		}

		if (n == 1) {
			if (nu[0] > orig[0]) {
				cout << "-1" << endl;
			} else {
				cout << (orig[0] - nu[0]) << endl;	
			}
			continue;
		} else if (n == 2) {
			e[0] = nu[0] - orig[0];
			e[1] = nu[1] - orig[1];

			if (e[0] != -1 * e[1]) {
				cout << "-1" << endl;
			} else {
				int ans = (e[0] > e[1]) ? e[0] : e[1];
				cout << ans << endl;
			}
			continue;				
		} else {
			prev_e = 0;
			for (int i = 0; i < n; ++i) {
				e[i] = nu[i] - orig[i];
				prev_e += e[i];
			}
	
			if (prev_e % (n - 2) == 0) {
				prev_e /= n - 2;
			} else {
				cout << "-1" << endl;
				continue;			
			}

			int sum = 0;
			int total = prev_e;
			for (int i = n - 1; i > 0; --i) {
				if ((prev_e + e[i] - sum) % 2 != 0) {
					sum = -1;
					break;					
				}
				a[i] = prev_e - ((prev_e + e[i] - sum) / 2);
				if (a[i] < 0) {
					sum = -1;
					break;
				}

				sum += a[i];
				prev_e = total - sum;
			}
			if (sum == -1 || prev_e < 0 ) {
				sum = -1;
			} else {
				sum += prev_e;
			}

			cout << sum << endl;
		}
	}

	return 0;
}
