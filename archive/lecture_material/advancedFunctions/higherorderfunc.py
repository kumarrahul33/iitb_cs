def scaleit(x):
    return lambda z : z*x

scale3 = scaleit(3)
print(scale3(3))


