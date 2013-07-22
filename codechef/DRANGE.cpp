#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

#define LL long long

struct p {
	int change;
	bool type;
};

int main(int argc, char** argv) {
	int t, n, m;
	int w, x, y, z;
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		set<int> points;
		map<int, p> change;
		
		for (int i = 0; i < m; ++i) {
			cin >> w >> x >> y >> z;

			points.insert(x); points.insert(y);
			if (change.find(x) == change.end()) {
				change[x].change = 0;
			}
			change[x].change += (w == 1) ? z : -z;
			change[x].type = true;
	
			if (change.find(y) == change.end()) {
				change[y].change = 0;
			}
			change[y].change += (w == 1) ? z : -z;
			change[y].type = false;
		}
		
		vector<int> fp(points.begin(), points.end());
		sort(fp.begin(), fp.end());
		
		int last_change = -1;
		int max_elem = -1;
		int min_elem = -1;

		if (fp[0] > 1) {
			last_change = max_elem = min_elem = 1;
		}
		
		int len = p.size();
		int index;
		for (int i = 0; i < len; ++i) {
			index = fp[i];
			
			if (change[index].type) {
				// start range point.
				// check index, index - 1 for start indexes.				
				if (index > 1) {
					max_elem = max(max_elem, index - 1 + last_change);
					min_elem = min(min_elem, index - 1 + last_change);					
				}

				last_change += change[index].change;
				max_elem = max(max_elem, index - 1 + last_change);
				min_elem = min(min_elem, index - 1 + last_change);				
			} else {
				// end range point.
				// check index, index + 1 for start indexes.
				max_elem = max(max_elem, index - 1 + last_change);
				min_elem = min(min_elem, index - 1 + last_change);
				
				last_change -= change[index].change;				
				if (index < n) {
					max_elem = max(max_elem, index - 1 + last_change);
					min_elem = min(min_elem, index - 1 + last_change);					
				}			
			}
		}
		
		setprecision(20);
		cout << (max_elem - min_elem) << endl;
	}

	return 0;
}