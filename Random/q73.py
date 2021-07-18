class Solution:
    def setZeroes(self, matrix):
        d={}
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if(matrix[i][j]==0):
                    if(d.get(i)==None):
                        d[i]=[j]
                    else:
                        d[i].append(j)
        done = {}
        for k in d:
            for i in range(len(matrix[k])):
                matrix[k][i]=0
            for j in d[k]:
                if(done.get(j)==None):
                    for i in range(len(matrix)):
                        matrix[i][j]=0  
                    done[j]=True

o = Solution()

matrix=[[0,1,2,0],[3,4,5,2],[1,3,1,5]]
o.setZeroes(matrix)
print(matrix)
        