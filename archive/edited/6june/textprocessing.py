#PLEASE USE python (not python3 or python3.5)
from functools import reduce


def vowerFilter(l) :
    if l in ["a","e","i","o","u"] : return True
    return False

def avgVowel(fileList):
    files = []

    for i in fileList:
        with open(i, 'r') as data:
            dataRead = data.read()
            data_into_list = dataRead.split(" ")
            for i in range(len(data_into_list)):
                word = data_into_list[i]
                data_into_list[i] = filter(vowerFilter,word)

            data_into_list = map(lambda x: len(x), data_into_list)
            files.append(data_into_list)

    for i in range(len(files)):
        files[i] = reduce(lambda x,y: x+y , files[i])/float(len(files[i]))

    files.sort(reverse=True)
    return (files)

#change the entries of this with the filenames to be analysed
fileList = ["file1.txt", "file2.txt", "file3.txt","file4.txt"]

print(avgVowel(fileList)[0:3])