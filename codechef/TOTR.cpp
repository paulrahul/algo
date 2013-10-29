#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	string m;
	cin >> m;
	
	char bmap[26];
	int l = m.length();
	for (int i = 0; i < l; ++i) {
		bmap[i] = m[i];
	}

	string tmp;
	for (int i = 0; i < t; ++i) {
		cin >> tmp;
		l = tmp.length();
		for (int i = 0; i < l; ++i) {
			if (tmp[i] >= 'a' && tmp[i] <= 'z') {
				cout << bmap[tmp[i] - 'a'];
			} else if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
				cout << (char)('A' + (bmap[tmp[i] - 'A'] - 'a'));
			} else if (tmp[i] == '_') {
				cout << ' ';
			} else {
				cout << tmp[i];
			}
		}

		cout << endl;
	}

	return 0;
}
