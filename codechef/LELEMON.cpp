#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct room {
	room() {
		this->next = 0;
	}

	vector<int> v;
	int next;
};

int main() {
	int t, n, m, c;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		vector<int> p(m, -1);
		for (int i = 0; i < m; ++i) {
			cin >> p[i];
		}
	
		vector<room> r;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			vector<int> tv(c, 0);
			for (int j = 0; j < c; ++j) {
				cin >> tv[j];
			}
			
			room nr;
			sort(tv.begin(), tv.end(), greater<int>());
			nr.v = tv;
			r.push_back(nr);
		}
		
		int ans_v = 0;
		for (int i = 0; i < m; ++i) {
			int idx = r[p[i]].next++;
			if (idx >= r[p[i]].v.size()) continue;
			ans_v += r[p[i]].v[idx];
		}
		
		cout << ans_v << endl;
	}
	
	return 0;
}