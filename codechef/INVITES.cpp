#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

long long c(int n, int r) {
	if (r > n) return 0;
	if (n == r) return 1;
	
	long long num = 1;
	
}

int main(int argc, char** argv) {
	int t, n;
	int tmp;
	cin >> t;
	
	while (t--) {
		cin >> n;
		vector<int> counts(n + 1, 0);
		vector<int> enemy(n + 1, 0);
		
		for (int i = 1; i <= n; ++i) {
			cin >> tmp;
		
			enemy[i] = tmp;
			counts[i] = n - i;
			
			if (tmp > i) {
				counts[i]--;
			} else {
				if (enemy[tmp] != i) {
					counts[tmp]--;
				}
			}
		}
		
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += (counts[i] + 1);
		}
		ans++;
		
		setprecision(20);
		cout << (ans % 1000000007) << endl;
	}

	return 0;
}