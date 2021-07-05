import math; inf= 1e18; mod =10**9+7


class Solution:
    def maximumWealth(self, accounts):
        for i in range(len(accounts)):
            for j in range(1,len(accounts[i])):
                accounts[i][0]+=accounts[i][j];

        accounts.sort(reverse=True)
        return accounts[0][0]

o = Solution
print(o.maximumWealth(o,[[1,5],[7,3],[3,5]]))
