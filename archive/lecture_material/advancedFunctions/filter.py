
l = [1,2,3,4,5,6,7]

def f (x):
	if(x%2==0):
		return True
	else:
		return False

r = filter (lambda x: x%2,l)

print (*r)


#exercise 1: write your own filter function called myfiles
#exercise 2: filter based on freq counts


