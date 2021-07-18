class Solution:
    def merge(self, nums1, m: int, nums2, n: int):
        i=m-1
        j=n-1
        k=n+m-1
        while(j>=0):
            if(i<0 or nums1[i]<=nums2[j]):
                nums1[k]=nums2[j]
                j-=1
                k-=1
            else:
                nums1[k]=nums1[i]
                i-=1
                k-=1

a = [1,2,4,6,8,0,0,0]
b = [-1,7,10]
o=Solution()
o.merge(a,5,b,3)
print(a)
