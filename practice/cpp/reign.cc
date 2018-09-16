#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  int tmp;
  cin >> t;

  while (t--) {
    vector<int> arr;

    while (cin >> tmp) {
      arr.push_back(tmp);
    }


    int sz = arr.size();
    vector<int> lr(sz, -1);
    vector<int> rr(sz, -1);
    int last_max_idx = -1;

    lr[0] = 0;
    last_max_idx = 0;
    for (int i = 1; i < sz; ++i) {
      if (arr[i] >= arr[i - 1]) {
        lr[i] = lr[i - 1];
        if (arr[i] >= arr[last_max_idx]) {
          lr[i] = lr[last_max_idx];
          last_max_idx = i;
        }
      } else {
        lr[i] = i;
      }
    }

    rr[sz - 1] = sz - 1;
    last_max_idx = sz - 1;
    for (int i = sz - 2; i >= 0; --i) {
      if (arr[i] >= arr[i + 1]) {
        rr[i] = rr[i + 1];
        if (arr[i] >= arr[last_max_idx]) {
          rr[i] = rr[last_max_idx];
          last_max_idx = i;
        }
      } else {
        rr[i] = i;
      }
    }

    for (int i = 0; i < sz; ++i) {
      cout << "Index " << i + 1 << " : ["
           << lr[i] + 1 << ", " << rr[i] + 1 << "]" << endl;
    }

  }

  return 0;
}
