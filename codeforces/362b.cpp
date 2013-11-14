#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> d(n + 1, false);
    int tmp;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        d[tmp] = true;
    }
    
    if (d[1] || d[n]) {
        cout << "NO";
        return 0;
    }
    
    vector<bool> ans(n + 1, false);
    ans[1] = true;
    for (int i = 2; i <= n; ++i) {
        if (d[i]) {
            continue;
        }
        
        if (ans[i - 1]) {
            ans[i] = true;
        } else if (i >= 3 && ans[i - 2]) {
            ans[i] = true;
        } else if (i >= 4 && ans[i - 3]) {
            ans[i] = true;
        }
    }
    
    if (ans[n]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}