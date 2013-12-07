#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Returns if negative or not.
bool StripLeadingZeroes(string* num) {
	if (num == NULL || num->length() == 0) {
		return false;
	}
	
	int len = num->length();
	int i = -1;
	bool neg = false;
	while (i + 1 < len && (num[i + 1] == "0" || num[i + 1] == "-"))  {
		++i;
		if (num[i] == "-") {
			neg = true;
		}
	}
	
	*num = num->substr(i + 1);
	return neg;
}

int Add(string& a, const string& b, int alen, bool sub = false) {
	// NULL checks already done outside.
	int blen = b.length();  // Will not be more than alen.
	
	int c = 0;
	for (int i = 0, ai = alen - 1, bi = blen - 1; i < blen; ++i, --ai, --bi) {
		int anum = a[ai] - '0';
		int bnum = b[bi] - '0';
		
		int t = anum + bnum + c;
		if (t > 9) {
			c = 1;
		}
		a[ai] = (char) ('0' + (t % 10));
	}
	

	for (int i = alen - blen; i >= 0 && a[i] != ' '; --i) {
		int anum = a[i] - '0' + c;
		if (anum > 9) {
			c = 1;
		}
		a[i] = (char) ('0' + (anum % 10));	
	}

	
	// Check the first digit. If 0, then the digit to the left must be set to 1.
	if (a[a.length() - alen] == '0') {
		++alen;
		a[a.length() - alen] = '1';
	}
	
	return alen;
}

int main() {
	string a, b;
	
	while (cin >> a >> b) {
		bool aneg = StripLeadingZeroes(&a);
		bool bneg = StripLeadingZeroes(&b);		
		
		int alen = a.length();
		int blen = b.length();
		
		// First, the edge cases.
		if (alen == 0 || blen == 0) {
			// Invalid input.
			cout << "Invalid input." << endl;
		} else if (b == "0") {
			// Divide by zero.
			cout << "NAN NAN" << endl;
		} else if (b == "1") {
			cout << a << " " << "0" << endl;
		} else if (blen > alen) {
			// b has more digits than a, so b > a
			cout << "0 " << a << endl;
		} else {
			// b has same or lesser length as a and is more than 1.
			// Do the normal process now.
			
			string q(a.length(), ' ');
			q[q.length() - 1] = '0';
			
			int len = b.length();
			for (int i = 0; i < 20; ++i) {
				len = Add(q, "1", len);
				cout << q << endl;				
			}
		}
		
	}
	
	return 0;
}