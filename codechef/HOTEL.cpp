#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n, tmp;
	
	cin >> t;
	while (t--) {
		cin >> n;

		vector<int> cnt(1050, 0);
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			++cnt[tmp];
		}

		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			--cnt[tmp];
		}

		int m = 0;
		int rc = 0;
		for (int i = 1; i < 1050; ++i) {
			rc += cnt[i];
			m = max(m, rc);
		}

		cout << m << endl;
	}

	return 0;
}
