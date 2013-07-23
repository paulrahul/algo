/*
 ID: paul.ra1
 LANG: C++
 TASK: subset
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream cin("subset.in");
	ofstream cout("subset.out");

	int n;
	cin >> n;

	int s = (n * (n + 1)) / 2;

	if (s & 1) {
		// An odd sum can never be divided equally.
		cout << "0" << endl;
		return 0;
	}

	int half_s = s / 2;
	int p[n + 1][s + 1];

	for (int i = 1; i <= s; ++i) {
		p[1][i] = 0;
	}
	p[1][1] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= s; ++j) {
			p[i][j] = p[i - 1][j] + ((j - i >= 1) ? p[i - 1][j - i] : 0);
		}
	}

	cout << p[n][half_s] << endl;

	return 0;
}
