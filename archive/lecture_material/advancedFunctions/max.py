import functools

l = [40,1,2,100,3,1002,4,5,6,222,7]

def f (x,y):
	print (x,y)
	if x>y:
		return x
	else:
		return y

r = functools.reduce (f,l)

print (r)

r = functools.reduce(f,[100,4])
print (r)

r = functools.reduce(f,[100])
print (r)
