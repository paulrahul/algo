#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int n, k;
	int arr[100001];
	int sums[100001];
	int l[100001];
	int lpos[100000][2];

	cin >> n >> k;
	
	cin >> arr[0];
	sums[0] = l[0] = arr[0];
	lpos[0][0] = lpos[0][1] = 0;
	
	int tmp = 0;
	for (int i = 1; i < n; ++i) {
		cin >> arr[i];
		sums[i] = sums[i - 1] + arr[i];
		if (i < k) {
			l[i] = sums[i];
			lpos[i][0] = 0; lpos[i][1] = i;
			continue;
		}
		
		// l[i] = 
		// if (lpos[i - 1] == i - 1
		//       if i within k distance from start, then add i
		//       else l[i] = max(l[i - 1], (sums[i] - sums[i - k] + l[i - k - 1])
		// else
		//   simply add i starting a new k sequence
		if (lpos[i - 1][1] == i - 1) {
			if (i - lpos[i - 1][0] + 1 <= k) {
				l[i] = l[i - 1] + arr[i];
				lpos[i][0] = lpos[i - 1][0];
				lpos[i][1] = i;
			} else {
				tmp = sums[i] - sums[i - k];
				if (i - k - 1 >= 0) tmp += l[i - k - 1];
				if (l[i - 1] >= tmp) {
					l[i] = l[i - 1];
					lpos[i][0] = lpos[i - 1][0];
					lpos[i][1] = lpos[i - 1][1];					
				} else {
					l[i] = tmp;
					lpos[i][0] = i - k + 1;
					lpos[i][1] = i;									
				}
			}
		} else {
			l[i] = l[i - 1] + arr[i];
			lpos[i][0] = lpos[i][1] = i;
		}
	}
	
	cout << l[n - 1] << endl;
	
	return 0;
}