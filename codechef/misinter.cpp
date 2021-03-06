#include <iostream>
#include <vector>

using namespace std;

struct subset {
	subset() {
		this->parent = -1;
		this->rank = 0;
	}

	int parent;
	int rank;
};

int find(subset ss[], int c) {
	if (ss[c].parent == -1) {
		ss[c].parent = c;
		return c;
	}

	if (ss[c].parent != c) {
		ss[c].parent = find(ss, ss[c].parent);
	}

	return ss[c].parent;
}

void unite(subset ss[], int x, int y) {
	int xroot = find(ss, x);
	int yroot = find(ss, y);

	int xrank = ss[xroot].rank;
	int yrank = ss[yroot].rank;

	if (xrank < yrank) {
		ss[xroot].parent = yroot;
	} else if (yrank < xrank) {
		ss[yroot].parent = xroot;		
	} else {
		if (xroot > yroot) {
			ss[yroot].parent = xroot;
			ss[xroot].rank++;
		} else {
			ss[xroot].parent = yroot;
			ss[yroot].rank++;
		}
	}
}

int main() {
	int t, n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		//n = t;		

		subset ss[n + 1];
		int odd = n / 2 + 1;
		for (int i = 1; i <= n; ++i) {
			if (i & 1) {
				unite(ss, i, odd++);
			} else {
				unite(ss, i, i / 2);
			}
		}

		vector<bool> f(n + 1, false);
		long long int ans = 1;
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			int p = find(ss, i);
			//cout << i << ": " << p << endl;
			if (!f[p]) {
				ans = (ans * 26) % 1000000007;
				f[p] = true;
				++cnt;
			}
		}

		//cout << n << " " << ans << " " << cnt << endl;
		cout << ans << endl;
	}

	return 0;
}
