#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long int64;

struct band {
	band(int l) {
		this->total_length = l;
	}
	int64 total_length;
	//int num_other_bands;
};

bool compare_band(band a, band b) {
	//return ( (a.total_length * a.num_other_bands) < 
	//		 (b.total_length * b.num_other_bands) );
	return (a.total_length < b.total_length);
}

int main(int argc, char** argv) {
	int t, n;
	int l, b;
	
	cin >> t;
	while (t--) {
		cin >> n;
		//cout  << "n = " << n << endl;
		map<int, int64> band_length;
		for (int i = 0; i < n; ++i) {
			cin >> b >> l;
			if (band_length.find(b) == band_length.end()) {
				band_length[b] = 0;
			}
			band_length[b] += l;
		}
		vector<band> bands;
		map<int, int64>::iterator iter = band_length.begin();
		while (iter != band_length.end()) {
			bands.push_back(band(iter->second));
			++iter;
		}
		sort(bands.begin(), bands.end(), compare_band);
		
		int64 max = 0;
		int len = bands.size();
		for (int i = 0; i < len; ++i) {
			max += (i + 1) * bands[i].total_length;
		}
		
		cout << max << endl;
	} 
	
	// test case generator
/*	cout << "1" << endl;
	cout << "100000" << endl;
	for (int i = 0; i < 100000; ++i) {
		
	} */

	return 0;
}