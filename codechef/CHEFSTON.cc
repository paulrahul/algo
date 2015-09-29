#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, n, k;

  cin >> t;
  while (t--) {
    cin >> n >> k;

    vector<int> a(n, 0);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    long long ans = 0;
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;

      ans = max(ans, ((long long) k / a[i]) * tmp);
    }

    cout << ans << endl;

  }

  return 0;
}
