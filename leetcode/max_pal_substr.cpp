#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        
        vector<vector<bool> > p(len, vector<bool>(len, false));
        
        for (int i = 0; i < len; ++i) {
            p[i][i] = true;
        }
        
        int st = 0;
        int al = 1;
        for (int l = 2; l <= len; ++l) {
            for (int i = 0; i <= len - l; ++i) {
                int j = i + l - 1;
                
                p[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || p[i + 1][j - 1]);
                if (p[i][j]) {
                    st = i; al = l;
                }
            }
        }
        
        return s.substr(st, al);
    }
};

int main() {
  Solution sol;

  string s;
  while (true) {
    cin >> s;
    cout << sol.longestPalindrome(s) << endl;
  }

  return 0;
}
