#include <iostream>

using namespace std;

#define ll long long

ll ans = 0;

void recurse(int s, int n) {
	if (s >= n) {
		ans++;
		return;
	}
	
	int lim = n - s;
	for (int i = 1; i <= lim; ++i) {
		recurse(s + i, n);
	}
}

int main() {
	int n;
	cin >> n;
	
	recurse(0, n);
	
	cout << ans << endl;

	return 0;
}