// Simple math. O(NlogN)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, d, m;
	
	cin >> n >> d;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	int ans = 0;
	int lim = (m > n) ? n : m;
	for (int i = 0; i < lim; ++i) {
		ans += arr[i];
	}
	ans -= ((m - lim) * d);
	
	cout << ans << endl;
	
	return 0;
}