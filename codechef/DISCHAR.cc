#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;

  string str;

  while (t--) {
    cin >> str;

    int len = str.length();
    vector<bool> u(26, false);
    int ans = 0;
    for (int i = 0; i < len; ++i) {
      if (!u[str[i] - 'a']) {
        ++ans;
        u[str[i] - 'a'] = true;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
