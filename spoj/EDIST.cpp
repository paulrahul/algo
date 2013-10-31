#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int t;
	string s1, s2;
	cin >> t;

	while (t--) {
		cin >> s1 >> s2;
		int n = s1.length();
		int m = s2.length();

		vector<vector<int> > edist(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; ++i) {
			edist[i][0] = i;
		}

		for (int i = 1; i <= m; ++i) {
			edist[0][i] = i;
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (s1[i - 1] == s2[j - 1]) {
					edist[i][j] = edist[i - 1][j - 1];
				} else {
					edist[i][j] = min(edist[i - 1][j], edist[i][j - 1]) + 1;
					edist[i][j] = min(edist[i][j], edist[i - 1][j - 1] + 1);
				}

				//cout << edist[i][j] << " ";
			}
			//cout << endl;
		}

		cout << edist[n][m] << endl;
	}

	return 0;
}
