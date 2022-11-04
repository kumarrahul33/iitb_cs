import magic
from xmlrpc.server import SimpleXMLRPCServer, SimpleXMLRPCRequestHandler

class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)
    noisy = False
with SimpleXMLRPCServer(('localhost',8080),requestHandler=RequestHandler, logRequests=False) as server:
    server.register_introspection_functions()

    def kill():
        server._BaseServer__shutdown_request = True
        return 0

    server.register_function(magic.getMagicNumber,"doMagic")
    server.register_function(kill,"kill")

    server.serve_forever()

