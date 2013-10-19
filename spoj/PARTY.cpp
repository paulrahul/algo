#include <iostream>
#include <vector>
#include <algorithm>

struct party {
	int fee, fun;
};

bool compare_p(const party& a, const party& b) {
	return a.fee < b.fee;
}

using namespace std;

int main() {
	int n, mf;

	cin >> mf >> n;

	while (mf != 0 || n != 0) {
		vector<party> p(n, party());

		for (int i = 0; i < n; ++i) {
			cin >> p[i].fee >> p[i].fun;
		}

		sort(p.begin(), p.end(), &compare_p);

		vector<vector<int> > m(n + 1, vector<int>(mf + 1, -1));
		vector<vector<int> > c(n + 1, vector<int>(mf + 1, -1));
		m[0][0] = 0;
		c[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			m[i][0] = c[i][0] = 0;
		}

		for (int j = 1; j <= mf; ++j) {
			for (int i = 1; i <= n; ++i) {
				int fee = p[i - 1].fee;
				int fun = p[i - 1].fun;

				if (m[i - 1][j] > m[i][j - 1]) {
					m[i][j] = m[i - 1][j];
					c[i][j] = c[i - 1][j];
				} else {
					m[i][j] = m[i][j - 1];
					c[i][j] = c[i][j - 1];
				}

				if (j >= fee && m[i - 1][j - fee] >= 0) {
					if (m[i - 1][j - fee] + fun > m[i][j]) {
						m[i][j] = m[i - 1][j - fee] + fun;
						c[i][j] = c[i - 1][j - fee] + fee;
					}
				}
			}
		}

/*		for (int j = 1; j <= mf; ++j) {
			for (int i = 1; i <= n; ++i) {
				cout << m[i][j] << " " ;
			}
			cout << endl;
		}	*/	


		cout << c[n][mf] << " " << m[n][mf] << endl;

		cin >> mf >> n;
	}


	return 0;
}
