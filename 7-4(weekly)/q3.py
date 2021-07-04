mod=10**9+7
class Solution:
    def countGoodNumbers(self, n):
        return (pow(5,n-n//2,mod)*pow(4,n//2,mod))%mod

o = Solution
print(o.countGoodNumbers(o,int(input())))