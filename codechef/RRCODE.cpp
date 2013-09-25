#include <iostream>

using namespace std;

int main() {
	int t, n, k, a;
	int arr[2000];
	string op;

	cin >> t;
	while (t--) {
		cin >> n >> k >> a;

		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cin >> op;

		if (k == 0) {
			cout << a << endl;
			continue;
		}

		long long ans = arr[0];
		if (op == "AND") {
			for (int i = 1; i < n; ++i) {
				ans &= arr[i];
			}

			ans &= a;
		} else if (op == "OR") {
			for (int i = 1; i < n; ++i) {
				ans |= arr[i];
			}
			ans |= a;
		} else if (op == "XOR") {
			if (k & 1) {
				for (int i = 1; i < n; ++i) {
					ans ^= arr[i];
				}
			} else {
				ans = 0;
			}
			ans ^= a;
		}

		cout << ans << endl;

	}

	return 0;
}
