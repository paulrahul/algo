#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	char ch;
	int d;
	int nr = 0;
	for (int i = 0; i < m; ++i) {
		cin >> ch >> d;
		
		if (ch == 'R') {
			d -= 1;
			int nrot = nr % n;
			if (nrot < 0) nrot *= -1;
			if (nr > 0) {
				if (d >= nrot) {
					cout << arr[d - nrot] << endl;
				} else {
					cout << arr [n - (nrot - d)] << endl;
				}
			} else if (nr < 0) {
				cout << arr[(d + nrot) % n] << endl;
			} else {
				cout << arr[d] << endl;
			}
		} else if (ch == 'A') {
			nr += d;
		} else if (ch == 'C') {
			nr -= d;
		}
	}
	
	return 0;
}