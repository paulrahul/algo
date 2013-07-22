#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
	int n, k;
	
	while (cin >> n >> k) {
		int c[100];
		for (int i = 0; i < n; ++i) cin >> c[i];

		sort(c, c + n);

		double sum = 0;
		for (int i = n - 1, j = 0; i >= 0; --i, ++j) {
			sum += (j / k + 1)*c[i];
		}
		
		cout << setprecision(15) << sum << endl;
	}

	return 0;
}