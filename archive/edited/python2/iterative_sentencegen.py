# object = open('object.txt','r')
# o_list = object.split()
# for x in o_list:
# 	print(x,"\n")
# print(len(o_list))

def sentence(objects, subjects, verbs):
	for o in objects:
		for v in verbs:
			for s in subjects:
				print(s + " " + v + "s " + o + ".")
				print(s + " will " + v + " "+ o + "." )
				print(s + " " + v + "ed " + o+".")



objects = []
subjects = []
verbs = []

with open("Object.txt",'r') as f:
	for readline in f:
		for word in readline.split():
			objects.append(word)

with open("Subject.txt",'r') as f:
	for readline in f:
		for word in readline.split():
			subjects.append(word)

with open("verb.txt",'r') as f:
	for readline in f:
		for word in readline.split():
			verbs.append(word)

sentence(objects, subjects, verbs)