#include <iostream>

using namespace std;

int main() {
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
	
		int arr[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				arr[i][j] = 0;
				if (i == 0 && j == 0) {
					arr[i][j] = 1;
					continue;
				}
				
				if (i > 0) arr[i][j] += arr[i - 1][j];
				if (j > 0) arr[i][j] += arr[i][j - 1];				
			}
		}
		
		int ans = 0;
		if (k < arr[n - 1][m - 1]) {
			ans = 1;
		} else {
			ans = 1  + (k - arr[n - 1][m - 1]); 
		}
		
		cout << ans << endl;
	}
	
	return 0;
}