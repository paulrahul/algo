#include <iostream>

using namespace std;

int main() {
	int t, n;
	int needed, c;

	cin >> t;
	while (t--) {
		cin >> n >> c;
		
		needed = 0;
		int j;
		for (int i = 0; i < n; ++i) {
			cin >> j;
			needed += j;
		}
		
		if (needed > c) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}

	return 0;
}