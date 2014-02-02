#include <iostream>

using namespace std;

inline int area(int x1, int y1, int x2, int y2) {
	return (x2 - x1) * (y2 - y1);
}

int main() {
	int t;
	int x1, y1, x2, y2;
	int a1, b1, a2, b2;
	
	cin >> t;
	while (t--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> a1 >> b1 >> a2 >> b2;
		
		int ar = area(x1, y1, x2, y2) + area(a1, b1, a2, b2);
		
		if (a1 >= x2 || b1 >= y2 || a2 <= x1 || b2 <= y1) {
			ar += 0;  // No overlap.
		} else {
			// Overlap. Let's plot the overlap rectangle corners in terms of
			// (p, q) and (r, s).
			int p = max(a1, x1);
			int q = max(b1, y1);
			int r = min(a2, x2);
			int s = min(b2, y2);
			ar -= area(p, q, r, s);
		}
		
		cout << ar << endl;
	}
	
	return 0;
}