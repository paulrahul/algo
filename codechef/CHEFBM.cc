#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m, p;
	cin >> n >> m >> p;
	
	int r, c;
	map<int, map<int, int> > mods;
	for (int i = 0; i < p; ++i) {
		cin >> r >> c;
		
		if (mods[r].find(c) == mods[r].end()) {
			mods[r][c] = c;
		}
		++mods[r][c];
	}
	
	for (int r = 1; r <= n; ++r) {
		if (mods.find(r) == mods.end()) {
			cout << (m - 1) << endl;
		} else {
			map<int, int>::iterator iter = mods[r].begin();
			int ans = m - 1;
			for (; iter != mods[r].end(); ++iter) {
				int i = iter->first;

				int rgt = -1;
				if (i == m) {
					rgt = iter->second;
				} else if (mods[r].find(i + 1) == mods[r].end()) {
					rgt = i + 1;
					ans += (rgt - iter->second - 1);
				} else {
					rgt = mods[r][i + 1];
					ans += (rgt - iter->second - 1);
				}

				int lft = -1;
				if (i == 1) {
					lft = iter->second;
				} else if (mods[r].find(i - 1) == mods[r].end()) {
					lft = i - 1;
					ans += (iter->second - lft - 1);
				} else {
					lft = mods[r][i - 1];
				}

				if (iter->second > rgt || lft > iter->second) {
					ans = -1;
					break;
				}
			}
			
			cout << ans << endl;
		}
	}
	
	return 0;
}