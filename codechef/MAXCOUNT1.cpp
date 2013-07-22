#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	int t, n;
	
	int max_count;
	int max_element;
	
	cin >> t;
	while (t--) {
		cin >> n;
		
		vector<int> counts(10001, 0);
		max_count = 0;
		max_element = -1;
		int tmp, c;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			
			c = ++counts[tmp];
			if (c > max_count ||
				(c == max_count && tmp < max_element)) {
				max_count = c;
				max_element = tmp;
			}
		}
		
		cout << max_element << " " << max_count << endl;
	}

	return 0;
}