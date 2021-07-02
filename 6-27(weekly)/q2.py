def setlayer(grid,k,layer,ans,n,m):
    l = []
    i=layer-1
    for j in range(layer-1,m-layer+1):
        l.append(grid[i][j])
    j=m-layer
    for i in range(layer,n-layer+1):
        l.append(grid[i][j])
    i=n-layer
    for j in range(m-layer-1,layer-2,-1):
        l.append(grid[i][j])
    j=layer-1
    for i in range(n-layer-1,layer-1,-1):
        l.append(grid[i][j])

    nl = []
    for i in range(len(l)):
        nl.append(l[(i+k)%len(l)])

    j=layer-1
    for i in range(layer,n-layer+1):
        ans[i][j] = nl.pop()
    i=n-layer
    for j in range(layer,m-layer+1):
        ans[i][j] = nl.pop()
    j=m-layer
    for i in range(n-layer-1,layer-2,-1):
        ans[i][j] = nl.pop()
    i=layer-1
    for j in range(m-layer-1,layer-2,-1):
        ans[i][j] = nl.pop()
        
# def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
def rotateGrid(grid, k: int):
    n = len(grid)
    m = len(grid[0]) 
    ans = [[0 for i in range(m)] for j in range(n)]
    layer=1
    while((n-2*layer+1)>=0 and (m-2*layer+1)>=0 and not ((n-2*layer+1)==0 and (m-2*layer+1)==0)):
        setlayer(grid,k,layer,ans,n,m)
        layer+=1
    return ans


print(rotateGrid([[10,1,4,8],[6,6,3,10],[7,4,7,10],[1,10,6,1],[2,1,1,10],[3,8,9,2],[7,1,10,10],[7,1,4,9],[2,2,4,2],[10,7,5,10]],1))