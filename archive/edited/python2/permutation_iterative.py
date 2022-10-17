def permute(l):
    curr = [[]]
    temp = []
    for i in range(len(l)):
        
        for j in range(len(curr)):
            curr[j].append(l[i])
            for k in range(len(curr[j])):
                l1 = curr[j]
                l1[k], l1[0] = l1[0], l1[k]
                temp = temp +[l1]
                print(l1)
            
        curr = temp
        temp.clear()

    for i in curr:
        print(i)

permute(['a', 'b', 'c', 'd'])