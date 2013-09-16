#include <iostream>

using namespace std;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
           71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
           151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
           233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

 // Return the number of primes <= floor
int floor(int x, int l, int r) {
    if (l > r) return -1;

    int m = (l + r) / 2;

    if (p[m] == x) {
        return m + 1;
    }

    if (p[m] < x) {
        int ret = floor(x, m + 1, r);
        if (ret > 0) {
            return ret;
        } else {
            return m + 1;
        }
    } else {
        return floor(x, l, m - 1);
    }

    return -1;
}

int main() {
    int nt;
    int m, n;
    char arr[500][500];
    int t[500][500];
    int r[500][500];
    int b[500][500];
    int l[500][500];

    cin >> nt;
    while (nt--) {
        cin >> m >> n;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> arr[i][j];

                if (i == 0) {
                    t[i][j] = 0;
                } else {
                    if (arr[i - 1][j] == '^') {
                        t[i][j] = t[i - 1][j] + 1;
                    } else {
                        t[i][j] = 0;
                    }
                }

                if (j == 0) {
                    l[i][j] = 0;
                } else {
                    if (arr[i][j - 1] == '^') {
                        l[i][j] = l[i][j - 1] + 1;
                    } else {
                        l[i][j] = 0;
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1) {
                    b[i][j] = 0;
                } else {
                    if (arr[i + 1][j] == '^') {
                        b[i][j] = b[i + 1][j] + 1;
                    } else {
                        b[i][j] = 0;
                    }
                }

                if (j == n - 1) {
                    r[i][j] = 0;
                } else {
                    if (arr[i][j + 1] == '^') {
                        r[i][j] = r[i][j + 1] + 1;
                    } else {
                        r[i][j] = 0;
                    }
                }

                if (arr[i][j] != '^') continue;

                if (l[i][j] >= 2 && r[i][j] >= 2 &&
                    t[i][j] >= 2 && b[i][j] >= 2) {
                    // Get minimum
                    int min1 = min(l[i][j], r[i][j]);
                    int min2 = min(t[i][j], b[i][j]);
                    ans += floor(min(min1, min2), 0, 61);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
