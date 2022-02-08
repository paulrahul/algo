from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)

        mx = [0] * n
        mn = [0] * n
        
        mn[0] = prices[0]
        for i in range(1, n):
            mn[i] = min(mn[i - 1], prices[i])
            
        mx[n - 1] = prices[n - 1]
        for i in range(n - 2, 0, -1):
            mx[i] = max(mx[i + 1], prices[i])
            
        ans = 0
        for i in range(n):
            if mx[i] - mn[i] > 0:
                ans = max(ans, mx[i] - mn[i])
        
        return ans
    
if __name__ == "__main__":
    o = Solution()
    print(o.maxProfit([7,1,5,3,6,4]))
    print(o.maxProfit([7,6,4,3,1]))