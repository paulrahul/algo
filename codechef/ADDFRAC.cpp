#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void split(const string& str, int* a, int* b) {
	int i = str.find('/');
	string a_str = str.substr(0, i);
	string b_str = str.substr(i + 1);

	stringstream ss(a_str + " " + b_str);
	ss >> *a;
	ss >> *b;
}

int gcd(int a, int b) {
	if (b > a) {
		a = a + b;
		b = a - b;
		a = a - b;
	}
	
	int tmp;
	while (b > 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return tmp;
}

int main(int argc, char** argv) {
	int t, n;
	int a, b, c, d;
	cin >> t;
	
	int num[100000];
	int den[100000];
	int ans_num[100000];
	int ans_den[100000];

	string tmp;
	while (t--) {
		cin >> n;
		
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			split(tmp, &num[i], &den[i]);
		}
		
		ans_num[n - 1] = num[n - 1];
		ans_den[n - 1] = den[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			a = num[i] + ans_num[i + 1];
			b = den[i] + ans_den[i + 1];
			
			if (a * den[i] > b * num[i]) {
				ans_num[i] = a;
				ans_den[i] = b;
			} else {
				ans_num[i] = num[i];
				ans_den[i] = den[i];
			}
		}
		
		for (int i = 0; i < n; ++i) {
			int g = gcd(ans_num[i], ans_den[i]);
			cout << ans_num[i] / g << "/" << ans_den[i] / g << endl;
		}
		cout << endl;
	}

	return 0;
}
