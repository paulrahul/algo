#include <iostream>
#include <string>

using namespace std;

int cnt = 0;
void paran(string curr, int l, int r) {
  if (l == 0 && r == 0) {
    cout << curr << endl;
    ++cnt;
    return;
  }

  if (l > 0) {
    paran(curr + "(", l - 1, r);
  }

  if (r > 0 && r > l) {
    paran(curr + ")", l, r - 1);
  }
}

int main() {
  int n;

  cout << "Enter n: ";
  cin >> n;

  paran("", n, n);
  cout << "Printed " << cnt << " patterns." << endl;

  return 0;
}
