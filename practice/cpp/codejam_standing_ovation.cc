#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int t;
  int smax;
  string s;

  cin >> t;
  for (int x = 1; x <= t; ++x) {
    cin >> smax;
    cin >> s;
    
    int standing = 0;
    int ans = 0;
    int len = s.length();

    for (int i = 0; i < len; ++i) {
      int ns = s[i] - '0';
      if (ns == 0) {
        continue;
      }

      if (standing < i) {
        int np = (i - standing);
        ans += np;
        standing += np;
      }
      standing += ns;
    }

    cout << "Case #" << x << ": " << ans << endl;
  }

  return 0;
}
