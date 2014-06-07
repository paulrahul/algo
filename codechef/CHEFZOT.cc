#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	int ans = 0;
	int prev = (arr[0] != 0) ? 0 : -1;
	
	for (int i = 0; i < n; ++i) {
		if (arr[i] != 0) {
			if (prev == -1) {
				prev = i;
			}
			ans = max(ans, i - prev + 1);
		} else {
			prev = -1;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}