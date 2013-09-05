#include <iostream>

using namespace std;

#define ll long long

int main() {
	int t, n;
	int train[2000][3];
	
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> train[i][0] >> train[i][1] >> train[i][2];
		}
		
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			if (ans >= train[i][0]) {
				ll w = (ans - train[i][0]) % train[i][2];
				ans += (w == 0) ? 0 : (train[i][2] - w); // waiting time
			} else {
				ans += train[i][0] - ans;
			}
			ans +=  train[i][1]; // travel time
			//cout << ans << endl;
		}
		
		cout << ans << endl;
	}

	return 0;
}