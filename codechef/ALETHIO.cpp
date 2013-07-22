#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	string str;
	string last_num = "";
	int next_start = -1;
	string curr_num = "";
	
	cin >> str;
	int len = str.length();
	int i = 0;
	
	while (i < len) {
		if (str[i] == '0') {
			i++;
			continue;
		}

		curr_num = "";
		next_start = -1;
		while (1) {			
			if (i < len && (str[i] >= '0' && str[i] <= '9')) {
				curr_num += str[i];
				i++;
				continue;
			}
			
			if (i >= len) break;
			
			if (next_start == -1) {
				next_start = i + 1;
				curr_num += str[i];
			} else {
				break;
			}
			i++;
		}
		
		// compare with previous
		if (curr_num.length() < last_num.length()) continue;
		if (curr_num.length() > last_num.length()) {
			last_num = curr_num;
		} else {				
			bool ismore = false;
			for (int j = 0; j < curr_num.length(); ++j) {
				if (curr_num[j] >= 'A' && curr_num[j] <= 'Z') curr_num[j] = '9';
				if (last_num[j] >= 'A' && last_num[j] <= 'Z') last_num[j] = '9';
				
				if (curr_num[j] > last_num[j]) {
					ismore = true;
					break;
				}
				
				if (curr_num[j] < last_num[j]) {
					ismore = false;
					break;
				}
			}
			
			if (ismore) last_num = curr_num;
		}
		
		if (next_start != -1) i = next_start;
	}
	
	if (str == "0") {
		cout << "0";
	} else {
		len = last_num.length();
		for (int i = 0; i < len; ++i) {
			if (last_num[i] >= 'A' && last_num[i] <= 'Z') last_num[i] = '9';
			cout << last_num[i];
		}
	}
	cout << endl;
	
	return 0;
}