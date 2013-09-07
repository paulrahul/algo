/*
ID: paul.ra1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool isValid(int m) {
	stringstream ss;	
	ss << m;
	string num = ss.str();
	int len = num.length();
	
	bool valid = true;
	bool digits[10];
	for (int i = 1; i < 10; ++i) {
		digits[i] = false;
	}
	
	char f = num[0];
	int idx = 0;
	char d = num[idx];
	int nd = 1;
	digits[d - '0'] = true;
	while (1) {
		idx = (idx + (d - '0')) % len;
		d = num[idx];
	
		if (d == '0') {
			valid = false;
			break;
		}
		
		if (digits[d - '0']) {
			if (idx != 0 || nd != len) {
				valid = false;
			}
			break;
		}
		
		digits[d - '0'] = true;
		++nd;
	}

	return valid;
}

int main() {
	ifstream cin("runround.in");
	ofstream cout("runround.out");

	int m;
	cin >> m;

	do {
		++m;
	} while (!isValid(m));
	
	cout << m << endl;

	return 0;
}