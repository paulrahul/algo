#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int n, k;
	int curr;
	int sums[100001];
	int l[100001];
	int r[100001];
	int lpos[100000][2];
	int rpos[5][2];	

	cin >> n >> k;
	
	cin >> curr;
	sums[0] = l[0] = r[0] = curr;
	lpos[0][0] = lpos[0][1] = rpos[0][0] = rpos[0][1] = 0;
	
	/*int tmp = 0;
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
				if (l[i - 1] > tmp) {
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
	
	// Do the same for the reverse array.
	for (int j = n - 1; j >= 0; --j) {
		if (j >= n - k) {
			r[j] = sums[n - 1] - ((j > 0) ? sums[j - 1] : 0);
			rpos[j][0] = n - 1; rpos[j][1] = j;
			continue;
		}
		
		// r[j] = 
		// if (rpos[j + 1] == j + 1
		//       if j within k distance from start, then add j
		//       else r[j] = max(r[j + 1], (sums[j + k - 1] - sums[j - 1] + r[j + k + 1])
		// else
		//   simply add j starting a new k sequence
		if (rpos[j + 1][1] == j + 1) {
			if (rpos[j + 1][0] - j + 1 <= k) {
				r[j] = r[j + 1] + arr[j];
				rpos[j][0] = rpos[j + 1][0];
				rpos[j][1] = j;
			} else {
				tmp = sums[j + k - 1] - ((j > 0) ? sums[j - 1] : 0);
				if (j + k + 1 <= n - 1) tmp += r[j + k + 1];
				if (r[j + 1] > tmp) {
					r[j] = r[j + 1];
					rpos[j][0] = rpos[j + 1][0];
					rpos[j][1] = rpos[j + 1][1];					
				} else {
					r[j] = tmp;
					rpos[j][0] = j + k - 1;
					rpos[j][1] = j;									
				}
			}
		} else {
			r[j] = r[j + 1] + arr[j];
			rpos[j][0] = rpos[j][1] = j;
		}
	}
	
	// Try all partitions.
	int max_score = 0;
	int score = 0;
	for (int i = 0; i < n; ++i) {
		int left = l[i];
		int right = r[i];
		
		if (rpos[i][1] - lpos[i][1] > 1) {
			score = left + right;
		} else {
			if (rpos[i][1] == lpos[i][1]) {
				score = left + right - arr[i];
			} else {
				score = left + right - min(arr[lpos[i][1]], arr[rpos[i][1]]);
			}
		}

		max_score = max(max_score, score);
	}
	
	cout << max_score << endl;*/
	
	return 0;
}