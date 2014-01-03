#include <iostream>
#include <string>

using namespace std;

string check(const string& str) {
	int len = str.length();
	if (len < 3) {
		return "Bad";
	}

	int inv = 0;
	int i = 1;
	while (i < len) {
		if (str[i] != str[i - 1]) {
			++inv;
			if (inv == 2) {
				return "Good";
			}
		} else {
			inv = 0;
		}
		++i;
	}
	
	return "Bad";
}

int main() {
	int t;
	string str;
	
	cin >> t;
	while (t--) {
		cin >> str;
		cout << check(str) << endl;
	}
	
	return 0;
}