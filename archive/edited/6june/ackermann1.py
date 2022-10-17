def acker(m,n):
        if(m == 0):
            return n+1
        elif(m > 0 and n == 0):
            return acker(m-1,1)
        else: 
            return acker(m-1,acker(m,n-1))

print(acker(3,7))
