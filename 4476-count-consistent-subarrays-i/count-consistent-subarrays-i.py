class Solution:
    def countConsistent(self, nums: list[int]) -> int:
        n = len(nums)
        cnt = 0
        for i in range(n):
            mn = nums[i]
            bitor = nums[i]
            cnt+=1
            for j in range(i+1 ,n):
                bitor &= nums[j]

                if(nums[j] < mn):
                    mn = nums[j]
                
                if(bitor == mn):
                    cnt+=1
        
        return cnt