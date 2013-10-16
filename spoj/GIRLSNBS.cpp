#include <iostream>

using namespace std;

int main() {
	int g, b;
	while (cin >> g >> b) {
		if (g == -1 && b == -1) break;

		int l = min(g, b);
		int h = max(g, b);
		int av = l + 1;

		if (h <= l + 1) {
			cout << (h > 0) << endl;
		} else {
			int s = h - l - 1;
			int ans = s / (l + 1);
			if (s % (l + 1) > 0) {
				++ans;
			}

			cout << (ans + 1) << endl;
		}
	}

	return 0;
}
