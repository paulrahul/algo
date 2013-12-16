// Codechef December 2013 Long: RECTQUER
// DP, sub matrix calculations. Well solved! :D

#include <iostream>
#include <vector>

using namespace std;

int main () {
	int n;
	cin >> n;

	int tmp;	
	vector<vector<char> > inp(n + 1, vector<char>(n + 1, '0'));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> tmp;
			inp[i][j] = '0' + (tmp - 1);
		}
	}

	vector<vector<vector<int> > >
		arr(n + 1, vector<vector<int> >(n + 1, vector<int>(11, 0)));

	// O(N^2) -- unavoidable.
	// First row.
	for (int j = 1; j <= n; ++j) {
		for (int k = 1; k <= 10; ++k) {
			arr[1][j][k] = arr[1][j - 1][k];
		}
		++arr[1][j][1 + (inp[1][j] - '0')];	
	}

	// First col.
	for (int i = 2; i <= n; ++i) {
		for (int k = 1; k <= 10; ++k) {
			arr[i][1][k] = arr[i - 1][1][k];
		}
		++arr[i][1][1 + (inp[i][1] - '0')];	
	}

	// The non-border cells.
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			for (int k = 1; k <= 10; ++k) {
				arr[i][j][k] =
				arr[i - 1][j][k] + arr[i][j - 1][k] - arr[i - 1][j - 1][k];
			}
			++arr[i][j][1 + (inp[i][j] - '0')];
		}
	}

	int q;
	int x1, y1, x2, y2;

	cin >> q;
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2;	

		int ans = 0;
		if (x1 == x2 && y1 == y2) {
			// Just one cell. At least one character is there.
			//cout << i << " " << j << " " << k << " " << l << endl;
			ans = 1;
		} else {
			for (int x = 1; x <= 10; ++x) {
				int t1 = arr[x2][y2][x];
				int t2 = arr[x1 - 1][y2][x]
						 + arr[x2][y1 - 1][x]
						 - arr[x1 - 1][y1 - 1][x];
				// if (i == 1 && j == 1 && k == 2 && l == 3) {
				// cout << x << " " << t1 << " " << t2 << endl;	
				// }	
				if (t1 > t2) {
					++ans;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}