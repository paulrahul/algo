#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		
		int price[n][m];
		vector<int> min_price(n, 2000000);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> price[i][j];

				min_price[i] = min(min_price[i], price[i][j]);				
			}
		}
		
		vector<int> min_with_discount(n, 2000000);		
		int discount;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> discount;
				
				if (i > 0) {
					discount = (discount > price[i][j]) ? 0 : (price[i][j] - discount);
					min_with_discount[i] = min(min_with_discount[i], price[i - 1][j] + discount);
				}
			}
		}
		
		for (int i = n - 2; i >= 0; --i) {
			min_price[i] = min(min_price[i] + min_price[i + 1], min_with_discount[i + 1]);
			min_with_discount[i]+= min_price[i + 1];
		}
		
		cout << min(min_price[0], min_with_discount[0]) << endl;
	}

	return 0;
}