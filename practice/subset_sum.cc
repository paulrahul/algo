#include <iostream>
#include <vector>

using namespace std;

int main() {
	int sum;
	int n;
	
	while (cin >> sum >> n) {
		vector<int> arr(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		
		// DP[i][val] holds true if val can be achieved by a sum
		// of a subset of numbers in [0, i] indexes.
		vector<vector<bool> > dp(sum + 1, vector<bool>(n + 1, false));
		
		int start_val = arr[1];
		dp[start_val][1] = true;  // The lowest number entered can be created with subset [0,0]
		for (int i = 2; i <= n; ++i) {
			for (int val = start_val; val <= sum; ++val) {
				if (arr[i] == val) {
					dp[val][i] = true;
					continue;
				}
				
				for (int j = 1; j < i; ++j) {
					if (dp[val][j] ||
					    (val > arr[i] && dp[val - arr[i]][j])) {
						dp[val][i] = true;
						break;
					} 
				}
			    // cout << "dp[" << val << "][" << i << "] = " << dp[val][i] << endl;
			}
		}
		
		cout << dp[sum][n] << endl;
		
	}
	
	return 0;
}