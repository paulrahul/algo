#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	int t, n, m;
	int p[20000][2];
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		for (int i = 0; i < m; ++i) {
			cin >> p[i][0] >> p[i][1];
		}
	
		// start from the bottom and keep adding to
		// final answer vector if all the pair elements
		// have not been used so far.
		set<int> used;
		vector<int> ans;
		for (int i = m - 1; i >= 0; --i) {
			if (used.find(p[i][0]) != used.end()) continue;
			if (used.find(p[i][1]) != used.end()) continue;

			ans.push_back(i);
			used.insert(p[i][0]);
			used.insert(p[i][1]);
		}
		
		for (int i = ans.size() - 1; i > 0; --i) {
			cout << ans[i] << " ";
		}
		cout << ans[0] << endl;
	}

	return 0;
}