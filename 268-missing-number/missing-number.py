class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        i=0
        while(1):
            if i not in nums:
                return i
            i+=1