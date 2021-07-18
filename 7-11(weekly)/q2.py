class Solution:
    
    def countPalindromicSubsequence(self, s: str):
        d = {}
        for i in range(len(s)):
            if(d.get(s[i]) is None):
                d[s[i]]=[i]
            else:
                d[s[i]].append(i)
        ans=0
        for i in d:
            if(len(d[i])>1):
                ans+=(d[i][len(d[i])-1]-d[i][0]-1)
                if(len(d[i])>2):
                    ans-=len(d[i])-3

                for j in d:
                    if(j!=i and len(d[j])>1 and not(len(d[j]) == 2 and d[j][0]<d[i][0])):
                        l=True
                        for k in d[j]:
                            if(d[i][0]<k<d[i][len(d[i])-1]):
                                if(l):
                                    l=False
                                else:
                                    ans-=1


        return ans

o = Solution()
print(o.countPalindromicSubsequence(input()))


