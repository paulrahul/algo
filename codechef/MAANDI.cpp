#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

bool isOverLucky(int n) {
	stringstream ss;
	ss << n;
	string s = ss.str();
	
	if (s.find("4") != string::npos ||
			s.find("7") != string::npos) {
		return true;
	}

	return false;
}

int main() {
	int n, t;

	cin >> t;
	while (t--) {
		cin >> n;

		int ans = 0;
		int lim = sqrt(n);
		for (int i = 1; i <= lim; ++i) {
			if (n % i == 0) {
				if (isOverLucky(i)) ++ans;
				if (isOverLucky(n / i)) ++ans;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
