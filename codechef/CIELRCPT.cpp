#include <iostream>

using namespace std;

int num_bits_set(int n) {
	int count = 0;
	
	while (n) {
		if (n & 1) count++;
		n >>= 1;
	}
	
	return count;
}

int main() {
	int t, p;
	
	cin >> t;
	while (t--) {
		cin >> p;
		
		int ans = 0;
		if (p >= 4096) {
			ans = p / 2048;
			p %= 2048;
		}
		
		ans += num_bits_set(p);
		cout << ans << endl;
	}

	return 0;
}