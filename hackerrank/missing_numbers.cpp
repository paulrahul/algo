#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;

    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    vector<int> b(m, 0);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int i = 0;
    int j = 0;
    int l1 = a.size();
    int l2 = b.size();
    set<int> ans;
    
    while (j < l2) {
        if (i < l1) {
            if (a[i] == b[j]) {
                ++i;
            } else {
                ans.insert(b[j]);
            }
        } else {
            ans.insert(b[j]);
        }
        ++j;
    }
    
    set<int>::iterator iter = ans.begin();
    while(iter != ans.end()) {
        if (iter != ans.begin()) cout << " ";        
        cout << *iter;
        ++iter;
    }
    cout << endl;
    
    return 0;
}
