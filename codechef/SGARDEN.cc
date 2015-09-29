#include <iostream>
#include <vector>

using namespace std;

#define long long ll

ll gcd(ll a, ll b) {
	while (b != 0) {
		ll t = b;
		b = a % b;
		a = t;
	}
	
	return a;
}

ll lcm(ll a, ll b) {
	return 
}

int main() {
	int t, n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> arr(n + 1, -1);
		
		for (int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		
		vector<int> moves(n + 1, -1);
		for (int i = 1; i <= n; ++i) {
			int cnt = 0;
			
			int j = i;
			moves[i] = 0;
			while (j != i) {
				++moves[i];
				j = arr[j];
				
				if (moves[j] != -1) {
					moves[i] += moves[j];
					break;
				}
			}
		}
		
		// Take lcm of all moves
	}
		
	return 0;
}