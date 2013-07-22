#include <iostream>
#include <iomanip>

using namespace std;

#define LL long long

int main(int argc, char** argv) {
	LL n, k;
	cin >> n >> k;
	
	LL mid = n / 2;
	if (n & 1) mid++;
	
	LL ans = 0;
	if (k <= mid) {
		ans = 1 + (k - 1) * 2;
	} else {
		k -= mid;
		ans = 2 + (k - 1) * 2;
	}
	
	setprecision(20);
	cout << ans << endl;

	return 0;
}