#include <iostream>
#include <string>

using namespace std;

void c_count(string str, int arr[]) {
	int len = str.length();
	for (int i = 0; i < len; ++i) {
		arr[str[i] - 'a']++;
	}
}

int main(int argc, char** argv) {
	int t, n;
	string a, b, c, tmp;
	
	cin >> t;
	while (t--) {
		int c_arr[26];
		int p_arr[26];
		for (int i = 0; i < 26; ++i) c_arr[i] = p_arr[i] = 0;

		cin >> a >> b;
		c_count(a + b, p_arr);
		
		cin >> n;
		c = "";
		while (n--) {
			cin >> tmp;
			c = c + tmp;
		}
		c_count(c, c_arr);
		
		bool valid = true;
		for (int i = 0; i < 26; ++i) {
			if (c_arr[i] > p_arr[i]) {
				valid = false;
				break;
			}
		}
		
		if (valid) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		cout << endl;
	}

	return 0;
}