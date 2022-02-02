from pydoc import cli

class Solution:
    def __init__(self):
        self.fib = [int] * 45
        self.preseed()

    def preseed(self):
        prev = 0
        next = 1

        for i in range(45):
            self.fib[i] = prev + next
            prev = next
            next = self.fib[i]

    def climbStairs(self, n: int) -> int:
        return self.fib[n - 1]


if __name__ == "__main__":
    o = Solution()
    print("%d -> %d" % (2, o.climbStairs(2)))
    print("%d -> %d" % (3, o.climbStairs(3)))
    print("%d -> %d" % (4, o.climbStairs(4)))
    print("%d -> %d" % (5, o.climbStairs(5)))
    print("%d -> %d" % (6, o.climbStairs(6)))
    print("%d -> %d" % (7, o.climbStairs(7)))
    print("%d -> %d" % (8, o.climbStairs(8)))
    print("%d -> %d" % (1, o.climbStairs(1)))