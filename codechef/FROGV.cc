#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct t {
	int v;
	int idx;
};

bool compare_t(const t& a, const t& b) {
	return a.v < b.v;
}

int main() {
	int n, k, p;
	
	cin >> n >> k >> p;

    vector<t> arr(n, t());
	for(int i = 0; i < n; ++i) {
		cin >> arr[i].v;
		arr[i].idx = i + 1;
	}

	sort(arr.begin(), arr.end(), &compare_t);

	vector<vector<bool> > dp(n, vector<bool>(n, false));
	vector<vector<bool> > ans(n + 1, vector<bool>(n + 1, false));	
	
	// Init
	for (int i = 0; i < n - 1; ++i) {
		ans[arr[i].idx][arr[i + 1].idx] = dp[i][i + 1] = ((arr[i + 1].v - arr[i].v) <= k);
		ans[arr[i + 1].idx][arr[i].idx] = dp[i + 1][i] = dp[i][i + 1];
		ans[i + 1][i + 1] = true;
	}
	ans[n][n] = true;

	for (int l = 2; l <= n; ++l) {
		for (int i = 0; i < n - l; ++i) {
			int j = i + l;
			for (int k = i + 1; k < j; ++k) {
				if (dp[i][k] && dp[k][j]) {
					ans[arr[i].idx][arr[j].idx] = dp[i][j] = true;
					ans[arr[j].idx][arr[i].idx] = dp[j][i] = true;
				}
			}
		}
	}

	int s, e;
	for (int i = 0; i < p; ++i) {
		cin >> s >> e;
		if (ans[s][e]) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << endl;
	}
	
	return 0;
}