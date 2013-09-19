#include <iostream>
#include <string>

using namespace std;

bool isGood(const string& str, string fav[], int k) {
	if (str.length() >= 47) {
		return true;
	}

	for (int i = 0; i < k; ++i) {
		if (str.find(fav[i]) != string::npos) {
			return true;
		}
	}

	return false;
}

int main() {
	int k, n;
	cin >> k >> n;
	
	string fav[k];
	for (int i = 0; i < k; ++i) {
		cin >> fav[i];
	}

	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		
		if (isGood(s, fav, k)) {
			cout << "Good" << endl;
		} else {
			cout << "Bad" << endl;
		}
	}

	return 0;
}
