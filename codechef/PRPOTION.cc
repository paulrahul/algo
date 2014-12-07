#include <iostream>

using namespace std;

void sort_arr(int* arr) {
  if (arr[0] < arr[1]) {
    if (arr[2] < arr[0]) {
      int tmp = arr[0];
      arr[0] = arr[2];
      arr[2] = tmp;
    }
  } else {
    if (arr[1] < arr[2]) {
      int tmp = arr[0];
      arr[0] = arr[1];
      arr[1] = tmp;
    } else {
      int tmp = arr[0];
      arr[0] = arr[2];
      arr[2] = tmp;
    }
  }

  if (arr[2] < arr[1]) {
    int tmp = arr[1];
    arr[1] = arr[2];
    arr[2] = tmp;
  }
}

int main() {
  int t, r, g, b, m;
  int arr[3];
  int tmp;

  cin >> t;
  while (t--) {
    cin >> r >> g >> b >> m;

    arr[0] = 0;
    for (int i = 0; i < r; ++i) {
      cin >> tmp;
      arr[0] = max(arr[0], tmp);
    }

    arr[1] = 0;
    for (int i = 0; i < g; ++i) {
      cin >> tmp;
      arr[1] = max(arr[1], tmp);
    }

    arr[2] = 0;
    for (int i = 0; i < b; ++i) {
      cin >> tmp;
      arr[2] = max(arr[2], tmp);
    }

    for (int i = 0; i < m; ++i) {
      sort_arr(arr);
      arr[2] /= 2;
    }

    sort_arr(arr);
    cout << arr[2] << endl;
  }

  return 0;
}
