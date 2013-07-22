#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
	int n, k;
	
	cin >> n >> k;
	double arr[n];
	double m[n];
	
	cin >> arr[0];
	m[0] = arr[0];
	for (int i = 1; i < n; ++i) {
		cin >> arr[i];
		
		if (i < k) {
			m[i] = m[i - 1] + arr[i];
			continue;
		}
		
		int end = i;
		m[i] = arr[i];
		double score = 0;
		while (end >= 0 && i - end + 1 <= k) {
			score += arr[end];
			m[i] = max(m[i], score + ((end - 2 >= 0) ? m[end - 2] : 0));
			end--;
		}
	}
	
	
	cout << setprecision(20) << m[n -  1] << endl;


	return 0;
}