#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	int n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> num(n, 0);
	
		for (int i = 0; i < n; ++i) {
			cin >> num[i];
		}
		
		int max_till_now = -1;
		long long ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			max_till_now = max(max_till_now, num[i]);
			ans += (max_till_now - num[i]);
		}
		
		cout << ans << endl;
	}

	return 0;
}