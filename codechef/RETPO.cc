#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

ll dist(ll x1, ll y1, ll x2, ll y2) {
	ll x = abs(x1 - x2);
	ll y = abs(y1 - y2);
	
	ll ret = x + y; 
	
	ll tmp = abs(x - y);
	if (tmp >= 2) {
		if (tmp & 1) {
			--tmp;
		}
		ret += tmp;
	}
	
	return ret;
} 

int main() {
	int t;
	cin >> t;
	ll x, y;
	
	while (t--) {
		cin >> x >> y;
		
		ll ans = 0;
		if (x != 0 && y != 0) {
			ans = dist(0, 0, x, y);
		} else {
			if (x != 0) {
				ans = 1 + dist(0, 1, x, y);
			} else {
				ans = dist(0, 0, x, y);
			}
		}
		cout << x << "," << y << " ";
		cout << ans << endl;
	}
	
	return 0;
}