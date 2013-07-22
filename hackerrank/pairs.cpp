#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char** argv) {
	int n, k;
	
	while (cin >> n >> k) {
		int arr[100001];
		set<int> nums;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			nums.insert(arr[i]);
		}

		sort(arr, arr + n);
		int ret = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (nums.find(arr[i] + k) != nums.end()) {
				ret++;
			}
		}
		
		cout << ret << endl;
	}

	return 0;
}