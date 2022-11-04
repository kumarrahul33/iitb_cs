import sqlite3 as sq
import csv
import sys

try:
    zipCodesDB = sq.connect("zipcodesDB.db")

except:
    print("some error in creation db")

cursor = zipCodesDB.cursor()
cursor.execute("""
    CREATE TABLE zipcodesInfo (
        zip_code TEXT PRIMARY KEY,
        latitude REAL,
        longitude REAL,
        city TEXT,
        state TEXT,
        county TEXT
    )
""")

file =  open("zipcodes.csv")
csv_data = csv.reader(file)

first_entry = True

put_row = "INSERT INTO zipcodesInfo (zip_code, latitude, longitude, city, state, county) VALUES(?,?,?,?,?,?)"

for row in csv_data:
    if(first_entry):
        first_entry = False
        continue
    cursor.execute(put_row,row)

# select_all = "m = SELECT MAX(latitude) from zipcodesInfo WHERE state='AL'; SELECT * FROM zipcodesInfo WHERE latitude=@m AND state='AL')"
# select_max = "SELECT max(latitude) from zipcodesInfo WHERE state='AL'"
q_get_max = '''SELECT city from zipcodesInfo WHERE state='{0}' ORDER BY latitude DESC LIMIT 1'''
q_get_codes = '''select zip_code from zipcodesInfo where city='{0}' '''



cursor.execute(q_get_max.format(sys.argv[1]))
max_lat_temp = cursor.fetchone()
if max_lat_temp is None:
    print("NOT FOUND")
    exit()
max_lat = max_lat_temp[0]


# select_all = f"SELECT DISTINCT zip_code from zipcodesInfo WHERE state='AL' AND latitude={max_lat[0][0]}"

cursor.execute(q_get_codes.format(max_lat))
rows = cursor.fetchall()
res = []
for elem in rows:
    res.append(elem[0])
# print(max_lat[0][0])

print(",".join(res))
