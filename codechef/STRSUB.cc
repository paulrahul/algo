#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ll long long

int main() {
  int t, k, n, q;
  int l, r;
  string s;

  cin >> t;
  while (t--) {
    cin >> n >> k >> q;
    cin >> s;

    vector<int> one_count(n, 0);
    one_count[0] = s[0] - '0';
    for (int i = 1; i < n; ++i) {
      one_count[i] = one_count[i - 1] + (s[i] - '0');
    }

    ll dp[n][n];
    
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }

    for (int l = 2; l <= n; ++l) {
      for (int i = 0; i <= n - l; ++i) {
        int j = i + l - 1;

        int local_one_count = one_count[j] - (i > 0 ? one_count[i - 1] : 0);
        int local_zero_count = j - i + 1 - local_one_count;

        if (local_one_count <= k && local_zero_count <= k) {
          int sz = j - i + 1;
          dp[i][j] = (sz * (sz + 1)) / 2;
        } else {
          dp[i][j] = -1;

          if (j - i == 1) {
            dp[i][j] = max(dp[i][j], dp[i][i] + dp[j][j]);
          } else {
            for (int k = i + 1; k < j; ++k) {
              dp[i][j] = max(dp[i][j], (dp[i][k] + dp[k][j] - dp[k][k]));
            }
          }
        }
      }
    }

    for (int i = 0; i < q; ++i) {
      cin >> l >> r;
      cout << dp[l - 1][r - 1] << endl;
    }
    
  }

  return 0;
}
