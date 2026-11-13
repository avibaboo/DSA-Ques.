class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        curr = 0
        mx = nums[0]
        for i in range(len(nums)):
            curr += nums[i]
            mx = max(mx , curr)
            if(curr < 0) : curr = 0
            
        return mx
        