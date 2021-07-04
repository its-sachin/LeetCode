class Solution:
    def buildArray(self, nums):
        a = [0]*len(nums)
        for i in range(len(nums)):
            a[i]=nums[nums[i]]

        return a