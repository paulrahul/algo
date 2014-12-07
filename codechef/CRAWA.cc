#include <iostream>
#include <cmath>

using namespace std;

bool is_valid(int x, int y) {
	if (y == 0) {
		if (x == 0 ||
			(x > 0 && (x & 1)) ||
		    (x < 0 && !(x & 1))) {
		   return true;    	
		}
	}
	
	double idx = ceil(abs(double(y))/ 2);
	
	int cr_start, cr_end;
	cr_start = -2 - ((idx - 1) * 2);
	if (y > 0) {
		cr_end = 1 + ((idx - 1) * 2);
	} else {
		cr_end = 3 + ((idx - 1) * 2);
	}
	
	if (!(y & 1) && x >= cr_start && x <= cr_end) {
		return true;
	}
	
	if ((x >= cr_end && (x & 1)) ||
		(x <= cr_start && !(x & 1))) {
		return true;
	}
	
	return false;
}


int main() {
	int t, x, y;
	
	cin >> t;
	while (t--) {
		cin >> x >> y;
		//cout << x << " " << y << " ";

		bool valid = is_valid(x, y);
		if (valid) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		
		cout << endl;
		
	}
	
	return 0;
}