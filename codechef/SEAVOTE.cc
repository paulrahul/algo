#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t, n;
  
  cin >> t;
  while (t--) {
    cin >> n;

    vector<int> arr(n, 0);
    int sum = 0;
    int lsum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
      sum += arr[i];
      lsum += arr[i] - 1;
    }

      if (sum == 100) {
        cout << "YES" << endl;
      } else if (sum < 100) {
        cout << "NO" << endl;
      } else {
        int d = 100 - lsum;

        if (d <= 0 || d >= n) {
          cout << "NO" << endl;
        } else {
          cout << "YES" << endl;
        }
      }    
  }

  return 0;
}
