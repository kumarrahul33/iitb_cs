import sqlite3

connection = sqlite3.connect('ipl.db')
cursor = connection.cursor()

cursor.execute("DROP TABLE IF EXISTS POINTS_TABLE;")
cursor.execute('''CREATE TABLE POINTS_TABLE (team_id INT PRIMARY KEY, team_name TEXT, points INT DEFAULT 0, nrr REAL DEFAULT 0);''')

cursor.execute("INSERT INTO POINTS_TABLE (team_id, team_name)  SELECT * FROM TEAM;")

cursor.execute("SELECT team1,team2,match_winner,win_type,win_margin FROM MATCH;")
pn = dict() 
games = cursor.fetchall()

for i in range(len(games)):
    game = games[i]
    if game[0] not in pn:
        pn[game[0]] = [0,0]
    if game[1] not in pn:
        pn[game[1]] = [0,0]

    if (game[2] is None) or (game[2] == 'NULL') or game[3] == 'Tie':
        pn[game[0]][0] += 1
        pn[game[1]][0] += 1
    else:
        pn[int(game[2])][0] += 2
        earned_nrr = 0
        l_team = game[0] if game[1]==int(game[2]) else game[1]
        if game[4] is not None:
            if game[3] == 'runs':
                earned_nrr = game[4]/20
            elif game[3] == 'wickets':
                earned_nrr=game[4]/10

        pn[int(game[2])][1] += earned_nrr
        pn[l_team][1] -= earned_nrr


for elem in pn:
    cursor.execute(f"UPDATE POINTS_TABLE SET points={pn[elem][0]}, nrr={pn[elem][1]} WHERE team_id={elem};")

cursor.execute("SELECT * FROM POINTS_TABLE ORDER BY points DESC, nrr DESC")

for elem in cursor.fetchall():
    print(elem[0],end=",")
    print(elem[1],end=',')
    print(elem[2],end=",")
    print(("%.2f" % elem[3]))
