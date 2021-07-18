class Solution:
    def getConcatenation(self, nums):
        b=nums[0:]
        for i in nums:
            b.append(i)
        return b