import heapq

# O(NlogN)
class Solution(object):
    # O(K) (K = 9) => O(1)
    def calcSum(self, x):
        ret = 0
        while x > 0:
            ret += x % 10
            x /= 10

        return ret

    def maximumSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        m = {}
        # O(NlogM)
        for x in nums:
            # O(1)
            s = self.calcSum(x)

            if s not in m:
                m[s] = []

            # O(logM)
            heapq.heappush(m[s], -x)
        
        ret = -1
        # O(N)
        for k, v in m.items():
            if len(v) <= 1:
                continue

            # O(1)
            a = heapq.heappop(v)
            b = heapq.heappop(v)
            ret = max(ret, -(a + b))

        return ret