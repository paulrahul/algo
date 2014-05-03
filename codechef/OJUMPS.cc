#include <iostream>

using namespace std;

#define ll long long

int main() {
	ll a;
	cin >> a;
	ll r = a % 6;
	if (r == 0 || r == 1 || r == 3) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
	
	return 0;
}