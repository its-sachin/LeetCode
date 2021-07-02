
def allEven(d):
    once = False
    for i in d:
        if(d[i]%2==1):
            if(once):
                return False
            else:
                once =True
    return True
def wonderfulSubstrings(word: str) -> int:
    c=0
    for i in range(len(word)):
        d={'a':0,'b':0,'c':0,'d':0,'e':0,'f':0,'g':0,'h':0,'i':0,'j':0}
        d[word[i]]+=1
        c+=1
        for j in range(i+1,len(word)):
            d[word[j]]+=1
            if(allEven(d)):
                c+=1
            

    return c

print(wonderfulSubstrings("fiabhedce"))
                

        