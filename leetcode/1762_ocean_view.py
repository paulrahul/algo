from typing import List

class Solution:
    def findBuildings(self, heights: List[int]) -> List[int]:
        n = len(heights)
        mx = heights[n - 1]
        heights[n - 1] = -1
        i = n - 2

        while i >= 0:
            if heights[i] > mx:
                mx = heights[i]
                heights[i] = -1

            i -= 1

        ret = []
        for i in range(n):
            if heights[i] == -1:
                ret.append(i)

        return ret

if __name__ == "__main__":
    o = Solution()
    print(o.findBuildings([4,2,3,1]))
    print(o.findBuildings([4,3,2,1]))
    print(o.findBuildings([1,3,2,4]))