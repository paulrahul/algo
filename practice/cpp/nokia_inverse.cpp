#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t;

	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> arr(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}

		bool valid = true;
		for (int i = 1; i <= n; ++i) {
			if (i != arr[arr[i]]) {
				valid = false;
				break;
			}
		}

		if (valid) {
			cout << "inverse" << endl;
		} else {
			cout << "not inverse" << endl;
		}
	}

	return 0;
}
