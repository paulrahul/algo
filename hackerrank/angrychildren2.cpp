#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
    int n, k;
    cin >> n;
    vector<ll> arr(n, 0);
    cin >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    vector<ll> s(n, 0);
    s[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] + arr[i];
    }
    
    ll ans = 0;
    for (ll i = 0, times = k - 1; times > 0; ++i, --times) {
        ans += times * arr[i];
    }
    for (ll i = k - 1, times = k - 1; times > 0; --i, --times) {
        ans -= times * arr[i];
    }
    ll prev = ans;
    ans = abs(ans);
		// cout << ans << endl;
 
    for (int i = 1; i <= n - k; ++i) {
        // Formula: Mi = |Mi-1 + 2.(common numbers) - (k - 1).(rejected + new number)|
        ll nu = prev - ((k - 1) * (arr[i - 1] + arr[i + k - 1]));
        nu += 2 * (s[i + k - 2] - s[i - 1]);  // common numbers
        prev = nu;
        nu = abs(nu);
        ans = min(ans, nu);
				// cout << nu << endl;
    }
    
    cout << ans << endl;
    
    return 0;
}

