#include <iostream>

using namespace std;

int solution(int N) {
  int mx = 0;
  bool start = false;
  int len = 0;

  while (N) {
    if (N & 1) {
      if (start) {
        mx = max(mx, len);
      } else {
        start = true;
      }
      len = 0;
    } else {
      ++len;
    }

    N >>= 1;
  }

  return mx;
}

int main() {
  int N;
  while (cin >> N) {
    cout << N << " " << solution(N) << endl;
  }
  return 0;
}
