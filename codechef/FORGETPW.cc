#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	
	map<char, char> m;
	char c, p;
	string estr;
	while (t--) {
		cin >> n;
		
		m.clear();
		for (int i = 0; i < n; ++i) {
			cin >> c >> p;
			m[c] = p;
		}
		
		cin >> estr;
		int l = estr.length();
		
		// Replace all characters in estr.
		int dot_idx = -1;
		for (int i = 0; i < l; ++i) {
			if (m.find(estr[i]) != m.end()) {
				estr[i] = m[estr[i]];
			}
			
			if (estr[i] == '.') {
				dot_idx = i;
			}
		}

		vector<bool> f(l, true);
		int discarded = 0;
		// Strip leading and trailing zeroes.
		for (int i = 0; i < l && estr[i] == '0'; ++i) {
			f[i] = false;
			++discarded;
		}
		
		if (dot_idx >= 0) {
			for (int i = l - 1; i >= 0 && estr[i] == '0' && f[i]; --i) {
				f[i] = false;
				++discarded;
			}			
		}
		
		// If the decimal part is zero, discard it.
		bool dec_stripped = false;
		if (dot_idx >= 0 && (dot_idx == l - 1 || !f[dot_idx + 1])) {
			f[dot_idx] = false;
			dec_stripped = true;
			++discarded;
		}


		if (discarded == l) {
			cout << "0";
		} else {
			for (int i = 0; i < l; ++i) {
				if (f[i]) {
					cout << estr[i];
				}
			}			
		}

		cout << endl;
	}
	
	return 0;
}