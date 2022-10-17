def fact(n,temp):
    if(n==0):
        return temp
    
    else:
        return (fact(n-1,temp*n))

print(fact(3,1))
