#include <iostream>

using namespace std;

int main() {
  int x, y, k, n;
  int p, c;
  int t;

  cin >> t;
  while (t--) {
    cin >> x >> y >> k >> n;

    int needed = x - y;
    bool got = false;
    for (int i = 0; i < n; ++i) {
      cin >> p >> c;

      if (!got && p >= needed && c <= k) {
        got = true;
      }
    }

    if (got) {
      cout << "LuckyChef" << endl;
    } else {
      cout << "UnluckyChef" << endl;
    }
  }

  return 0;
}
