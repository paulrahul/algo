#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, n, m;
  
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<int> arr(n, 0);
    int mx = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      s += arr[i];
      mx = max(mx, arr[i]);
    }

    int b = n * mx - s;
    bool valid = false;
 
    if (b <= m && ((m - b) % n == 0)) {
      valid = true;
    }

    if (valid) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}
