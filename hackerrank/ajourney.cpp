#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int lastk(int n, int k) {
	set<int> powers;
	
	int i = 0;
	while (n) {
		if (n % 2) {
			powers.insert(i);
		}
		n /= 2;
		i++;
	}
	
	double d1 = pow(10, k);
	int d = d1;
	int r = 2;
	long long ret = (powers.find(0) != powers.end()) ? r % d : 1;
	for (int j = 1; j < i; ++j) {
		r = (r * r) % d;
		
		if (powers.find(j) != powers.end()) {
			ret = ((ret % d) * (r % d)) % d;
		}
	}
	
	return ret;
}

int firstk(int n, int k) {
   double x, y;

   x = n * log10(2);
   y = floor(pow(10, x - floor(x) + k - 1));
   
   return (int)y;
}

int main() {
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		
		n--;
		
		int first = firstk(n, k);
		int last = lastk(n, k);
		cout << first << " " << last << endl;
		cout << (first + last) << endl;
	}
	
	return 0;
}