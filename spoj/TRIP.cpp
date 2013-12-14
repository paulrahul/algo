#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string a, b;
char* path;
vector<string> ans;
int idx;

void create_path(const vector<vector<vector<int> > >& p, int i, int j, int mx) {
	if (p[i][j].size() == 0) {
		return;
	}
	
	for (int k = 0; k < p[i][j].size(); ++k) {
		if (p[i][j][k] == 0) {
			create_path(p, i - 1, j, mx);
		}
		
		if (p[i][j][k] == 1) {
			create_path(p, i, j - 1, mx);
		}
		
		if (p[i][j][k] == 2) {
			create_path(p, i - 1, j - 1, mx);
		}
	}
}

int main() {
	int t;
	
	cin >> t;
	while (t--) {
		cin >> a >> b;
		
		int m = a.length();
		int n = b.length();
		
		vector<vector<int> > arr(m + 1, vector<int>(n + 1, 0));
		vector<vector<vector<int> > > p(m + 1, vector<vector<int> >(n + 1, vector<int>()));  // 0 - left, 1 - right, 2 - up
		
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				int m1 = arr[i - 1][j];
				int m2 = arr[i][j - 1];
				int m3 = (a[i] == b[j]) ? 1 + arr[i - 1][j - 1] : 0;
				
				int mx = max(m1, m2);
				mx = max(mx, m3);
				arr[i][j] = mx;
				
				if (m1 == mx) {
					p[i][j].push_back(0);
				}
				if (m2 == mx) {
					p[i][j].push_back(1);
				}
				if (m3 == mx) {
					p[i][j].push_back(2);
				}							
			}
		}
		
		cout << arr[m][n] << endl;
	}

	return 0;
}