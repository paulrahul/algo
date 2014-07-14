#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct t {
	int v;
	int idx;
};

bool compare_t(const t& a, const t& b) {
	return a.v < b.v;
}

int main() {
	int n, k, p;
	
	cin >> n >> k >> p;

    vector<t> arr(n, t());
	for(int i = 0; i < n; ++i) {
		cin >> arr[i].v;
		arr[i].idx = i + 1;
	}

	sort(arr.begin(), arr.end(), &compare_t);
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		m[arr[i].idx] = i;
	}
	
	vector<int> hcount(n, 0);
	for (int i = 1; i < n; ++i) {
		hcount[i] = hcount[i - 1];
		if (arr[i].v - arr[i - 1].v > k) {
			++hcount[i];
		} 
	}

	int s, e;
	for (int i = 0; i < p; ++i) {
		cin >> s >> e;
		
		int start = m[s];
		int end = m[e];
		
		if (start > end) {
			int tmp = start;
			start = end;
			end = tmp;
		}
		
		if (hcount[end] > hcount[start]) {
			cout << "No";
		} else {
			cout << "Yes";
		}

		cout << endl;
	}
	
	return 0;
}