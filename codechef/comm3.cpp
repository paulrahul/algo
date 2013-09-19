#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	double r;

	cin >> t;
	while (t--) {
		cin >> r;

		int cnt = 0;
		int x[3];
		int y[3];

		for (int i = 0; i < 3; ++i) {
			cin >> x[i] >> y[i];
			
			if (i > 0) {
				double d = pow(
					pow(x[i] - x[i - 1], 2) + pow(y[i] - y[i - 1], 2),
					0.5);
				if (d <= r) ++cnt;
			}
		}

		double d = pow(
			pow(x[0] - x[2], 2) + pow(y[0] - y[2], 2),
			0.5);
		if (d <= r) ++cnt;

		if (cnt >= 2) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}

	}

	return 0;
}
