#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
	int t;
	long long ans = 0;
	string str;
	int known = 0;
	int curr = 0;
	
	cin >> t;
	while (t--) {
		cin >> str;
		int len = str.length();
		
		ans = 0;
		int i = 0;
		known = 0;
		curr = 0;
		
		while (i < len) {
			if (str[i] == '.') {
				curr = 0;
				while (i < len && str[i] == '.') {
					curr++;
					i++;
				}
				
				if (curr > known) {
					ans++;
					known = curr;
				}
				
				continue;
			}
			
			i++;
		}
		
		if (curr > known) {
			ans++;
			known = curr;
		}
		
		setprecision(20);
		cout << ans << endl;
	}

	return 0;
}