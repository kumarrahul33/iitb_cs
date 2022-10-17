from functools import reduce

def f(x,y):
    print (x,y)
    return (x+y)

l=[1,2,3,4,5,6]
v = reduce (f,l,100)
print(v)