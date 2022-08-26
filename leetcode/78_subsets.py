class Solution:
    def find_subsets(self, nums: List[int], idx: int) -> List[List[int]]:
        n = len(nums)
        
        if idx == n - 1:
            return [[nums[idx]]]
        else:
            ret = self.find_subsets(nums, idx + 1)
            rn = len(ret)
            for i in range(rn):
                l = copy.deepcopy(ret[i])
                l.append(nums[idx])
                ret.append(l[:])
            ret.append([nums[idx]])
            return ret
                
    
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 0:
            return [[]]
        else:
            return [[]] + self.find_subsets(nums, 0)