#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	int n;
	string str;

	cin >> n;
	while (n--) {
		cin >> str;

		int startpos[3];
		int start = 0;
		int end = 0;
		set<char> c;
		long long int ans = 0;

		int slen = str.length();
		for (int i = 0; i < slen; ++i) {
			c.insert(str[i]);
			if (c.size() == 3) {
				// Subtract the previous overlap.
				if (ans > 0) {
					long long int l = end - start + 1;
					ans -= (l * (l + 1)) / 2;		
				}					
		
				end = i - 1;
				long long int l = end - start + 1;
				ans += (l * (l + 1)) / 2;

				// One char of the current substring goes out.
				c.erase(str[startpos[str[i - 1] - 'a'] - 1]);
				// New start will be earliest position of previous character.
				start = startpos[str[i - 1] - 'a'];
				end = i - 1;
			}

			if (i == 0 || str[i] != str[i - 1]) {
				startpos[str[i] - 'a'] = i;
			}
		}

		if (ans > 0) {
			long long int l = end - start + 1;
			ans -= (l * (l + 1)) / 2;
		}
		
		end = slen - 1;
		long long int l = end - start + 1;
		ans += (l * (l + 1)) / 2;

		cout << ans << endl;
	}

	return 0;
}
