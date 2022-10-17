def power(l):
    powerList = [[]]
    for i in range(1,len(l)+1):
        for j in range(len(l) - i + 1):
            powerList.append(l[j:j+i])
    return powerList

l = [1,2,3]
print(power(l))