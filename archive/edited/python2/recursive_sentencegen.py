def printSentence(o,s,v):
    if s == "he" or s == "she" or s=="it":
        print(s + " " + v + "s " + o + ".")
        print(s + " will " + v + " "+ o + "." )
        print(s + " " + v + "ed " + o+".")
    elif s == "we" or s == "they" or s=="I":
        print(s + " " + v + o + ".")
        print(s + " will " + v + " "+ o + "." )
        print(s + " " + v + "ed " + o+".")





def sentence(objects, subjects, verbs):
    if len(objects) == 0 :
        return
    else:
        for i in range(len(subjects)):
            for j in range(len(verbs)):
                printSentence(objects[0],subjects[i],verbs[j])
        return sentence(objects[1:],subjects,verbs)
    
	


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