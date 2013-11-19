// Codeforces Round #213 - Fibonacci Segment.
// Simple math. O(N)

#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	
	vector<ll> arr(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	int ans = 0;
	int l = 2;
	for (int i = 2; i < n; ++i) {
		if (arr[i] == arr[i - 1] + arr[i - 2]) {
			++l;
		} else if (l > 2) {
			ans = max(ans, l);
			l = 2;
		}
	}
	if (l > 2) {
		ans = max(ans, l);			
	}
	
	if (ans == 0) {
		ans = min(n, 2);
	}
	
	cout << ans << endl;
	
	return 0;
}