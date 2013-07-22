#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	int k, n;
	double t;

	cin >> k;
	while (k--) {
		cin >> n >> t;

		double arr[10000];
		double newarr[10000];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			newarr[i] = arr[i];
		}

		for (int i = 0; i < n - 1; ++i) {
			double l = newarr[i];
			double r = newarr[i+1];

			if (r - l >= t) continue;

			double dtc = t - (r - l);
			double hs = dtc / 2;
			double lcm = (i == 0) ? newarr[i] : (newarr[i] - newarr[i-1] - t);

			double lm = (lcm >= hs) ? hs : lcm;
			double rm = hs + (hs - lm);
			newarr[i] = newarr[i] - lm;
			newarr[i + 1] = newarr[i + 1] + rm;
		}

		double diff_max = 0;
		for (int i = 0; i < n; ++i) {
			//cout << arr[i] << "," << newarr[i] << endl;
			double diff = abs(newarr[i] - arr[i]);
			diff_max = max(diff_max, diff);
		}

		cout.setf(ios::fixed,ios::floatfield);
		cout << setprecision(4) << diff_max << endl;
	}

	return 0;
}