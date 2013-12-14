// Codechef December 2013 Long contest: REIGN
// DP - Max subarray sum.


#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main() {
	int k, n, t;
	
	cin >> t;
	while (t--) {
		cin >> n >> k;
		
		vector<ll> arr(n, 0);
		vector<ll> lmx(n, 0);
		vector<ll> rmx(n, 0);
		vector<ll> rlmx(n, 0);
		vector<ll> rrmx(n, 0);
		
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		ll mx = lmx[0] = rlmx[0] = arr[0];
		for (int i = 1; i < n; ++i) {
			lmx[i] = max(lmx[i - 1] + arr[i], arr[i]);
			mx = max(mx, lmx[i]);
			rlmx[i] = mx;
		}
		
		mx = rmx[n - 1] = rrmx[n - 1] = arr[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			rmx[i] = max(rmx[i + 1] + arr[i], arr[i]);
			mx = max(mx, rmx[i]);
			rrmx[i] = mx;
		}

		ll ans = rlmx[0] + rrmx[k + 1];
		for (int i = k + 1; i < n; ++i) {
			ans = max(ans, rlmx[i - k - 1] + rrmx[i]);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}