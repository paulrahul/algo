#include <iostream>
#include <string>

using namespace std;

int main() {
	int t, ac, bc;
	string str;

	cin >> t;
	while (t--) {
		cin >> str;
		cin >> ac >> bc;

		int len = str.length();
		int i = 0;
		int j = len - 1;
		int ans = 0;
		int mn = (ac < bc) ? ac : bc;
		while (i <= j) {
			if (str[i] != '/' && str[j] != '/') {
				if (str[i] != str[j]) {
					ans = -1;
					break;
				}
			} else {
				if (str[i] == '/' && str[j] == '/') {
					ans += mn;
				} else {
					if (str[i] == 'a' || str[j] == 'a') {
						ans += ac;
					} else {
						ans += bc;
					}
				}  // if
			}  // if
			++i; --j;
		}  // while
		
		cout << ans << endl;
		
	}  // t

	return 0;
}
