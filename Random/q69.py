class Solution:
    def mySqrt(self, x: int) -> int:
        l=0
        r=x
        while(l<r):
            mid = l+(r-l)//2
            if(mid*mid<=x):
                if((mid+1)*(mid+1)>x):
                    return mid
                l=mid+1
            else:
                r=mid-1

        return r

o = Solution()
print(o.mySqrt(int(input())))