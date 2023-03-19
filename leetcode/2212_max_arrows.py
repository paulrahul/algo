class Solution(object):
    def __init__(self):
        self.best = -1
        self.path = [0] * 12
        self.ans = None

    def solve(self, left, start, aliceArrows, rSum):
        if left == 0:
            return

        # Start from the end and pick the highest possible
        # section.
        i = start
        while i >= 0:
            if left > aliceArrows[i]:
                self.path[i] = aliceArrows[i] + 1

                # Not used as yet and eligible.
                if rSum + i > self.best:
                    self.best = rSum + i
                    self.ans = [x for x in self.path]

                self.solve(
                    left - aliceArrows[i] - 1, i - 1,
                    aliceArrows, rSum + i)
            

            self.path[i] = 0
            i -= 1

    def maximumBobPoints(self, numArrows, aliceArrows):
        """
        :type numArrows: int
        :type aliceArrows: List[int]
        :rtype: List[int]
        """
        self.best = -1
        self.ans = [0] * 12
        self.used = 0

        self.solve(numArrows, 11, aliceArrows, 0)

        # Fill up any unused number of arrows.
        used = 0
        for x in self.ans:
            used += x
        if used < numArrows:
            self.ans[11] += (numArrows - used)

        return self.ans

if __name__ == "__main__":
    o = Solution()

    print(o.maximumBobPoints(9, [1,1,0,1,0,0,2,1,0,1,2,0]))
    print(o.maximumBobPoints(3, [0,0,1,0,0,0,0,0,0,0,0,2]))  
    print(o.maximumBobPoints(53, [0,2,2,0,1,6,16,11,4,5,3,3]))     