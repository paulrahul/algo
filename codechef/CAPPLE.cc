#include <iostream>
#include <set>

using namespace std;

int main() {
  int t;
  cin >> t;

  int tmp;
  int n;

  while (t--) {
    cin >> n;

    set<int> s;
    while (n--) {
      cin >> tmp;
      s.insert(tmp);
    }

    cout << s.size() << endl;
  }

  return 0;
}

