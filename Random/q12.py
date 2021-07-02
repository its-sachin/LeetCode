class Solution:
    def intToRoman(self, num: int):
        d = {1: ['I', 'X', 'C', 'M'], 2: ['II', 'XX', 'CC', 'MM'], 3: ['III', 'XXX', 'CCC', 'MMM'], 4: ['IV', 'XL', 'CD'], 5: ['V', 'L', 'D'], 6: ['VI', 'LX', 'DC'], 7: ['VII', 'LXX', 'DCC'], 8: ['VIII', 'LXXX', 'DCCC'], 9: ['IX', 'XC', 'CM']}
        ans = ""
        i=0
        while(num!=0):
            digit = num%10
            if(digit!=0):
                ans = d.get(digit)[i]+ans
            i+=1
            num=num//10
        return ans

d = {}
a = ['I','X','C','M']
f = ['V','L','D']
for i in range(1,10):
    d[i]=[]
    if(i<4):
        for j in range(4):
            s = ""
            for k in range(i):
                s+=a[j]
            d[i].append(s)
    elif(i==4):
        for j in range(3):
            s = a[j]+f[j]
            d[i].append(s)
    elif(i==5):
        for j in range(3):
            d[i].append(f[j])
    elif(i<9):
        for j in range(3):
            s = f[j]
            for k in range(i-5):
                s+=a[j]
            d[i].append(s)
    else:
        for j in range(3):
            s = a[j]+a[j+1]
            d[i].append(s)  

a = Solution()
print(a.intToRoman(int(input())))
# print(d)