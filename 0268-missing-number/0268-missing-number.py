class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums)
        exp_sum = n*(n+1) //2
        act_sum =sum(nums)
        return exp_sum - act_sum