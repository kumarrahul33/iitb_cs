def freq(l1,l2):
    commonList = []
    finalList = []
    for elem1 in l1:
        for elem2 in l2:
            if elem1 == elem2 and not elem1 in commonList:
                commonList.append(elem1)

    for elem1 in commonList:
        count = 0
        for elem2 in l1:
            if elem1 == elem2:
                count += 1
        
        for elem2 in l2:
            if elem1 == elem2:
                count += 1
        if count != 0:
            finalList.append([elem1, count])
    return finalList

L1 = [1,2,3,1,4]
L2 = [1,1,2,2,21,9,4] 

print(freq(L1,L2))