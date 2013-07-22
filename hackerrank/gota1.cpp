#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string str;
	cin >> str;
	
	int len = str.length();
	vector<int> count(26, 0);
	
	for (int i = 0; i < len; ++i) {
		count[str[i] - 'a']++;
	}
	
	int single_count = 0;
	bool valid = true;
	for (int i = 0; i < 26; ++i) {
		if (count[i] == 0) continue;
		
		if (count[i] % 2 == 1) {
			if (single_count == 1) {
				valid = false;
				break;
			} else {
				single_count = 1;
			}
		}
	}
	
	if (valid) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}