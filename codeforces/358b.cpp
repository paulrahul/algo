#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> w(n, "");
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}

	string m;
	cin >> m;

	bool valid = false;
	int i = 0;
	int len = m.length();

	char next = '<';
	int nw = 0;
	int nc = 0;
	for (int i = 0; i < len; ++i) {
		if (m[i] != next) {
			continue;
		}

		if (next == '<') {
			next = '3';
		} else if (next == '3') {
			if (nw == n) {
				valid = true;
				break;  // done with all words and loves
			}
			++nw;
			nc = 0;
			next = w[nw - 1][nc];
		} else {
			++nc;
			if (nc == w[nw - 1].length()) {  // done with current word. Some love pls.
				next = '<';
			} else {
				next = w[nw - 1][nc];
			}
		}
	}

	if (valid) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}

	return 0;
}
