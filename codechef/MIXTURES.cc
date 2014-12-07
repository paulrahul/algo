#include <iostream>

using namespace std;

#define ll long long

int main() {
  int n;
  int arr[100];
  ll dp[100][100];
  int col[100][100];

  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
      dp[i][i] = 0;
      col[i][i] = arr[i];
    }

    for (int l = 2; l <= n; ++l) {
      for (int i = 0; i <= n - l; ++i) {
        int j = i + l - 1;

        dp[i][j] = -1;
        for (int k = i + 1; k <= j; ++k) {
          ll tmp = dp[i][k - 1] + dp[k][j] + (col[i][k - 1] * col[k][j]);
          if (dp[i][j] < 0 || tmp < dp[i][j]) {
            dp[i][j] = tmp;
            col[i][j] = (col[i][k - 1] + col[k][j]) % 100;
          }
        }
      }
    }

    cout << dp[0][n - 1] << endl;
  }

  return 0;
}
