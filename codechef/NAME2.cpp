#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	int t;
	string m, w;
	
	cin >> t;
	while(t--) {
		cin >> m >> w;
		bool valid = false;
		
		if (m == w) {
			valid = true;
		} else if(m.length() == w.length()) {
			valid = false;
		} else {
			string str, q;
			if (m.length() > w.length()) {
				str = m; q = w;
			} else {
				str = w; q = m;
			}
			
			int i = 0, j = 0;
			int found_len = 0;
			while (i < q.length() && j < str.length()) {
				if (str[j] == q[i]) {
					found_len++;
					i++;
				}
				j++;
			}
			
			if (found_len == q.length()) valid = true;
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