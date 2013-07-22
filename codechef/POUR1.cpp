#include <iostream>

using namespace std;

int solve(int source, int dest, int a, int b, int c) {
	if (source == c || dest == c) {
		return 0;
	}
	
	int transfer = (b - dest > a) ? a : b - dest;
	int moves = 0;
	if (transfer == 0) {
		dest = (source < b) ? source : b;
		source -= dest;
		moves = 2;  // empty dest, transfer from source.
	} else {
		if (source < transfer) source = a;
		dest += transfer;
		source -= transfer;
		moves = 2;  // fill source, transfer
	}
	
	moves += solve(source, dest, a, b, c);
	return moves;
}

int gcd(int a, int b) {
	if (b < a) {
		a = a + b;
		b = a - b;
		a = a - b;
	}
	
	while (b != 0) {
		int tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int main() {
	int t;
	cin >> t;
	
	int a, b, c;
	while (t--) {
		cin >> a >> b >> c;
		
		if (a < c && b < c) {
			cout << "-1" << endl;
			return 0;
		}
		
		if (a == c || b == c) {
			cout << "1" << endl;
			return 0;
		}
		
		int g = gcd(a, b);
		if (c % g != 0)  {
			cout << "-1" << endl;
			return 0;
		}
		
		int min1 = solve(0, 0, a, b, c);
		int min2 = solve(0, 0, b, a, c);
		
		cout << min(min1, min2) << endl;
	}

	return 0;
}