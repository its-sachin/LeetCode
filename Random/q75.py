import math; inf= 1e18; mod =10**9+7

class Solution:
    def sortColors(self, nums):
        i,j,k=-1,-1,-1
        while(k<len(nums)-1):
            if(nums[k+1]==2):
                k+=1
            elif(nums[k+1]==1):
                k+=1
                j+=1
                nums[k],nums[j] = nums[j],nums[k]
            else:
                k+=1
                j+=1
                i+=1
                nums[k],nums[j] = nums[j],nums[k]
                nums[j],nums[i] = nums[i],nums[j]

o = Solution()
a = [1,2,1,0,0,1,2,0]
o.sortColors(a)
print(a)
            
