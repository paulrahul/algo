// Program to remove repeating adjacent characters from a string.
//
// E.g.:
// abcde -> abcde (no continuous repeating character)
// abcdea -> abcdea (no continuous repeating character)
// abbc -> ac
// abbcb -> acb
// abba -> ""
// abccbba -> ""
// bbacdddcf -> af
// aaaaa -> ""

#include <iostream>
#include <string>

using namespace std;

string collapse(string str, int idx) {
	int len = str.length();
	if (idx >= len) {
		return "";
	}

	int begin_idx = idx;
	int count = 0;
	char ch = str[idx];
	while (idx < len && str[idx] == ch) {
		++idx;
		++count;
	}

	if (count > 1) {
		// Current index character is repeating.
		// So we ignore it and process the rest of the string.
		if (begin_idx == 0) {
			// Everything to the left is discarded. So process the
			// right part.
			return collapse(str.substr(idx), 0);
		} else {
			return str.substr(idx);
		}
	}

	// Current character does not repeat. Get the collapsed part
	// of the rest of the string to the right and re-check.
	string rem = collapse(str, idx);
	if (rem.length() == 0 || rem[0] != ch) {
		// No more collapse possible.
		return ch + rem;
	}

	idx = 0;
	len = rem.length();
	while (idx < len && rem[idx] == ch) {
		++idx;
	}

	if (begin_idx == 0) {
		return collapse(rem.substr(idx), 0);
	} else {
		return rem.substr(idx);
	}

	return "";
}

int main() {
	string str;

	while (cin >> str) {
		cout << str << " -> " << collapse(str, 0) << endl;
	}
	
	return 0;
}

