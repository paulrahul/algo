#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

#define LL long long

const LL mod = 1000000007;

LL ncr(int n, int r) {
	if (n < r) {
		return 0;
	}
	if (n == r) {
		return 1;
	}

	LL num = 1;
	for (int i = n; i > r; --i) {
		num *= i;
	}

	LL den = 1;
	for (int i = n - r; i > 1; --i) {
		den *= i;
	}

	return (num / den) % mod;
}

LL mypow(int n, int e) {
	if (e < 0) {
		return 1;
	}
	LL p = pow(n, e);
	return p % mod;
}

LL normal_digits_e(int ndigits, int num_lucky_expected) {
	if (num_lucky_expected > ndigits) {
		return 0;
	}

	LL num_lucky = 0;

	// First digit is lucky. All other digits except lucky ones can be any digit.
	num_lucky += ncr(ndigits - 1, num_lucky_expected - 1) * mypow(2, num_lucky_expected) * mypow(10, ndigits - num_lucky_expected);

	// First digit is not lucky. Hence first digit will have only 9 choices.
	num_lucky += ncr(ndigits - 1, num_lucky_expected) * mypow(2, num_lucky_expected) * mypow(10, ndigits - num_lucky_expected - 1) * 9;

	// Deduct duplicates
	num_lucky -= ncr(num_lucky_expected, num_lucky_expected) * mypow(2, num_lucky_expected) * mypow(10, ndigits - num_lucky_expected);	

	return num_lucky;
}

LL normal_digits(int ndigits) {
	if (ndigits < 4) {
		return 0;
	}

	LL num_lucky = 0;
	if (ndigits == 4) {
		num_lucky = 16;
	} else if (ndigits > 4 && ndigits < 7) {
		num_lucky = normal_digits_e(ndigits, 4);
	} else if (ndigits == 7) {
		num_lucky = 128 + normal_digits_e(ndigits, 4);
	} else {
		num_lucky = normal_digits_e(ndigits, 4) + normal_digits_e(ndigits, 7);
	}

	return num_lucky;
}

LL limit_digits(string num, bool low) {
	int digits[1010];

	int ndigits = num.length();

	if (ndigits < 4) {
		return 0;
	}

	for (int i = 1; i <= ndigits; ++i) {
		digits[i] = num[i - 1] - '0'; 
	}

	LL num_discarded = 0;
	if (low) {
		for (int i = 1; i <= ndigits; ++i) {
			if (i == 1 && digits[i] > 1) {
				num_discarded += (digits[i] - 1) * mypow(10, ndigits - 1);
			} else if (i > 1) {
				num_discarded += (digits[i]) * mypow(10, ndigits - i);
			}
		}
	}  else {
		for (int i = 1; i <= ndigits; ++i) {
			num_discarded += (9 - digits[i]) * mypow(10, ndigits - i);
		}
	}

	return num_discarded;
}

LL limit_digits_inl(int i, int digit, int ndigits, int num_lucky_expected, bool low) {
	int options = 0;
	LL num_lucky = 0;
	if (!low) {
		if (digit > 4) options++;
		if (digit > 7) options++;

		// i being lucky.
		num_lucky += options * ncr(ndigits - i, num_lucky_expected - 1) * mypow(2, num_lucky_expected - 1) * mypow(10, ndigits - num_lucky_expected - i);

		if (i == 1) {
			// i not being lucky. first digit can not be zero
			num_lucky += (digit - options - 1) * ncr(ndigits - i, num_lucky_expected) * mypow(2, num_lucky_expected) * mypow(10, ndigits - num_lucky_expected - 1 - i);
		} else {
			// i not being lucky.
			num_lucky += (digit - options) * ncr(ndigits - i, num_lucky_expected) * mypow(2, num_lucky_expected) * mypow(10, ndigits - num_lucky_expected - 1 - i);
		}
	} else {
		if (digit < 4) options++;
		if (digit < 7) options++;

		// i being lucky.
		num_lucky += options * ncr(ndigits - i, num_lucky_expected - 1) * mypow(2, num_lucky_expected - 1) * mypow(10, ndigits - num_lucky_expected - i);

		// i not being lucky.
		num_lucky += (9 - digit - options) * ncr(ndigits - i, num_lucky_expected) * mypow(2, num_lucky_expected) * mypow(10, ndigits - num_lucky_expected - 1 - i);
	}
	return num_lucky;
}

LL limit_digits1(string num, bool low) {
	int digits[1010];

	int ndigits = num.length();

	if (ndigits < 4) {
		return 0;
	}

	bool all_lucky = true;
	for (int i = 1; i <= ndigits; ++i) {
		digits[i] = num[i - 1] - '0'; 
		if (digits[i] != 4 && digits[i] != 7) {
			all_lucky = false;
		}
	}

	LL num_lucky = 0;
	if (all_lucky) num_lucky++;

	for (int i = 1; i <= ndigits; ++i) {
		// in each iteration, we are attempting to increase/decrease the ith digit.
		num_lucky += limit_digits_inl(i, digits[i], ndigits, 4, low);
		num_lucky += limit_digits_inl(i, digits[i], ndigits, 7, low);
	}

	return num_lucky;
}

LL limit_digits_same(string l, string r) {
	int ldigits[1010];
	int rdigits[1010];

	int ndigits = l.length();

	if (ndigits < 4) {
		return 0;
	}

	bool all_lucky = true;
	for (int i = 1; i <= ndigits; ++i) {
		ldigits[i] = l[i - 1] - '0'; 
		if (ldigits[i] != 4 && ldigits[i] != 7) {
			all_lucky = false;
		}
	}
	LL num_lucky = 0;
	if (all_lucky) num_lucky++;

	all_lucky = true;
	for (int i = 1; i <= ndigits; ++i) {
		rdigits[i] = r[i - 1] - '0'; 
		if (rdigits[i] != 4 && rdigits[i] != 7) {
			all_lucky = false;
		}
	}
	if (all_lucky) num_lucky++;

	for (int i = 1; i <= ndigits; ++i) {
		int options = 0;
		if (ldigits[i] < 4 && rdigits[i] >= 4) options++;
		if (ldigits[i] < 7 && rdigits[i] >= 7) options++;

		// i being lucky.
		num_lucky += options * ncr(ndigits - i, num_lucky_expected - 1) * mypow(2, num_lucky_expected - 1) * mypow(10, ndigits - num_lucky_expected - i);

		// i not being lucky.
		num_lucky += (9 - digit - options) * ncr(ndigits - i, num_lucky_expected) * mypow(2, num_lucky_expected) * mypow(10, ndigits - num_lucky_expected - 1 - i);
	}

	return num_lucky;	
}

int main(int argc, char** argv) {
	int t;
	string s;
	char lch[1010];
	char rch[1010];
	int nl, nr;

	cin >> t;
	getline(cin, s); //fake
	while (t-- > 0) {
		getline(cin, s);

		sscanf(s.c_str(), "%s %s", lch, rch);

		string l(lch);
		string r(rch);

		nl = l.length();
		nr = r.length();

		LL num_lucky = 0;

		num_lucky = limit_digits1(l, true);

		for (int i = nl + 1; i < nr; ++i) {
			num_lucky += normal_digits(i);
		}

		num_lucky += limit_digits1(r, false);

		cout << num_lucky << endl;
	}

	return 0;
}