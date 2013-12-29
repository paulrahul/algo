#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
	int n, m, l;
	
	cin >> n >> m;
	vector<vector<int> > arr(n + 1, vector<int>(m + 1, 0));
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
		}
	}
	
	cin >> l;
	ll e1 = 0;
	ll e2 = 0;
	
	int i, j;
	for (int x = 0; x < l; ++x) {
		cin >> i >> j;
		if (e1 != -1 && i >= 1 && i <= n && j >= 1 && j <= m) {
			e1 += arr[i][j];
		} else {
			e1 = -1;
		}
		
		if (e2 != -1 && i >= 1 && i <= m && j >= 1 && j <= n) {
			e2 += arr[j][i];
		} else {
			e2 = -1;
		}	
	}
	
	cout << max(e1, e2) << endl;
	
	return 0;
}