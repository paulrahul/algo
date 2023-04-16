class Solution(object):
    def __init__(self):
        self.prev = 0
        self.count = 0
        self.max_diff = (0, 0)
        self.lim = 0
        
    def init(self):
        self.prev = 0
        self.count = 0
        self.max_diff = (0, 0)
        self.lim = 0   

    def recurse(self, num_digits_left, mask, running_num):
        # Iterate over all digits for this position.
        for d in range(10):
            if mask & (1 << d) != 0:
                # Digit has already been used.
                continue
            
            num = running_num * 10 + d
            if num_digits_left > 1:
                ret = self.recurse(num_digits_left - 1, mask | (1 << d), num)
                if not ret:
                    return False
            elif num <= self.lim:
                if num < 1:
                    continue
                self.count += 1
                if num - self.prev > self.max_diff[1] - self.max_diff[0]:
                    self.max_diff = (self.prev, num)

                self.prev = num
                # print(num)
            else:
                return False # No more generation possible.
            
        return True
        
    def solve(self, lim):
        self.init()
        self.lim = lim
        
        nd = 0
        while lim > 0:
            nd += 1
            lim //= 10
        
        for x in range(1, nd + 1):
            self.recurse(x, 0, 0)

        print("Solution for limit {} - Count: {}, Max diff is {} between {} & {}"
            .format(self.lim, self.count, self.max_diff[1] - self.max_diff[0],
                    self.max_diff[1], self.max_diff[0]))

if __name__ == "__main__":
    o = Solution()
    o.solve(10)
    o.solve(12)
    o.solve(105)
    o.solve(120)