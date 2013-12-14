#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

#define ll long long

int main() {
	int n, q;
	
	cin >> n >> q;
	
	int k = sqrt((double) n);
	vector<int> arr(n, 0);
	vector<ll> s(ceil (n / k), 0);
	
	ll cs = 0;
	int sl = 0;
	for (int i = 0; i < n; ++i) {
		if (i != 0 && i % k == 0) {
			s[sl++] = cs;
			cs = 0;
		}
		
		cin >> arr[i];
		cs += arr[i];
	}
	
	s[sl++] = cs;
	
	char op;
	int i, j;
	setprecision(20);
	while (q--) {
		cin >> op >> i >> j;
		if (op == 'S') {
			if (j / k == i / k) {
				ll ans = 0;
				for (int x = i; x <= j; ++x) {
					ans += arr[x];
				}
				cout << ans << endl;
				continue;
			}
			
			int nbs = ((i / k) + 1) * k;
			int pbs = (j / k) * k;
			
			ll ans = 0;
			for (int x = i; x < n && x <= nbs - 1; ++x) {
				ans += arr[x];
			}
			
			for (int x = pbs; x >= 0 && x <= j; ++x) {
				ans += arr[x];
			}
			
			int sb = nbs / k;
			int eb = (pbs - 1) / k;
			for (int x = sb; x >= 0 && x < n && x <= eb; ++x) {
				ans += s[x];
			}
			
			cout << ans << endl;
		} else if (op == 'G') {
			arr[i] += j;
			s[i / k] += j;
		} else if (op == 'T') {
			arr[i] -= j;
			s[i / k] -= j;
		}
	}
	
	return 0;
}