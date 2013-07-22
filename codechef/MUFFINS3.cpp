#include <iostream>

using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) {
			cout << "2" << endl;
		} else {
			cout << (n / 2 + 1) << endl;
		}
	}

	return 0;
}