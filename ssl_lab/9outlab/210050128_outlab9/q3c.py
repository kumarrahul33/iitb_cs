import sqlite3

connection = sqlite3.connect('ipl.db')
cursor = connection.cursor()

cursor.execute("SELECT player_id, player_name FROM PLAYER")
final_runs = dict()
players = cursor.fetchall()

for batsman in players:
    cursor.execute(f"SELECT sum(runs_scored) FROM BALL_BY_BALL WHERE striker={batsman[0]}")
    match_runs = cursor.fetchone()[0]

    if match_runs is None:
        continue
    key = f"{batsman[0]}--{batsman[1]}"
    if key not in final_runs:
        final_runs[key] = 0

    final_runs[key] += match_runs 


res = []
for player_key in final_runs:
    id,name = player_key.split('--')
    res.append((id, name, final_runs[player_key]))

res = sorted(res,key=lambda r:(-r[2], r[1]))

for i in range(20):
    print(f"{res[i][0]},{res[i][1]},{res[i][2]}")

