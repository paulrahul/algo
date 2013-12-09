#include <iostream>
#include <string>

using namespace std;

// Returns carry value. Sum of digits is set in d1.
int AddDigits(char* c1, const char c2, int c) {
    int d1 = *c1 - '0';
    int d2 = c2 - '0';
    int t = d1 + d2 + c;
    if (t > 9) {
        c = 1;
    } else {
        c = 0;
    }

    *c1 = '0' + (t % 10);
    return c;
}

// Returns carry value. Difference of digits is set in d1.
int SubtractDigits(char *c1, const char c2, int c) {
    int d1 = *c1 - '0';
    int d2 = c2 - '0';

    int s1 = d1 - c;
    if (s1 < d2) {
        c = 1;
        if (s1 < 0) {
            s1 = 9;
        } else {
            s1 += 10;
        }
    } else {
        c = 0;
    }

    *c1 = '0' + (s1 - d2);
    return c;
}

void increment(char* num, int len) {
    // Increment least significant digit by 1.
    int c = AddDigits(&num[len - 1], '1', 0);
    
    // Now increment other digits till carry is present.
    int i = len - 2;
    while (i >= 0 && num[i] != ' ' && c == 1) {
        c = AddDigits(&num[i], '0', c);
        --i;
    }

    // If carry still present, that means the number is increasing
    // to one more number of digits (e.g. 99 -> 100). So convert the
    // next significant digit to 1.
    if (i >= 0 && c == 1) {
        num[i] = '1';
    }        
}

// Returns true if difference is positive.
bool subtract(char* a, const char* b, int alen, int blen) {
	char bkup[alen + 1];
    strcpy(bkup, a);

    // First subtract all digits of b from corresponding
    // digits of a.
    int c = 0;
 	int i = alen - 1;
    int j = blen - 1;
    for (; j >= 0; --i, --j) {
    	c = SubtractDigits(&a[i], b[j], c);
    }

    // If carry still left and no more digit is present
    // in a, then the difference is negative.
    if (c == 1 && (i < 0 || a[i] == ' ')) {
    	strcpy(a, bkup);
    	return false;
    }

    // Keep on deducting more significant digits till carry is present.
    while (i >= 0 && a[i] != ' ' && c == 1) {
    	c = SubtractDigits(&a[i], '0', c);
        --i;
    }

    // Did not reach the end. Nothing more to do.
    if (i >= 0 && a[i] != ' ') {
    	return true;
    }

    // If most significant digit is 0, then that means the number is
    // decreasing in number of digits. Set the most siginificant digit
    // to ' '
    if (a[i + 1] == '0') {
    	a[i + 1] = ' ';
    }

    return true;
}

void PadAndSubtract(char* a,  // the dividend
					const string& b,  // the divisor
					int alen,  // length of dividend
					int times,  // how many times to pad
					char* q) {  // current quotient (is of length alen)
	int blen = b.length();
	string ds(blen + times, '0');  // Create 0 padded string first.
	for (int i = 0; i < blen; ++i) {
		ds[i] = b[i];
	}
	
	int msb = alen - times - 1;
	
	int curr = q[msb] - '0';
	while (subtract(a, ds.c_str(), alen, ds.length())) {
		++curr;
	}
	q[msb] = '0' + curr;
}

string sanitize(char* num, int len) {
	int i = -1;
	while (i + 1 < len && (num[i + 1] == '0' || num[i + 1] == ' ')) {
        ++i;
	}

	string ret(num + i + 1, num + len);
	if (ret == "") {
		ret = "0";
	}

	return ret;
}

void divide(const string& a, const string& b) {
	int alen = a.length();
	int blen = b.length();
	
    const char* src = a.c_str();
    char dividend[alen + 1];
    strcpy(dividend, src);
    const char* divisor = b.c_str();

    char q[alen];
    memset(q, '0', alen);
	
	// First pad and subtract.
	for (int i = alen - blen; i > 0; --i) {
		PadAndSubtract(dividend, divisor, alen, i, q);
	}
	
    while (subtract(dividend, divisor, a.length(), b.length())) {
        increment(q, alen);
    }

    cout << sanitize(q, alen) << " "
		 << sanitize(dividend, alen) << endl;                
}

int main() {
	string a, b;
	
	while (cin >> a >> b) {
		divide(a, b);
	}
	
	return 0;
}