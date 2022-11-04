from datetime import datetime
import sys
from bs4 import BeautifulSoup
import requests
import re


f = open("announcements.txt",'w')
LOGIN_URL = "https://moodle.iitb.ac.in/login/index.php"
BASE_URL = "https://moodle.iitb.ac.in/"

s =requests.Session()
def scrape_page(link):
    a_page = s.get(link)
    soup = BeautifulSoup(a_page.text,'html.parser')
    a_author = [a.text for a in soup.select("div div.w-100.flex-column header.mb-2 div.flex-column div.mb-3 a")]
    a_time = [a.text for a in soup.select("time")]
    a_title = [a.text for a in soup.select("div div.w-100.flex-column header.mb-2 div.flex-column h3.mb-0")]
     
    res = [a_author,a_title,a_time]
    return res 

def fetch_announcements(page):
    soup = BeautifulSoup(page,'html.parser') 
    length = len(soup.select("tbody tr.discussion:has(div.pl-0) a.w-100"))

    for i in range(length):
        link = soup.select("tbody tr.discussion:has(div.pl-0) a.w-100")[i]['href']
        
        data.append(scrape_page(link))

data = []
def load_data():
    r = s.get(LOGIN_URL)
    pattern = '<input type="hidden" name="logintoken" value="\w{32}">'
    token = re.findall(pattern, r.text)
    token = re.findall("\w{32}", token[0])
    payload = {'username': sys.argv[1], 'password': sys.argv[2], 'anchor': '', 'logintoken': token[0]}
    s.post(LOGIN_URL,data=payload)
    page = s.get(BASE_URL+"my/")

    soup = BeautifulSoup(page.text,'html.parser')

    ssl_lab_link = [a['href'] for a in soup.select("a.list-group-item:-soup-contains('CS 251-2022-1')")][0] 
    page_ssl_lab = s.get(ssl_lab_link)
    soup = BeautifulSoup(page_ssl_lab.text,'html.parser')
    announcement_page_link = [a['href'] for a in soup.select("li.forum a")][0]
    announcement_page = s.get(announcement_page_link)

    fetch_announcements(announcement_page.text)

def print_results(author):
    load_data()

    res_arr = []
    for elem in data:
        for i in range(len(elem[0])):
            if elem[0][i] == author:
                res_arr.append(elem[2][i]+"; "+elem[1][i])
    res_arr = list(set(res_arr))
    for i in range(len(res_arr)):
        time_date_str = (re.findall("[0-9]* [A-Za-z]* 2022, [0-9]*:[0-9]* [A-Z]{2}",res_arr[i]))[0]
        time_date = datetime.strptime(time_date_str,'%d %B %Y, %I:%M %p')
        res_arr[i] = [time_date,res_arr[i]]
    res_arr.sort()
    for elem in res_arr:
        print(elem[1],file=f)
print_results(sys.argv[3])