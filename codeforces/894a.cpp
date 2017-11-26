#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;

  while (cin >> s) {
    int n = s.length();
    int q_c = 0;
    int a_c = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (s[i] == 'Q') {
        ++q_c;
        ans += a_c;
      } else if(s[i] == 'A') {
        a_c += q_c;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
