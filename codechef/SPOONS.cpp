#include <iostream>

using namespace std;

#define int64 long long

int64 arr[3000];

int64 ceil(int64 n, int64 l, int64 r) {
    if (l > r) return -1;
   
    int64 h = (l + r) / 2;

    if (h == 0) return -1;
   
    if (h == 1) {
        if (n == 1) {
            return 1;
        } else {
            return ceil(n, h + 1, r);
        }
    }

    int64 hc = arr[h];
    if (hc == n) {
        return h;
    }

    if (hc > n) {
        int64 ret = ceil(n, l, h - 1);
        if (ret > 0) {
            return ret;
        } else {
            return h;
        }
    } else {
        return ceil(n, h + 1, r);
    }
   
    return -1;
}

int main() {
    int t;
    int64 n;
   
    arr[1] = 1;
    arr[2] = 2;
    int64 d = 1;
    int64 p = 2;
    int lim = 2;
    int64 maxn = 1000000000000000000LL;
    for (int64 i = 3; i <= 100; ++i) {
        if (i & 1) ++d;
        if (i % d == 0) {
            p = p * (i / d);
        } else if (p % d == 0) {
            p = (p / d) * i;
        }
        arr[i] = p;
		if (p >= maxn) {
			lim = i;
			break;
		}
    }
   
    cin >> t;
    while (t--) {
        cin >> n;
		int r = (n > lim) ? lim : n;
		int ans = ceil(n, 1, r);
		cout << ans << endl;
    }

    return 0;
}