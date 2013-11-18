// Leetcode
// http://oj.leetcode.com/problems/candy/
//
// Simple math. O(N)

#include <algorithm>

class Solution {
public:
    int candy(vector<int> &ratings) {
        int len = ratings.size();
        int ans = len;  // at least this much is required.
        vector<int> fr(len, 1);
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                int old = fr[i];
                fr[i] = fr[i - 1] + 1;
                ans += fr[i] - old;
            }
        }

        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && fr[i] <= fr[i + 1]) {
                int old = fr[i];
                fr[i] = fr[i + 1] + 1;
                ans += fr[i] - old;
            }
        }
        
        return ans;
    }
};