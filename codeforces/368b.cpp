// Simple iteration. O(N)

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n, 0);
	vector<int> ans(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	set<int> u;
	for (int i = n - 1; i >= 0; --i) {
		u.insert(arr[i]);
		ans[i] = u.size();
	}
	
	int t;
	for (int i = 0; i < m; ++i) {
		cin >> t;
		cout << ans[t - 1] << endl;
	}
	
	return 0;
}