class Solution:
    def climbStairs(self, n: int) -> int:
        i=1
        j=1
        k=1
        while(k<n):
            i,j=j,i+j
            k+=1
        return j

o = Solution()
print(o.climbStairs(int(input())))