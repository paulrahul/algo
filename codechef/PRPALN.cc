#include <iostream>
#include <string>

using namespace std;

bool IsModPal(const string& s) {
  int len = s.length();
  bool bad_found = false;

  int i = 0;
  int j = len - 1;

  while (i < j) {
    if (s[i] != s[j]) {
      if (bad_found) {
        return false;  // Already a bad one found.
      }

      bad_found = true;
      if (s[j - 1] == s[i]) {
        --j;
      } else if (s[i + 1] == s[j]) {
        ++i;
      } else {
        return false;
      }
      continue;
    }

    ++i; --j;
  }

  return true;
}

int main() {
  int t;
  string s;

  cin >> t;
  while (t--) {
    cin >> s;

    bool valid = IsModPal(s);

    if (valid) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }

  return 0;
}
