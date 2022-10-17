import functools
def mult5(x):
    if(x%5 == 0):
        return True
    else:
        return False

list1 = [1,2,3,5,6,4,7,55,5,50,10]
list2 = list(filter(mult5,list1))
print(list2)


list3 = list(map(lambda x: x-1,list2))
list4 = functools.reduce(lambda x,y: x+y, list1)

list5 = list2[1:]
print(list3)
print(list4)
print(list5)
