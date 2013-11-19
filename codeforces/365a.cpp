// Codeforces Round #213 - Good Number.
// Simple math. O(N)

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int tmp;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		set<int> d;
		
		while (tmp) {
			int dg = tmp % 10;
			if (dg <= k) {
				d.insert(dg);
			}
			tmp /= 10;
		}
		
		
		if (d.size() == k + 1) {
			++ans;
		}
	}
	
	cout << ans << endl;

	return 0;
}