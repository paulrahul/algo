#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	int x1, x2, x3;
	int y1, y2, y3;
	double max_a, min_a;
	int max_idx, min_idx;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x1 >> y1
				>> x2 >> y2
				>> x3 >> y3;

		double a = abs((double) (-1 * x2 * y1 + x3 * y1 + 
									 x1 * y2 - x3 * y2 - 
									 x1 * y3 + x2 * y3) / 2);
		//cout << a << endl;
		if (i == 0) {
			min_a = max_a = a;
			min_idx = max_idx = i + 1;
		} else {
			if (a <= min_a) {
				min_a = a;
				min_idx = i + 1;
			}

			if (a >= max_a) {
				max_a = a;
				max_idx = i + 1;
			}
		}
	}

	cout << min_idx << " " << max_idx << endl;

	return 0;
}
