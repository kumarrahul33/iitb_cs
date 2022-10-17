def f(x):
    return x*x

s= {1,3,4}
l = {1,2,3,4,5,6,7}

r = map(f,s)  #calling the function f on every element of s and then returning the consolidated list
print(list(r))

r = map(f,l)
print(r)