#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double find_min(int k, int l, int r, double arr[], double min_b[]) {
	double m = 0;

//	cout << "k = " << k << endl;
		
	int nearest_l = l/k + 1;
	int nearest_r = r/k;

//	cout << nearest_l << ", " << nearest_r << endl;
	
	int lim = nearest_l * k - 1;
	m = arr[l];
	for (int i = l + 1; i <= lim; ++i) {
		m = min(m, arr[i]);
	}

//	cout  << "m = " << m << endl;
	
	lim = nearest_r * k;
	m = min(m, arr[lim]);
	for (int i = lim + 1; i <= r; ++i) {
		m = min(m, arr[i]);
	}

//		cout  << "m = " << m << endl;
	
	for (int i = nearest_l; i < nearest_r; ++i) {
		m = min(m, min_b[i]);
	}
	
//		cout  << "m = " << m << endl;
	
	return m;
}

void find_max(int n, int k, int l, int r, double arr[], double max_b[], double* max_out, double* max_in) {
	double x = 0;
	for (int i = 0; i < l/k; ++i) {
		x = max(x, max_b[i]);
	}

	int lim = n / k;
	for (int i = r/k + 1; i <= lim ; ++i) {
		x = max(x, max_b[i]);
	}
	
	for (int i = (l / k) * k; i < l; ++i) {
		x = max(x, arr[i]);
	}
	
	for (int i = r + 1; i < ((r / k) + 1) * k; ++i) {
		x = max(x, arr[i]);
	}
	
	*max_out = x;

	int nearest_l = l/k + 1;
	int nearest_r = r/k;

//	cout << nearest_l << ", " << nearest_r << endl;
	
	lim = nearest_l * k - 1;
	x = arr[l];
	for (int i = l + 1; i <= lim; ++i) {
		x = max(x, arr[i]);
	}

//	cout  << "m = " << m << endl;
	
	lim = nearest_r * k;
	x = max(x, arr[lim]);
	for (int i = lim + 1; i <= r; ++i) {
		x = max(x, arr[i]);
	}

//		cout  << "m = " << m << endl;
	
	for (int i = nearest_l; i < nearest_r; ++i) {
		x = max(x, max_b[i]);
	}
	
	*max_in = x;
}

int main(int argc, char** argv) {
	int n, q, l, r;
	double arr[100001];
	double min_b[1000];
	double max_b[1000];
	
	cin >> n;
	int k = ceil(sqrt(n));
	int j = 0;
	double m;
	double x;
	int max_ind = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];

		if (i == 0) m = x = arr[i];

		if (arr[i] > arr[max_ind]) max_ind = i;
		
		if (i % k == 0) {
			if (i != 0) {
				min_b[j] = m;
				max_b[j++] = x;
			}						
			m = x = arr[i];
		} 

		m = min(m, arr[i]);
		x = max(x, arr[i]);		
		
		if (i == n - 1) {
			min_b[j] = m;
			max_b[j++] = x;						
		}		
	}
	
	cin >> q;
	while (q--) {
		cin >> l >> r;

		m = find_min(k, l, r, arr, min_b);
		
		double max_t = 0;
		if (max_ind < l || max_ind > r) {
			max_t = (double)(arr[max_ind] + m);
		} else {
			double max_out, max_in;
			find_max(n, k, l, r, arr, max_b, &max_out, &max_in);
			max_t = max((double)(max_out + m), (double)(m) + ((double)(max_in - m) / 2));
		}
		
		cout.setf(ios::fixed,ios::floatfield);
		cout << setprecision(1) << max_t << endl;
	}
	
	return 0;
}