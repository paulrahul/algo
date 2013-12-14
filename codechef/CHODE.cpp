#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> cnt(26, 0);

bool compare_c(char a, char b) {
	if (cnt[a - 'a'] == cnt[b - 'a']) {
		return a < b;
	}
	
	return cnt[a - 'a'] < cnt[b - 'a'];
}

int main() {
	int t;
	string freq, text;
	
	cin >> t;
	getline(cin, freq, '\n');  // dummy
	
	while (t--) {
		getline(cin, freq, '\n');
		getline(cin, text, '\n');		
		
		int len = text.length();
		cnt.assign(26, 0);
		
		for (int i = 0; i < len; ++i) {
			char ch = text[i];
			if (ch >= 'a' && ch <= 'z') {
				++cnt[ch - 'a'];
			} else if (ch >= 'A' && ch <= 'Z') {
				++cnt[ch - 'A'];
			}
		}

		vector<char> c(26, 'a');
		for (int i = 0; i < 26; ++i) {
			c[i] = (char) ('a' + i);
		}
		sort(c.begin(), c.end(), &compare_c);
		map<char, char> m;
		for (int i = 0; i < 26; ++i) {
			m[c[i]] = freq[i];
		}
		
		for (int i = 0; i < len; ++i) {
			char ch = text[i];
			if (ch >= 'a' && ch <= 'z') {
				cout << m[ch];
			} else if (ch >= 'A' && ch <= 'Z') {
				char tch = (char) ('a' + (ch - 'A'));
				cout << (char)('A' + (m[tch] - 'a'));
			} else {
				cout << ch;
			}
		}
		
		cout << endl;
	}
	
	return 0;
}