import sqlite3

connection = sqlite3.connect('ipl.db')
cursor = connection.cursor()

connection.execute("DROP TABLE IF EXISTS POINTS_TABLE;")
connection.execute('''CREATE TABLE POINTS_TABLE
         (team_id INT PRIMARY KEY,
         team_name TEXT,
         points INT DEFAULT 0,
         nrr REAL DEFAULT 0);''')

connection.execute("INSERT INTO POINTS_TABLE (team_id, team_name)  SELECT * FROM TEAM;")

cursor.execute("SELECT team1,team2,match_winner,win_type,win_margin FROM MATCH;")
point_nrr = dict() # [points, nrr] as the values with team id as the key
match = cursor.fetchone()
while not match is None:
    match
    if not match[0] in point_nrr:
        point_nrr[match[0]] = [0,0]
    if not match[1] in point_nrr:
        point_nrr[match[1]] = [0,0]

    if match[2] is None or match[3] == 'Tie':
        point_nrr[match[0]][0] += 1
        point_nrr[match[1]][0] += 1
        print(f"{match[2] is None} is the thing")
    else:
        point_nrr[int(match[2])][0] += 2
        nrr_del = 0
        losing_team = match[0] if match[1]==match[2] else match[1]
        if not match[4] is None:
            if match[3] == 'runs':
                nrr_del = match[4]/20
            elif match[3] == 'wickets':
                nrr_del=match[4]/10

        point_nrr[match[2]][1] += nrr_del
        point_nrr[losing_team][1] -= nrr_del

    match = cursor.fetchone()

for key in point_nrr.keys():
    cursor.execute("UPDATE TEAM SET points={0}, nrr={1} WHERE team_id={2};".format(point_nrr[key][0], point_nrr[key][1], key))

cursor.execute("SELECT * FROM TEAM ORDER BY points DESC, nrr DESC")