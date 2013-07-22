#include <iostream>

using namespace std;

typedef long long int64;
#define MOD 1000000007

int64 total;
int n, k;

void func(int pass, int curr_player) {
	//cout << "call for " << pass << " " << curr_player << endl;
	pass += 1;
	if (pass > n) return;
	if (pass == n) {
		if (curr_player != 0) {
			total  = (total + 1) % MOD;
		}
		return;
	}
	
	for (int i = 0; i <= k; ++i) {
		if (i != curr_player) {
			func(pass, i);
		}
	}
}

int main(int argc, char** argv) {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		total = 0;
		func(0, 0);
					cout << n << " " << k << " = ";

		cout << total <<  endl;
	}

	return 0;
}