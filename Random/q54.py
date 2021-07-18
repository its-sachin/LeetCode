class Solution:
    def spiralOrder(self, grid):
        n = len(grid)
        m = len(grid[0]) 
        ans = []
        i=0
        j=0
        while(i<=(n-1)//2 and j<=(m-1)//2):
    
            for k in range(j,m-j):
                ans.append(grid[i][k])
            for k in range(i+1,n-i):
                ans.append(grid[k][m-i-1])
            if(not i==n-i-1):
                for k in range(m-i-2,i-1,-1):
                    ans.append(grid[n-i-1][k])
            if(not j==m-j-1):
                for k in range(n-i-2,i,-1):
                    ans.append(grid[k][j])

            i+=1
            j+=1
            
        return ans