#include <iostream>
#include <vector>
#include <string>

using namespace std;

void count(const string& str, vector<int>* cnt) {
	int l = str.length();
	for (int i = 0; i < l; ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			(*cnt)[str[i] - '0']++;
		} else if (str[i] >= 'a' && str[i] <= 'z') {
			(*cnt)[10 + (str[i] - 'a')]++;			
		} else if (str[i] >= 'A' && str[i] <= 'Z') {
			(*cnt)[10 + 26 + (str[i] - 'A')]++;			
		}
	}
}

int main() {
	int t;
	string a, b;
	
	cin >> t;
	while (t--) {
		cin >> a >> b;
		
		vector<int> cnt_a(62, 0);
		vector<int> cnt_b(62, 0);		
		count(a, &cnt_a);
		count(b, &cnt_b);

		int ans = 0;
		for (int i = 0; i < 62; ++i) {
			ans += min(cnt_a[i], cnt_b[i]);
		}
		
		cout << ans << endl;
	}
}