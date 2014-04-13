#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		int ans = arr[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			ans += 1;
			if (ans < arr[i]) {
				ans = arr[i];
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}