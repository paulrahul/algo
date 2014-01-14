// Codechef Jan 2014 Long: MTRICK
// Nice trick with the reversal part. Rest was some pain in the ass
// modular arithmetic.

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

#define ll long long

ll mod(ll a, ll b) {
	//cout << "mod: " << a << " " << b << endl;
	return (a % b + b) % b;
}

long long multiple(long long a, long long b, long long c) // a * b % c
{
    if (b == 0) {
        return 0;
    }
    long long ret = multiple(a, b >> 1, c);
    ret = (ret + ret) % c;
    if (b & 1) {
        ret = (ret + a) % c;
    }
    return ret;
}

int main() {
	int t, n;
	ll a, b, c;
	string s;
	
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll> arr(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		
		cin >> a >> b >> c;
		cin >> s;

		int next_asc = 0;
		int next_desc = n - 1;
		bool asc = true;
		vector<int> nm(n, 0);

		// O(N)
		// Formula:
		// Keep computing term T.
		// f(i) = T - b ^ nm[i] + b ^ nm[i] * new_arr[i]
		//      = term - m_term + m_term * new_arr[i]
		//      = term - m_term + pow_term
		ll term = 1;
		ll m_term = 1;
		setprecision(20);
		vector<ll> new_arr(n, 0);
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'A') {
				term = ((term % c) + (a % c)) % c;				
			}
			else if (s[i] == 'M') {
				int prev = (i > 0) ? nm[i - 1] : 0;
				nm[i] = prev + 1;

				term = multiple(term, b, c);
				m_term = multiple(m_term, b, c);
			} else if (s[i] == 'R') {
				asc = !asc;  // Reverse pattern.
			}
			
			if (asc) {
				new_arr[i] = arr[next_asc++];
			} else {
				new_arr[i] = arr[next_desc--];
			}

			//cout << "debug: " << new_arr[i] << " " << m_term << " " << term << endl;

			// (new_arr[i] ^ nm[i]) % c
			//unsigned long long int tmp = (m_term % c) * (new_arr[i] % c);
			ll pow_term = multiple(m_term, new_arr[i], c);
			new_arr[i] = ((term % c) + (pow_term % c)) % c;
			//cout << "debug1: " << (new_arr[i] % c) << " " << (m_term % c) << " " << (new_arr[i] % c) - (m_term % c) << endl;
			new_arr[i] = mod((new_arr[i] % c) - (m_term % c), c);				
			
			if (i > 0) {
				cout << " ";
			}
			cout << new_arr[i];
		}

		cout << endl;
		
	}
	
	return 0;
}