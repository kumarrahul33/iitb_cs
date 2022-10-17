from functools import reduce

def vowerFilter(l) :
    if l in ["a","e","i","o","u"] : return True
    return False

def loadList(i):
    with open(i, 'r') as data:
            dataRead = data.read()
            data_into_list = dataRead.split(" ")
    return data_into_list

def avgVowel(fileList):
    files = []
    for i in fileList:
        data_into_list = loadList(i)
        for i in range(len(data_into_list)):
            word = data_into_list[i]
            data_into_list[i] = filter(vowerFilter,word)

        data_into_list = map(lambda x: len(x), data_into_list)
        files.append(data_into_list)

    for i in range(len(files)):
        files[i] = reduce(lambda x,y: x+y , files[i])/float(len(files[i]))
    return (files)

def avgLength(fileName):
    files = []
    for i in fileList:
        data_into_list = loadList(i)
        data_into_list = map(lambda x: len(x), data_into_list)
        files.append(data_into_list)

    for i in range(len(files)):
        files[i] = reduce(lambda x,y: x+y , files[i])/float(len(files[i]))
    
    return(files)


#change the entries of this with the filenames to be analysed
fileList = ["file1.txt", "file2.txt", "file3.txt","file4.txt"]

print(avgVowel(fileList))
print(avgLength(fileList))