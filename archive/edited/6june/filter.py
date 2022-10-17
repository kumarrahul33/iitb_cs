from fcntl import F_GETLEASE


def f(x):
    if(x%2 == 0): return True
    else: return False

l = [1,2,3,4,5,6,7,8,9]
 
m = filter(f, l)
print(m)