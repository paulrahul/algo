#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	string str;
	cin >> str;
	
	vector<int> a(n + 1, 0);
	vector<vector<int> > d(n + 1, vector<int>(10, 0));
	int tmp = 0;
	for (int i = 1; i <= n; ++i) {
		tmp = str[i - 1] - '0';
		a[i] = tmp;
		
		for (int j = 0; j < 10; ++j) {
			d[i][j] = d[i - 1][j];
		}
		
		++d[i][tmp];
//		cout << "d" << i << ", " << tmp << " = " << d[i][tmp] << endl;
	}

	int x;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		tmp = a[x];

		int b1 = 0;
		for (int j = 0; j < tmp; ++j) {
			int k = d[x - 1][j];
			b1 += k * (tmp - j);
//			cout << k << " " << j << " " << tmp << endl;
		}

		int b2 = 0;
		for (int j = 9; j > tmp; --j) {
			int k = d[x - 1][j];
			b2 += k * (tmp - j);
		}
		
		//cout << b1 << " " << b2 << endl;
		cout << (b1 - b2) << endl;
	}
	
	return 0;
}