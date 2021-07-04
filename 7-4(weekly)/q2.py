def m(d,s):
    if(d%s==0):
        return d//s
    return (d//s)+1

class Solution:
    
    def eliminateMaximum(self, dist, speed):
        a = []
        for i in range(len(dist)):
            a.append(m(dist[i],speed[i]))
        a.sort()
        c=0
        for i in range(len(a)):
            if(a[i]-i>0 or a[i]==0 and i==0):
                c+=1
            else:
                return c
        return c

o=Solution
print(o.eliminateMaximum(o,list(map(int,input().split())),list(map(int,input().split()))))