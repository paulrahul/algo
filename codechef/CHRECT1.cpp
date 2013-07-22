#include <iostream>

using namespace std;

int main() {
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		
		int num_openings = 0;
		if (n > 1) num_openings++;
		if (m > 1) num_openings++;
		
		if (num_openings == 0 || (n * m) == 2) {
			cout << "0" << endl;
			continue;
		}
		
		int ans = k / num_openings;
		if (k % num_openings != 0) ans++;
		
		cout << ans << endl;
	}
	
	return 0;
}