arr = [[-1 for i in range(1050)] for j in range(1050)]
def acker(m,n):
        if(arr[m][n] != -1 ): return arr[m][n]

        elif(m == 0):
            arr[m][n] = n+1 
            return n+1
        elif(m > 0 and n == 0):
            arr[m][n] = acker(m-1,1) 
            return acker(m-1,1)
        else: 
            arr[m][n] = acker(m-1,acker(m,n-1))
            return acker(m-1,acker(m,n-1))

print(acker(3,7))
