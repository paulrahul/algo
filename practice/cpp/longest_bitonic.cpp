// Find the longest bitonic sequence (Increasing and then decreasing)
//
// Sample input:
// 
// 3
// 8
// 1 11 2 10 4 5 2 1
// 6
// 12 11 40 5 3 1
// 6
// 80 60 30 40 20 10
//
// Sample output:
// 6
// 5
// 5

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	
	while (t--) {
		cin >> n;
		vector<int> arr(n, 0);
		vector<int> l(n, 1);
		vector<int> r(n, 1);
		vector<int> lp(n, -1);
		vector<int> rp(n, -1);
		
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		l[0] = 1;
		r[n - 1] = 1;
		
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (arr[j] <= arr[i] && l[j] + 1 > l[i]) {
					l[i] = l[j] + 1;
					lp[i] = j;
				}
			}
		}
		
		for (int i = n - 2; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				if (arr[j] <= arr[i] && r[j] + 1 > r[i]) {
					r[i] = r[j] + 1;
					rp[i] = j;
				}
			}
		}
		
		// for (int i = 0; i < n; ++i) {
		// 	cout << lp[i] << " ";
		// }
		// cout << endl;
		// for (int i = 0; i < n; ++i) {
		// 	cout << rp[i] << " ";
		// }		
		// cout << endl;
		
		int ans = 0;
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			int c = l[i] + r[i] - 1;
			if (c > mx) {
				mx = c;
				ans = i;
			}
		}
		// cout << ans << " " << mx << endl;
		
		int idx = ans;
		vector<int> path;
		while (idx >= 0) {
			path.push_back(arr[idx]);
			idx = lp[idx];
		}
		for (int i = path.size() - 1; i >= 0; --i) {
			cout << path[i] << " ";
		}
		idx = rp[ans];
		while (idx >= 0 && idx < n) {
			cout << arr[idx] << " ";
			idx = rp[idx];
		}
		
		cout << endl;
	}

	return 0;
}