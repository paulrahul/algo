#include <iostream>

using namespace std;

int main() {
	int t, n, k;
	int tmp;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			if (tmp % 2 == 0) {
				++cnt;
			}
		}
		
		if (k == 0 && cnt == n) {
			cout << "NO";  // can't create any segment having 0 even numbers.
		} else if (cnt >= k) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		
		cout << endl;
	}
	
	return 0;
}