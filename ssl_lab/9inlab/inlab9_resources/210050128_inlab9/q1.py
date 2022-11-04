import requests
from bs4 import BeautifulSoup
import re
import sys


try:
    page = requests.get("https://www.cse.iitb.ac.in/academics/courses.php")
except:
    print("error in getting the page")

def check_input(course):
    temp = course[:]
    if re.sub("CS[0-9]{3}","",temp) != "":
        return False
    return True

def finder(course,data):
    if not check_input(course):
        return "NOT FOUND"

    univ = ["NUS","SFU","NTU","Geneva","CHUK","KAIST","DTU"]
    # curr_univ = ""
    count = 0
    final_str = ""
    for i in range(len(data)):
        if data[i] in univ:
            # curr_univ = data[i] 
            final_str += ";"+data[i]+":"
        if course in data[i]: #or data[i] == course+"(m)" or data[i] == course+"M" :
            count += 1
            final_str += data[i-1]+","

    if not count :
        return "NOT FOUND"

    if final_str[0] == ";":
        final_str = final_str[1:]
    final_str.replace(',:',':')
    # final_str.replace(r'[A-Za-z]+:;','')
    final_str = re.sub("[A-Za-z]+:;","",final_str)
    final_str = re.sub("[A-Za-z]+:$","",final_str)
    final_str = re.sub(",;",";",final_str)

    final_data = final_str.split(';')
    final_data.sort()
    if(final_data[0] == ''):
        final_data = final_data[1:]
    # print(final_data)
    final_str = ""
    for a in final_data:
        final_str+=a+";"

    final_str = re.sub("[,;]+$","",final_str)
    # final_str = re.sub(";$","",final_str)
    return final_str
soup = BeautifulSoup(page.content,'html.parser')
course_table = soup.select('div.collapsible-body')
# course_table = soup.

# print(course_table)
data = ""
for a in soup:
    data = data + a.text
data_list =data.split()
data_list = data_list[data_list.index("Exchange"):]
data_list[data_list.index("(ML)")] = "CS3243 (AI), CS3244 (ML)"
data_list[data_list.index("CR")] = "S403011 CR"
# print(data_list)

print(finder(sys.argv[1],data_list))
# print(sys.argv[1])
