#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	string str;

	cin >> t;
	while (t--) {
		cin >> str;
		int len = str.length();
		int limit = str.length() * 11;

		int cnt = 2;  // Load and print first char
		int i = 1;
		while (i < len && cnt <= limit) {
			if (str[i] >= str[i - 1]) {
				cnt += str[i] - str[i - 1];
			} else {
				cnt += 'z' - str[i - 1] + (str[i] - 'a' + 1);
			}
			++cnt; // print
			++i;
		}

		if (cnt <= limit) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}
