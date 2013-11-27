#include <iostream>
#include <map>
#include <vector>

using namespace std;

int m, n;

int dfs(const vector<vector<int> >& arr,
		vector<vector<bool> >* col,
		int r, int c, int cc) {
	if (arr[r][c] != cc) return 0;
	
	col->at(r)[c] = true;
	int ans = 1;  //counting myself.
	
	// North.
	if (r > 0 && !col->at(r - 1)[c]) {
		ans += dfs(arr, col, r - 1, c, cc);
	}

	// North-East.
	if (r > 0 && c < n - 1 && !col->at(r - 1)[c + 1]) {
		ans += dfs(arr, col, r - 1, c + 1, cc);
	}	
	
	// East.
	if (c < n - 1 && !col->at(r)[c + 1]) {
		ans += dfs(arr, col, r, c + 1, cc);
	}
	
	// South-East.
	if (r < m - 1 && c < n - 1 && !col->at(r + 1)[c + 1]) {
		ans += dfs(arr, col, r + 1, c + 1, cc);
	}	
	
	// South.
	if (r < m - 1 && !col->at(r + 1)[c]) {
		ans += dfs(arr, col, r + 1, c, cc);
	}
	
	// South-West.
	if (r < m - 1 && c > 0 && !col->at(r + 1)[c - 1]) {
		ans += dfs(arr, col, r + 1, c - 1, cc);
	}	
	
	// West.
	if (c > 0 && !col->at(r)[c - 1]) {
		ans += dfs(arr, col, r, c - 1, cc);
	}

	// North-West.
	if (r > 0 && c > 0 && !col->at(r - 1)[c - 1]) {
		ans += dfs(arr, col, r - 1, c - 1, cc);
	}
	
	return ans;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		
		vector<vector<int> > arr(m, vector<int>(n, -1));
		vector<vector<bool> > col(m, vector<bool>(n, false));		
	
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
			}
		}
		
		map<int, int> cnt_mp;
		int ans_col = -1;
		int mx = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!col[i][j]) {
					int cc = arr[i][j];
					int cnt = dfs(arr, &col, i, j, cc);
					if (cnt_mp.find(cc) == cnt_mp.end()) {
						cnt_mp[cc] = 0;
					}
					cnt_mp[cc] += cnt;
					if (cnt_mp[cc] > mx) {
						mx = cnt_mp[cc];
						ans_col = cc;
					}
				}
			}
		}
		
		cout << ans_col << " " << mx << endl;
	}
}