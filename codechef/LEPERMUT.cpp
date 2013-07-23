/*
 * LEPERMUT.cpp
 *
 *  Created on: 23-Jul-2013
 *      Author: rahul
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int t, n, curr;
	cin >> t;

	while (t--) {
		cin >> n;

		bool valid = true;
		for (int i = 1; i <= n; ++i) {
			cin >> curr;
			if (abs(curr - i) > 1) {
				valid = false;
			}
		}

		if (valid) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}


