import sqlite3

con = sqlite3.connect("ipl.db")
cursor = con.cursor()

cursor.execute("SELECT player_id, player_name FROM PLAYER")
total_runs = dict()
players = cursor.fetchall()

for player in players:
    cursor.execute(f"SELECT sum(runs_scored) FROM BALL_BY_BALL WHERE striker={player[0]}")
    sub_tot = cursor.fetchone()[0]
    if sub_tot is None:
        continue

    key = f"{player[0]}$^{player[1]}"
    if not key in total_runs:
        total_runs[key] = 0
    total_runs[key] += sub_tot

results = []
for player_key in total_runs.keys():
    id,name = player_key.split('$^')
    results.append((id, name, total_runs[player_key]))

for to_print in sorted(results, key=lambda t: (-t[2], t[1]))[:20]:
    print(to_print[0], end=",")
    print(to_print[1], end=",")
    print(to_print[2])