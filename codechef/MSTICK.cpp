#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
	int n, q, l, r;
	int arr[100001];
	
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	
	cin >> q;
	while (q--) {
		cin >> l >> r;
	
		int i = l;
		int m = arr[i++];
		while (i <= r) {
			m = min(m, arr[i]);
			i++;
		}
		
		double max_t = 0;
		for (i = 0; i < n; ++i) {
			if (i >= l && i <= r) {
				max_t = max(max_t, (double)(m + ((arr[i] - m) / 2)));
			} else {
				max_t = max(max_t, (double)(arr[i] + m));
			}
		}
		
		cout.setf(ios::fixed,ios::floatfield);
		cout << setprecision(1) << max_t << endl;
	}
	
	return 0;
}