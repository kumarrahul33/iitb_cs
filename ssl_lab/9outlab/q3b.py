import sqlite3

con = sqlite3.connect("ipl.db")
cursor = con.cursor()

cursor.execute("SELECT match_id,venue_name FROM MATCH")
total_runs = dict()
count_matches = dict()
matches = cursor.fetchall()

for match in matches:
    cursor.execute(f"SELECT sum(runs_scored), sum(extra_runs) FROM BALL_BY_BALL WHERE match_id={match[0]}")
    sub_tot = cursor.fetchone()

    if sub_tot[0] is None or sub_tot[1] is None:
        continue

    if not match[1] in total_runs:
        total_runs[match[1]] = 0
        count_matches[match[1]] = 0
    total_runs[match[1]] += (sub_tot[0] + sub_tot[1])
    count_matches[match[1]] += 1

results = []
for key in total_runs.keys():
    results.append((key, total_runs[key]/count_matches[key]))

for to_print in sorted(results, key=lambda t: (-t[1], t[0])):
    print(to_print[0], end=",")
    print("{0:.2f}".format(to_print[1]))