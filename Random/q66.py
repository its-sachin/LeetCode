import math; inf= 1e18; mod =10**9+7
class Solution:
    def plusOne(self, digits):
        carry =1
        i=len(digits)-1
        while(carry ==1 and i>=0):
            digits[i]+=1
            if(digits[i]==10):
                digits[i]=0
                carry=1
            else:
                carry=0
            i-=1

        if(carry==1):
            digits=[1]+digits
        return digits