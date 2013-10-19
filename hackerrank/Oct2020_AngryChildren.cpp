#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    
    cin >> n;
    vector<int> arr(n, 0);
    cin >> k;
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    int ans = arr[k - 1] - arr[0];
    for (int i = 1; i <= n - k; ++i) {
        ans = min(ans, arr[i + k - 1] - arr[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}

