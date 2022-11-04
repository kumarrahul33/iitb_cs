import sqlite3

connection = sqlite3.connect('ipl.db')
cursor = connection.cursor()


cursor.execute("SELECT match_id,venue_name FROM MATCH")
matches = cursor.fetchall()



count_matches = dict()
final_runs = dict()
final_ans = []

for match in matches:
    cursor.execute("SELECT sum(runs_scored), sum(extra_runs) FROM BALL_BY_BALL WHERE match_id={0}".format(match[0]))
    total_runs_per_match = cursor.fetchall()[0]

    if(total_runs_per_match[0] == None) and (total_runs_per_match[1] == None):
        continue

    if match[1] not in final_runs:
        final_runs[match[1]] = 0
        count_matches[match[1]] = 0
    final_runs[match[1]] += (total_runs_per_match[0] + total_runs_per_match[1])
    count_matches[match[1]] += 1

for stad in final_runs:
    final_ans.append((stad, final_runs[stad]/count_matches[stad]))

final_ans.sort(key=lambda r:(-r[1],r[0]))

for elem in final_ans:
    print(elem[0]+","+"{0:.2f}".format(elem[1]))


