mod=(10**9)+7
class Solution:

    def colorTheGrid(self, m: int, n: int):
        return (3*(pow(2,m-1,mod))*pow(m+1,n-1,mod))%mod

o = Solution()
m,n = map(int,input().split())
print(o.colorTheGrid(m,n))