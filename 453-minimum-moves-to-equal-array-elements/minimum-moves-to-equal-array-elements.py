class Solution:
    def minMoves(self, nums: list[int]) -> int:
        n = len(nums)
        sum=0
        low=+1e9+1
        for i in range(n):
            low=min(low,nums[i])
        for i in range(n):
            sum=sum+(nums[i]-low)
        return sum
          