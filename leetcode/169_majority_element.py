class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = nums[0]
        cnt = 0
        
        for x in nums:
            if x == candidate:
                cnt += 1
            elif cnt == 0:
                candidate = x
                cnt = 1
            else:
                cnt -= 1
                
        return candidate
        