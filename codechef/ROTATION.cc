#include <iostream>
#include <vector>

using namespace std;

void rev(vector<int>& arr, int s, int e) {
	int i = s;
	int j = e;
	
	while (i < j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		++i;
		--j;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	
	char ch;
	int d;
	for (int i = 0; i < m; ++i) {
		cin >> ch >> d;
		
		if (ch == 'R') {
			cout << arr[d] << endl;
		} else if (ch == 'A') {
			rev(arr, 1, n - d);
			rev(arr, n - d + 1, n);
			rev(arr, 1, n);
		} else if (ch == 'C') {
			rev(arr, 1, n);
			rev(arr, 1, n - d);
			rev(arr, n - d + 1, n);
		}
	}
	
	return 0;
}