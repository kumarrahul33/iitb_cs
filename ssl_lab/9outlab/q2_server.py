from xmlrpc.server import SimpleXMLRPCServer
from xmlrpc.server import SimpleXMLRPCRequestHandler
from magic import getMagicNumber

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)
    noisy = False

# TODO: Silence the logs on the server-side

with SimpleXMLRPCServer(('localhost', 8080),
                        requestHandler=RequestHandler, logRequests=False) as server:
    server.register_introspection_functions()

    server.register_function(getMagicNumber)
    # def doMagic(num):
    #     a = getMagicNumber(num)
    #     print(a)
    #     return a

    @server.register_function
    def kill():
        server._BaseServer__shutdown_request = True
        return 0

    server.serve_forever()