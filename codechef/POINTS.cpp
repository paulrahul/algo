#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct p {
	int x, y;
};

bool compare_p(const p& a, const p& b) {
	if (a.x == b.x) {
		return (a.y > b.y);
	}
	
	return (a.x < b.x);
}

int main() {
	int t;
	cin >> t;
	
	int n;
	while (t--) {
		cin >> n;
		vector<p> point;
		
		p tmp;
		for (int i = 0; i < n; ++i) {
			cin >> tmp.x >> tmp.y;
			point.push_back(tmp);
		}
	
		sort(point.begin(), point.end(), &compare_p);
		
		double dist = 0;
		for (int i = 1; i < n; ++i) {
			dist += pow(pow(point[i].x - point[i - 1].x, 2) + pow(point[i].y - point[i - 1].y, 2),
						0.5);
		}
		
		cout << fixed << setprecision(2) << dist << endl;
	}

	return 0;
}