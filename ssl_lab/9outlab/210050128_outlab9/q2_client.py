import sys
import xmlrpc.client

if len(sys.argv) < 2:
    print("please provide an argument")
    exit()

try:
    a = int(sys.argv[1])
except:
    print("please provide a valid input")
    exit()

with xmlrpc.client.ServerProxy("http://localhost:8080") as proxy:
    print(proxy.doMagic(a))
    proxy.kill()

