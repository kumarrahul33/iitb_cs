def mult2(num):
    x = 0
    while(x < num):
        x += 2
        yield(x)
for e in mult2(50):
    print(e)
g = list(mult2(50))
print(g)
