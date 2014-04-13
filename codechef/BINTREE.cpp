#include <iostream>
#include <set>
#include <cmath>

using namespace std;

void FindParents(int x, set<int>* parents) {
	while (x) {
		parents->insert(x);
		x /= 2;
	}
}

int FindDistance(int p, int c) {
	return (int)log2(c) - (int)log2(p);
}

int main() {
	int n, i, j;

	cin >> n;
	while (n--) {
		cin >> i >> j;

		set<int> parents;
		int l = i < j ? i : j;
		int h = i > j ? i : j;

		FindParents(l, &parents);
		int p = h;
		while (parents.find(p) == parents.end()) {
			p /= 2;
		}
		
		int ans = FindDistance(p, l) + FindDistance(p, h);
		cout << ans << endl;
	}
	
	return 0;
}