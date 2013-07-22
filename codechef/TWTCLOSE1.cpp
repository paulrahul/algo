#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int n, k;
	
	cin >> n >> k;
	
	int count = 0;
	bool arr[1001];
	
	for (int j = 1; j <= n; ++j) arr[j] = false;
	
	int t;
	string str;
	for (int i = 0; i < k; ++i) {
		cin >> str;
		
		if (str == "CLOSEALL") {
			count = 0;
			for (int j = 1; j <= n; ++j) arr[j] = false;
		} else {
			cin >> t;
			arr[t] = !arr[t];
			if (arr[t]) count++;
			else count--;
		}
		
		cout << count << endl;
	}

	return 0;
}