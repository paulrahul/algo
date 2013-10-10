#include <iostream>
#include <string>

using namespace std;

int main() {
	int c;
	string str;

	cin >> c;
	while (c != 0) {
		cin >> str;

		int len = str.length();
		char ans[len + 1];

		int r = len / c;
		for (int x = 0; x < r; ++x) {
			if (x & 1) {
				for (int y = 0; y < c; ++y) {
					ans[x + y * r] = str[x * c + (c - y) - 1];
				}			
			} else {
				for (int y = 0; y < c; ++y) {
					ans[x + y * r] = str[x * c + y];
				}
			}
		}
		ans[len] = '\0';
		cout << ans << endl;

		cin >> c;
	}

	return 0;
}
