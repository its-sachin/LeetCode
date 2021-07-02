
def maxProductDifference(nums) -> int:
    ma=nums[0]
    ma1=None
    mi=nums[0]
    mi1=None
    for i in nums[1:]:
        if(i>ma):
            ma1=ma
            ma=i
        elif(ma1==None or i>ma1):
            ma1=i
        if(i<mi):
            mi1=mi
            mi=i
        elif(mi1==None or i<mi1):
            mi1=i
            
    return (ma*ma1)-(mi*mi1)

print(maxProductDifference([1,6,7,5,2,4,10,6,4]))