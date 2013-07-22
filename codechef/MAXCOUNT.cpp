#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> first_index(101, -1);

bool compare_ans(int a, int b) {
	return (first_index[a] < first_index[b]);
}

int main(int argc, char** argv) {
	int t, n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> counts(101, 0);
		map<int, set<int> > cnt_map;
		
		int tmp;
		int max_count = 0;
		int c;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			c = ++counts[tmp];
			
			if (c > 1) {
				// remove from previous bucket
				cnt_map[c - 1].erase(tmp);
			} else {
				first_index[tmp] = i;
			}
			
			cnt_map[c].insert(tmp);
			
			max_count = max(max_count, count);
		}
		
		// go to the bucket having max_count, and output the lowest set element.
		vector<int> ans(cnt_map[max_count].begin(), cnt_map[max_count].end());
		sort(
	}

	return 0;
}