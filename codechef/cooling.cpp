#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
	int t, n;
	int pie[101];
	int rack[101];

	cin >> t;

	while (t-- > 0) {
		cin >> n;

		for (int i = 0; i < n; ++i ) {
			cin >> pie[i];
		}

		for (int i = 0; i < n; ++i ) {
			cin >> rack[i];
		}

		sort(pie, pie + n);
		sort(rack, rack + n);

		int next_rack = 0;
		int next_pie = 0;
		while (next_rack < n) {
			if (pie[next_pie] <= rack[next_rack]) {
				next_pie++;
			}
			next_rack++;
		}

		cout << next_pie << endl;
	}

	return 0;
}