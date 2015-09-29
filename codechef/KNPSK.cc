#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int n;
	cin >> n;
	
	vector<int> w(n, 0);
	vector<int> c(n, 0);
	ll m = 0;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> c[i];
		m += w[i];
	}
	
	sort(dp.begin(), dp.end());
	
	vector<vector<ll>> dp(m, vector<ll>(n, 0));
	
	// Init.
	for (int i = 0; i < n; ++i) {
		dp[w[i]][1] = c[i];
	}
	
    for (int l = 2; l <= n; ++l) {
		for (int i = 0; i < n - l; ++i) {
			int j = i + l;
			for (int k = i + 1; k < j; ++k) {
				if (dp)
			}
		}
	}
		
	return 0;
}