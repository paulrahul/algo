#include <vector>

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        
        int ans = 0;
        vector<int> loci;
        vector<int> m(len, 0);
        
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                loci.push_back(i);
            } else {
                if (loci.size() > 0) {
                    int prev = loci[loci.size() - 1];
                    int curr = i - prev + 1;
                    
                    if (prev > 0) {
                        curr += m[prev - 1];
                    }
                    m[i] = curr;
                    
                    ans = max(ans, curr);
                    loci.pop_back();
                }
            }
        }
        
        return ans;
    }
};