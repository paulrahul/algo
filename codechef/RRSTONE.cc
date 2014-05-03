#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int n, k;
	
	cin >> n >> k;
	vector<ll> arr(n, 0);
	ll  mn, mx;
	cin >> arr[0];
	mn = mx = arr[0];
	for (int i = 1; i < n; ++i) {
		cin >> arr[i];
		mn = min(mn, arr[i]);
		mx = max(mx, arr[i]);
	}

    if (k == 0) {
    	mn = 0;
    }

	if (k & 1) {
		cout << mx - arr[0];
		for (int i = 1; i < n; ++i) {
			cout << " " << mx - arr[i];
		}
	} else {
		cout << arr[0] - mn;
		for (int i = 1; i < n; ++i) {
			cout << " " << arr[i] - mn;
		}		
	}
	cout << endl;
	
	return 0;
}