class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # Basically, if all nums are positive, then just return their squares.
        # Else, do a merge sort kind of thing where one array starts from the non-neg
        # number, and the other starts from the first negative number and goes lower.
        
        mn = min(nums)
        if mn >= 0:
            return [x*x for x in nums]
        
        mx = max(nums)
        if mx < 0:
            return [x*x for x in reversed(nums)]
        
        n = len(nums)
        # Find least neg
        idx = 0
        while idx + 1 < n and nums[idx + 1] < 0:
            idx += 1
            
        # Reverse the list from 0 till idx
        i = 0
        j = idx
        while i < j:
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp
        
            i += 1
            j -= 1
            
        
        # Now start merging the two sub arrays, putting the values in-place
        # starting from 0th index.
        i = 0
        j = idx + 1
        nxt = 0
        ret = [None] * n
        while i <= idx and j < n and nxt < n:
            if abs(nums[i]) < abs(nums[j]):
                ret[nxt] = nums[i] * nums[i]
                i += 1
            else:
                ret[nxt] = nums[j] * nums[j]
                j += 1
                
            nxt += 1
            
        # Put the rest in the rest of the array
        while i <= idx:
            ret[nxt] = nums[i] * nums[i]
            i += 1
            nxt += 1
            
        while j < n:
            ret[nxt] = nums[j] * nums[j]
            j += 1
            nxt += 1
                
        return ret
        
        