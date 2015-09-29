#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

struct subset {
	int parent;
	int rank;
};

struct p {
	int l;
	int r;
};

bool compare_p(const p& a, const p& b) {
	if (a.l == b.l) {
		return a.r < b.r;
	}
	return a.l < b.l;
}

int main() {
	int t, n, m;
	int l, r;
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> curr_state(n + 1, 0);
		vector<subset> ss(n + 1, subset());
		for (int i = 1; i <= n; ++i) {
			cin >> curr_state[i];
			ss[i].parent = i;
			ss[i].rank = 0;
		}
		
		vector<p> prs(m, p());
		for (int i = 0; i < m; ++i) {
			cin >> l >> r;
			
			if (l > r) {
				int tmp = l;
				l = r;
				r = tmp;
			}
			
			prs[i].l = l; prs[i].r = r;
		}
		
		sort(prs.begin(), prs.end(), compare_p);  //mlogm
		
		for (int i = prs[0].l; i <= prs[0].r; ++i) {
			ss[i].parent = prs[0].l;
		}
		for (int i = 1; i < m; ++i) {
			int parent = prs[i].l;
			if (prs[i].l <= prs[i - 1].r) {
				parent = ss[prs[i - 1].l].parent;
			}
			
			for (int j = prs[i].l; j <= prs[i].r; ++j) {
				ss[j].parent = parent;
			}
		}
		
		bool valid = true;
		for (int i = 1; i <= n; ++i) {
			int curr = i;
			int desired = curr_state[i];
			
			if (ss[curr].parent != ss[desired].parent) {
				valid = false;
				break;
			}
		}
		
		if (valid) {
			cout << "Possible";
		} else {
			cout << "Impossible";
		}
		cout << endl;
		
	}
	
	return 0;
}