#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<bool> is_prime(100001, true);
	vector<int> num_fac(100001, 1);
	
	is_prime[1] = is_prime[0] = false;
	
	int lim = 100000 / 2;
	
	for (int i = 2; i <= lim; ++i) {
		if (!is_prime[i]) continue;
		for (int j = i * 2; j <= 100000; j += i) {
			if (is_prime[j]) {
				is_prime[j]	= false;
				num_fac[j] = 0;
			}
			++num_fac[j];
		}
	}
	
	//for (int i = 2; i <= 100000; ++i) cout << i << " " << num_fac[i] << endl;
	
	int t, a, b, k;
	cin >> t;
	while (t--) {
		cin >> a >> b >> k;
		
		int ans = 0;
		for (int i = a; i <= b; ++i) {
			if (num_fac[i] == k) ++ans;
		}
		cout << ans << endl;
	}
	
	return 0;
}