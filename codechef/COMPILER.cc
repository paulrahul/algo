#include <iostream>
#include <string>

using namespace std;

int main() {
	int t;
	string inp;
	
	cin >> t;
	while (t--) {
		cin >> inp;
		int len = inp.length();
		
		int oc = 0;
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			if (inp[i] == '<') {
				++oc;
			} else {
				--oc;
			}
			
			if (oc < 0) {
				break;
			} else if (oc == 0) {
				ans = i + 1;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}