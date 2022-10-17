def find(l,e):
	if (l[0] == e): return 0
	else:
		return (find(l[1:],e)+1)

print (find([222,1,44,1],4))
print (find([1,222],222))
