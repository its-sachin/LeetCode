class Solution:

    def aa(self,s,d):
        if(s==""):
            return 1
            
        if( s[0]=='0'):
            return 0

        if(len(s)==1):
            return 1

        a = (ord(s[0])-48)*10+ord(s[1])-48

        if(a>26):
            t = d.get(s[1:])
            if(t==None):
                t = self.aa(s[1:],d)
                d[s[1:]]=t
            return t
        else:
            t = d.get(s[1:])
            u = d.get(s[2:])

            if(t==None):
                t = self.aa(s[1:],d)
                d[s[1:]]=t

            if(u==None):
                u = self.aa(s[2:],d)
                d[s[2:]]=u
            return t + u

    def numDecodings(self, s: str):
        if(s==""):
            return 0
        d={}
        return self.aa(s,d)

o = Solution()
print(o.numDecodings(input()))