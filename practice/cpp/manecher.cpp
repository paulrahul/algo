#include <iostream>
#include <string>

using namespace std;

string preprocess(const string& str) {
	int len = str.length();
	if (len == 0) {
		return "";
	}


	char nstr[2 * len + 2];
	for (int i = 0; i < len; ++i) {
		nstr[i * 2] = '#';
		nstr[i * 2 + 1] = str[i];
	}
	nstr[2 * len] = '#';
	nstr[2 * len + 1] = '\0';
	return string(nstr);
}

void findPal(const string& str) {
	string t = preprocess(str);
	int len = t.length();
	if (len == 0) {
		return;
	}
	int p[len];
	int c = 0; int r = 0;

	for (int i = 1; i < len - 1; ++i) {
		int mirror_i = 2 * c - i;
		p[i] = (r > i) ? min(r - i, p[mirror_i]) : 0;

		// Extend p[i] centered at i.
		while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
			p[i]++;
		}

		// Move the center to i if the palindrome centered at i goes beyond r.
		if (i + p[i] > r) {
			r = i + p[i];
			c = i;
		}
	}

	// Now scan back and output the biggest palindrome.
	int max_len = 0;
	int center = 0;
	for (int i = 1; i < len - 1; ++i) {
		if (p[i] > max_len) {
			max_len = p[i];
			center = i;
		}
	}

	cout << str.substr((center - max_len) / 2, max_len) << endl;
}

int main() {
	string str;
	cin >> str;

	findPal(str);

	return 0;
}
