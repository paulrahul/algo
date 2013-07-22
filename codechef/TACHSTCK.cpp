#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	int n, d;
	cin >> n >> d;
	
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	int count = 0;
	
	int i = 0;
	while (i < n - 1) {
		if (arr[i + 1] - arr[i] <= d) {
			count++;
			i += 2;
			continue;
		}
		i++;
	}
	
	cout << count << endl;

	return 0;
}