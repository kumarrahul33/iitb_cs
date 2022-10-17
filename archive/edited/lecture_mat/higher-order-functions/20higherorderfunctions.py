def f(g,l):
	return g(l)
def func1(l):
	sum=0
	for x in l:
		sum = sum+x
	return sum
def func2(l):
	prod=1
	for x in l:
		prod= prod*x
	print (prod)
	return prod 
def h(p,q,l):
	return p(q(l))
l = [1,2,3,4]
print (h(func1,func2,l)) // error-- find out where! (line 5) and why

v1 = f (func1,l)
v2 = f (func2,l)
print (v1,v2),
