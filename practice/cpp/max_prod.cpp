// Given a rod of length N, find the maximum product
// of sub-lengths it can be broken down to.
//
// E.g. 5 can be broken down to 2,2,1 or 3,2 but the second
// division has a higher product (3 * 2). Similarly, for N = 10,
// the max product is 36 (2 * 2 * 3 * 3)
//
// Input format: N in each line.
// Output format: Answer for N in each line.
//
// E.g.
// 5
// 10
// 20
//
// Output:
// 6
// 36
// 1458

#include <iostream>
#include <vector>

using namespace std;

void print_path(const vector<int>& p, int idx) {
//	cout << idx << " = " << p[idx] << endl;

	if (idx == 0) {
		return;
	}

	if (p[idx] == idx) {
		cout << idx << ", ";
		return;
	}

	print_path(p, p[idx]);
	print_path(p, idx - p[idx]);
}


int main() {
	int n;

	while (cin >> n) {
		vector<int> m(n + 1, 0);
		vector<int> p(n + 1, 0);

		m[1] = 1;
		p[1] = 1;

		for (int i = 2; i <= n; ++i) {
			m[i] = i;
			p[i] = i;
			for (int j = 1; j < i; ++j) {
				if (m[j] * m[i - j] > m[i]) {
					m[i] = m[j] * m[i - j];
					p[i] = j;
				}
			}
		}

		cout << n << " " << m[n] << endl;
		print_path(p, n);
		cout << endl;
	}

	return 0;
}
