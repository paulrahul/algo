#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

int main() {
	int n, t;
	ll sum;
	
	cin >> t;
	while (t--) {
		cin >> n >> sum;
		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		ll lim = pow(2, n);
		bool found = false;
		for (ll c = 1; c < lim; ++c) {
			ll tsum = 0;
			ll x = c;
			int i = 0;
			while (x) {
				if (x & 1) {
					tsum += arr[i];
					if (tsum == sum) {
						found = true;
						break;
					}
				}
				++i;
				x >>= 1;
			}
		}
		
		if (found) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	
	return 0;
}