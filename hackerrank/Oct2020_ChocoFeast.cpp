#include <iostream>

using namespace std;

int main() {
    int t, n, c, m;

    cin >> t;
    while (t--) {
        cin >> n >> c >> m;
        
        int ans = n / c;
        int s = ans;
        while (s >= m) {
            ans += s / m;
            s = s % m + s / m;
        }
        
        cout << ans << endl;
    }

    return 0;
}

