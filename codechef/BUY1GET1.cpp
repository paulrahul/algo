#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	int t;
	cin >> t;
	
	string str;
	while (t--) {
		vector<int> small(26, 0);
		vector<int> caps(26, 0);
	
		cin >> str;
		int len = str.length();

		for (int i = 0; i < len; ++i) {
			if (str[i] >= 'a' && str[i] <= 'z') {
				small[str[i] - 'a']++;
			} else {
				caps[str[i] - 'A']++;
			}
		}
		
		int count = 0;
		for (int i = 0; i < 26; ++i) {
			count += small[i] / 2;
			count += small[i] % 2;

			count += caps[i] / 2;
			count += caps[i] % 2;	
		}
		
		cout << count <<  endl;
	}

	return 0;
}