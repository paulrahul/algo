#include <iostream>

using namespace std;

int main() {
	int nt;
	int m, n;
	char arr[60][60];
	int l[60][60];
	int t[60][60];
	int r[60][60];
	int b[60][60];
	
	cin >> nt;
	while (nt--) {
		cin >> m >> n;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j];
				
				if (i == 0) {
					t[i][j] = 0;
				} else {
					if (arr[i - 1][j] == '^') {
						t[i][j] = t[i - 1][j] + 1;
					} else {
						t[i][j] = 0;
					}
				}
				
				if (j == 0) {
					l[i][j] = 0;
				} else {
					if (arr[i][j - 1] == '^') {
						l[i][j] = l[i][j - 1] + 1;
					} else {
						l[i][j] = 0;
					}
				} 
			}
		}
		
		int ans = 0;
		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (i == m - 1) {
					b[i][j] = 0;
				} else {
					if (arr[i + 1][j] == '^') {
						b[i][j] = b[i + 1][j] + 1;
					} else {
						b[i][j] = 0;
					}
				}
				
				if (j == n - 1) {
					r[i][j] = 0;
				} else {
					if (arr[i][j + 1] == '^') {
						r[i][j] = r[i][j + 1] + 1;
					} else {
						r[i][j] = 0;
					}
				}
				
				if (arr[i][j] == '^' && l[i][j] >= 2 && r[i][j] >=2 &&
					t[i][j] >= 2 && b[i][j] >= 2) {
					++ans;
				}
			}			
		}
		
		cout << ans << endl;
	}

	return 0;
}