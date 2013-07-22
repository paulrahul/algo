#include <iostream>
#include <string>

using namespace std;

bool recurse(const string& str, int idx, int n) {
	if (idx >= n) return true;
	
	if (str[idx] == '1') {
		if (recurse(str, idx + 1, n)) {
			return true;
		}
	}
	
	if (str[idx] == '1' && idx + 1 < n && str[idx + 1] == '4') {
		if (recurse(str, idx + 2, n)) {
			return true;
		}
	}

	if (str[idx] == '1' && idx + 1 < n && str[idx + 1] == '4' && idx + 2 < n && str[idx + 2] == '4') {
		if (recurse(str, idx + 3, n)) {
			return true;
		}
	}
	
	return false;
}

int main() {
	string str;
	cin >> str;
	
	int n = str.length();
	if (recurse(str, 0, n)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
