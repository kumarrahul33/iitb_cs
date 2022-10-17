def fact(n,res):
	if (n==0): return res 
	else: return fact(n-1,n*res)


print(fact(0,1))
print(fact(5,1))

