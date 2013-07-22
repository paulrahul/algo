#include <iostream>

using namespace std;

int main() {
	int t;
	double t1, t2, t3, t4;
	
	cin >> t;
	while (t--) {
		cin >> t1 >> t2 >> t3 >> t4;
		cout << t1 / (t1 + t2) << endl;
	}

	return 0;
}