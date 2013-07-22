#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	int t, n, k;
	cin >> t;
	
	while (t--) {
		cin >> n >> k;
		int sum = 0;
		int w[100];
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
			sum += w[i];
		}
		
		sort(w, w + n);
		int ssum1 = 0;
		for (int i = 0; i < k; ++i) ssum1 += w[i];
		int diff1 = abs((sum - ssum1) - ssum1);

		int ssum2 = 0;
		for (int i = 0, j = n - 1; i < k; ++i, --j) ssum2 += w[j];		
		int diff2 = abs(ssum2 - (sum - ssum2));

		int diff = diff1 > diff2 ? diff1 : diff2;
		cout << diff << endl;
	}

	return 0;
}