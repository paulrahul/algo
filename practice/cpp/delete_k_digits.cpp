// Delete K digits from a given number such that the remaining number is
// the lowest possible after deleting any K digits.

#include <iostream>
#include <string>

using namespace std;

string delete_k(string num, int k, int start) {
	if (k == 0) {
		return num;
	}
	
	int len = num.length();
	
	int r = start + 1;
	bool found = false;
	while (!found) {
		// Scan from left and find the digit which is lesser than
		// previous digit.  --- O(N).
		while (r < len && num[r] >= num[r - 1]) {
			++r;
		}
	
		if (r >= len) {
			// Found none. So delete top K digits from the end and return.
			int nlen = (k > len) ? 0 : len - k;
			return num.substr(0, nlen);
		}
		
		// Now look for the first index, l, within K distance to the left of r
		// such that num[l] > num[r]
		int l = r - k;
		while (l < r && num[l] <= num[r]) {
			++l;
		}
		
		if (l < r) {
			// So num[l ... r - 1] go out.
			for (int i = l; i < r; ++i) {
				num[i] = 'x';  // Sentinel character.
				--k;
			}
			found = true;
		}
	}
	
	num = delete_k(num, k, r + 1);
	return num;
}

int main() {
	string num;
	int t, k;
	
	cin >> t;
	
	while (t--) {
		cin >> num;
		cin >> k;
		
		// cout << num << " -> ";
		string ans = delete_k(num, k, 0);
		// Ignore sentinel characters and print.
		int len = ans.length();
		for (int i = 0; i < len; ++i) {
			if (ans[i] == 'x') continue;
			cout << ans[i];
		}
		cout << endl;
	}

	return 0;
}