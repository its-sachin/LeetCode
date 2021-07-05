import math; inf= 1e18; mod =10**9+7

class Solution:
    def kidsWithCandies(self, candies, extraCandies: int):
        m = candies[0]
        for i in range(1,len(candies)):
            if(candies[i]>m):
                m=candies[i]

        for i in range(len(candies)): 
            if(candies[i]+extraCandies>=m):
                candies[i]=True
            else:
                candies[i]=False
        return candies