#include <iostream>
#include <iomanip>

using namespace std;

#define ll long long
#define lim 20


ll cnt[lim + 1][lim + 1];

ll findCount(int r, int c) {
	if (cnt[r][c] != -1) {
		return cnt[r][c];
	}


	ll lcnt = 0;
	if (c < lim) {
		lcnt = findCount(r, c + 1);
	}

	if (r < lim) {
		lcnt += findCount(r + 1, c);
	}

	cnt[r][c] = lcnt;

	return lcnt;
}

int main() {
	for (int i = 0; i <= lim; ++i) {
		for (int j = 0; j <= lim; ++j) {
			cnt[i][j] = -1;
		}
	}

	cnt[lim][lim] = 1;

	cout << setprecision(20) << findCount(0, 0) << endl;
	
	return 0;
}
