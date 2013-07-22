#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int n, k;
	int arr[100001];
	bool used[100001];

	cin >> n >> k;
		
	cin >> arr[0];
	used[0] = true;
	long curr_k = arr[0];
	int start, end;
	start = end = 0;
	for (int i = 1; i < n; ++i) {
		cin >> arr[i];
		
		used[i] = false;
		if (end == i - 1) {
			if (i - start + 1 <= k) {
				curr_k += arr[i];
				end = i;
				used[i] = true;
			} else if (arr[i] > arr[start]) {
				curr_k = curr_k - arr[start] + arr[i];
				start += 1;
				end = i;
				used[i] = true;
				used[start - 1] = false;
			}
		} else {
			curr_k = arr[i];
			used[i] = true;
			start = i;
			end = i;
		}
	}
	
	long score = 0;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			cout << i << " ";
			score += arr[i];
			continue;
		}
		
		if ((i == 0 || !used[i - 1]) &&
			(i == n - 1 || !used[i + 1])) {
			//used[i] = true;
			cout << "a" << arr[i] << " ";
			score += arr[i];
		}
	}
	
	cout << endl;
	cout << score << endl;
	
	for (int i = 0; i < n; ++i) {
		if (used[i]) cout << arr[i] << " ";
	}
	
	return 0;
}