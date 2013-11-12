#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int> >& m, int i, int j,
		 vector<vector<int> >* c) {
	c->at(i)[j] = 1;  // Gray

	int dim = m.size();
	// Try all 8 neighbours which are yet not visited.
	// North
	if (i > 0 && m[i - 1][j] == 1 && c->at(i - 1)[j] == 0) {
		dfs(m, i - 1, j, c);
	}
	// North-East
	if (i > 0 && j < dim - 1 &&
		m[i - 1][j + 1] == 1 && c->at(i - 1)[j + 1] == 0) {
		dfs(m, i - 1, j + 1, c);
	}
	// East
	if (j < dim - 1 && m[i][j + 1] == 1 && c->at(i)[j + 1] == 0) {
		dfs(m, i, j + 1, c);
	}
	// South-East
	if (i < dim - 1 && j < dim - 1 &&
		m[i + 1][j + 1] == 1 && c->at(i + 1)[j + 1] == 0) {
		dfs(m, i + 1, j + 1, c);
	}
	// South
	if (i < dim - 1 && m[i + 1][j] == 1 && c->at(i + 1)[j] == 0) {
		dfs(m, i + 1, j, c);
	}
	// South-West
	if (i < dim - 1 && j > 0 &&
		m[i + 1][j - 1] == 1 && c->at(i + 1)[j - 1] == 0) {
		dfs(m, i + 1, j - 1, c);
	}
	// West
	if (j > 0 && m[i][j - 1] == 1 && c->at(i)[j - 1] == 0) {
		dfs(m, i, j - 1, c);
	}
	// North-West
	if (i > 0 && j > 0 && m[i - 1][j - 1] == 1 && c->at(i - 1)[j - 1] == 0) {
		dfs(m, i - 1, j - 1, c);
	}	
	
	c->at(i)[j] = 2;  // Black
}
	

int main() {
	int t, n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int> > m(n, vector<int>(n, 0));
		vector<vector<int> > c(n, vector<int>(n, 0));
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> m[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (m[i][j] == 1 && c[i][j] == 0) {
					++ans;
					dfs(m, i, j, &c);
				}
			}
		}
		
		cout << ans << endl;
		
	}
	
	return 0;
}