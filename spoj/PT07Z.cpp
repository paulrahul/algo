#include <iostream>
#include <vector>

using namespace std;

struct node {
	vector<int> c;
};

int ans = 0;

int lpath(const vector<node>& t, int idx) {
	const node& curr = t[idx];
	int mx = 0;
	int nmx = 0;

	int sz = curr.c.size();
	for (int i = 0; i < sz; ++i) {
		int tmp = 1 + lpath(t, curr.c[i]);

		if (tmp > mx) {
			nmx = mx;
			mx = tmp;
		} else if (tmp > nmx) {
			nmx = tmp;
		}
	}

	ans = max(ans, mx + nmx);
	// cout << ans << endl;

	return mx;
}

int main() {
	int n, u, v;
	
	cin >> n;
	vector<node> t(n + 1, node());

	for (int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		t[u].c.push_back(v);
	}

	lpath(t, 1);
	cout << ans << endl;

	return 0;
}
