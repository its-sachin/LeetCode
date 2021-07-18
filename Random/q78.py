class Solution:
    def subsets(self, nums):

        if(len(nums)==0):
            return [[]]

        ans = []
        l = self.subsets(nums[:-1])
        for k in l:
            ans.append(k)
            ans.append(k+[nums[-1]])
        return ans

a = [1,2,3]
o = Solution()
print(o.subsets(a))


  