#include <iostream>

using namespace std;

#define ll long long

int main() {
	int t;
	ll n, k;
	
	cin >> t;
	while (t--) {
		cin >> n >> k;
		
		if (k == 0) {
			cout << "0 " << n << endl;
		} else {
			cout << (n / k) << " " << (n % k) << endl;
		}
	}

	return 0;
}