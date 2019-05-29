class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sz = len(nums)
        if sz == 0:
            return 1
        
        # Segregate positive and negative numbers.
        np = 0
        pp = sz - 1
        while np <= pp:
            if nums[np] <= 0:
                np += 1

            if nums[pp] > 0:
                pp -= 1
                
            if np < pp and nums[np] > 0 and nums[pp] <= 0:
                tmp = nums[np]
                nums[np] = nums[pp]
                nums[pp] = tmp
                np += 1
                pp -= 1

        if pp == sz - 1:
            # not a single positive found.
            return 1

        nstart = pp + 1
        nsz = sz - nstart
        for i in xrange(nstart, sz):
            val = abs(nums[i]) - 1
            if val < nsz and nums[nstart + val] > 0:
                nums[nstart + val] = -nums[nstart + val]

        for i in xrange(nstart, sz):
            if nums[i] > 0:
                return i - nstart + 1

        return nsz + 1
    
if __name__ == "__main__":
    import copy

    o = Solution()
    while True:
        try:
            inp = raw_input()
        except EOFError:
            break

        nums = [int(x) for x in inp.split()]
        orig = copy.deepcopy(nums)
        print "%s = %d" % (orig, o.firstMissingPositive(nums))
