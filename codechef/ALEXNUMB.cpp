#include <iostream>
#include <set>

using namespace std;

#define ll long long

int main() {
	int t;
	ll n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		
		set<int> arr;
		int tmp;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			arr.insert(tmp);
		}
		
		n = arr.size() - 1;
		cout << (n * (n + 1)) / 2 << endl;
	}

	return 0;
}