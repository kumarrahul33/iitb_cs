def series (k):
	x = 0
	n0=1
	n1=1
	while(x<k):
		if (x==0): 
			x=x+1
			yield (n0)
		if (x==1):
			x=x+1
			yield (n1)
		tmp = n0+n1
		n0=n1
		n1=tmp
		yield (n1)
		x=x+1

for e in series(10):
	print ('received value', e)

g = series (5) 
print (g)  # l is a generator, not unfolded if elements not needed

print (list(g))
