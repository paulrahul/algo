#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ll long long

int main() {
	int a;
	string s;
	
	cin >> a;
	cin >> s;
	
	int len = s.length();
	int arr[len][len];
	
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			arr[i][j] = (s[i] - '0') * (s[j] - '0');
		}
	}
	
	vector<vector<int> > sm(len, vector<int>(len, 0));
	sm[0][0] = arr[0][0];
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			int top = (i > 0) ? sm[i - 1][j] : 0;
			int left = (j > 0) ? sm[i][j - 1] : 0;
			sm[i][j] += top + left;
		}
	}
	
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			for (int k = i; k < len;)
		}
	}
	
	return 0;
}