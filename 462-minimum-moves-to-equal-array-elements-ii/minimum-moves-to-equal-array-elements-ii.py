class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()
        n =len(nums)
        temp =nums[n//2]
        ans=0
        for i in range(n):
            ans=ans+ abs(temp-nums[i])
        return ans
        