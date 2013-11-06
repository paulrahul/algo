#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	int n, k;
	while (t--) {
		cin >> n;
		
		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cin >> k;
		int u = arr[k - 1];

		sort(arr.begin(), arr.end());

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i] == u) {
				ans = i + 1;
				break;
			}
		}

		cout << ans << endl;
	}


	return 0;
}
