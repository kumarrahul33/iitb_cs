import xmlrpc.client
import sys

if len(sys.argv) < 2:
    print("At least two arguments necessary for running the code")
    exit()
try:
    number = int(sys.argv[1])
except ValueError:
    print("The passed argument must be an int")
    exit()


server = xmlrpc.client.ServerProxy("http://localhost:8080")

print(server.getMagicNumber(number))
server.kill()