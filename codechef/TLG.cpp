#include <iostream>

using namespace std;

#define ll long long

int main() {
	ll n, s, t, p;
	cin >> n;
	
	ll ssum = 0;
	ll tsum = 0;
	ll m = 0;
	while (n--) {
		cin >> s >> t;
		ssum += s;
		tsum += t;
		
		if (ssum >= tsum && s - t > m) {
			m = s - t;
			p = 1;
		} else if (tsum >= ssum && t - s > m) {
			m = t - s;
			p = 2;
		}
	}
	cout << p << " " << m << endl;

	return 0;
}