// Given a 2D matrix where each cell has some integral color code, we define a
// color block as a group of adjacent cells where each of those cells has the
// same color code. The adjacent cells of a given cell are all all the cells to
// the eight adjacent sides of it without any wrapping (border cells will have
// lesser adjacent cells). Now, we define the area of a particular color block
// as the square of the number of cells in that block.
// 
// Given a 2D matrix, print out the color which has the maximum area of color
// blocks. Also, print out the area for that color.
//
// Sample Input:
// 1
// 5 5
// 1 2 3 4 5
// 1 1 2 2 3
// 2 3 4 5 1
// 1 2 3 4 5
// 2 1 2 1 3
//
// Sample Output:
// 2 25
//
// DFS and Hashmap. O(N^2)


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
		
		map<int, int> area_mp;
		int ans_col = -1;
		int mx = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!col[i][j]) {
					int cc = arr[i][j];
					int cnt = dfs(arr, &col, i, j, cc);
					int area = cnt * cnt;
					if (area_mp.find(cc) == area_mp.end()) {
						area_mp[cc] = 0;
					}
					area_mp[cc] += area;
					if (area_mp[cc] > mx) {
						mx = area_mp[cc];
						ans_col = cc;
					}
				}
			}
		}
		
		cout << ans_col << " " << mx << endl;
	}
}