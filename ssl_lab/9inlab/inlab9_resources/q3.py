import sys
import os

res = os.system("ping -c 5 " + sys.argv[1] + " > .useless && rm .useless")

print("YES" if not res else "NO")