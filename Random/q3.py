class Solution(object):
    def lengthOfLongestSubstring(self,s):
        if (len(s)<2):
            return len(s)
        m = -1
        for i in range(len(s)):
            d = {s[i]:1}
            j=i+1
            while(True):
                if (j == len(s) or d.get(s[j])!=None):
                    if (m<j-i):
                        m=j-i
                    break
                d[s[j]]=1
                j+=1
            i=j
        return max(0,m)

s = input()
print(lengthOfLongestSubstring(s))