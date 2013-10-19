// Some random timepass code for 0-1 knapsack problem.
// Given a few boxes and their weights and values, find
// the maximum value possible by collecting boxes whose
// total weight goes upto W.

#include <iostream>
#include <vector>
#include <algorithm>

struct box {
	int w, v;
};

bool compare_b(const box& a, const box& b) {
	return a.w < b.w;
}

using namespace std;

int main() {
	int n;

	cin >> n;
	vector<box> b(n, box());
	
	for (int i = 0; i < n; ++i) {
		cin >> b[i].w >> b[i].v;
	}

	sort(b.begin(), b.end(), &compare_b);

	int max_w;
	cin >> max_w;

	vector<vector<int> > m(n + 1, vector<int>(max_w + 1, -1));
	m[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		m[i][0] = 0;
	}

	for (int j = 1; j <= max_w; ++j) {
		for (int i = 1; i <= n; ++i) {
			int wt = b[i - 1].w;
			int vl = b[i - 1].v;

			// Max way of achieving upto weight j using i boxes.
			// Initially, we take the max of creating j - 1 weight
			// with i boxes and creating weight j with i - 1 boxes
			// as both apply to this current combination.
			m[i][j] = max(m[i - 1][j], m[i][j - 1]);

			// Then we consider the case of creating weight j by
			// including the ith box.
			if (j >= wt && m[i - 1][j - wt] >= 0) {
				m[i][j] = max(m[i][j], m[i - 1][j - wt] + vl);
			}
		}
	}

	cout << m[n][max_w] << endl;

	return 0;
}
