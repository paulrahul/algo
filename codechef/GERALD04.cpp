// Codechef: GERALD04
// Simple math. But had to think out the cases a bit.

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int conv(const string& str) {
	size_t idx = str.find(":");
	stringstream ss(str.substr(0, idx) + str.substr(idx + 1));
	int num;
	ss >> num;
	
	num = ((num / 100) * 60) + (num % 100);
	
	return num;
}

int main() {
	int t;
	int t1, t2;
	double dist;
	string tmp;
	
	cout << fixed << setprecision(1);	
	cin >> t;
	while (t--) {
		cin >> tmp;
		t1 = conv(tmp);
		cin >> tmp;
		t2 = conv(tmp);
		cin >> dist;
				
		double ans1 = (t1 - t2) + dist;

		double ans2 = dist;
		double left = t1 - t2 - dist;
		
		if (left <= 0) {
			double t1_walked = t2 + dist - t1;
			double left = dist - t1_walked;
			ans2 += left / 2;
		} else if (left > 0) {
			if (left >= dist) {
				ans2 = t1 - t2;
			} else {
				ans2 += left;
				ans2 += (dist - left) / 2;
			}
		}
		
		cout << ans1 << " " << ans2 << endl;
	}
	
	return 0;
}