#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	int t, n, m;
	
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		vector<int> num;
		vector<bool> npresent(1001, false);

		int x;
		bool found = false;
		for (int i = 0; i < n; ++i) {
			cin >> x;
			if (x == m) {
				cout << "Yes" << endl;
				found = true;
			}
			num.push_back(x);
			npresent[x] = true;
		}
	
		if (found) continue;
	
		sort(num.begin(), num.end());
		if (m < num[0]) {
			cout << "No" << endl;
			continue;
		}
		
		// find the last number <= m
		int i = n - 1;
		while (i >= 0 && num[i] > m) {
			i--;
		}
		
		if (i == 0) {
			// only one number less than m, so it can't be the answer.
			cout << "No" << endl;
			continue;
		}
		
		int num_size = i + 1;
		int limit = pow(2, num_size) - 1;
		for (int c = 3; c <= limit; ++c) {
			int sum = 0;
			for (int s = 0; s < num_size; ++s) {
				if ((c & (1 << s)) != 0) {
					// bit is set
					sum += num[s];
					//cout << s << "=" << num[s] << endl;
				}
			}
			
			//cout << "c = " << c << ", sum = " << sum << endl;
			if (sum == m) {
				cout << "Yes" << endl;
				found = true;
				break;
			}
		}
		
		if (!found) {
			cout << "No" << endl;
		}
	}

	return 0;
}