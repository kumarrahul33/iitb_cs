from functools import reduce
from termios import VLNEXT
from xmlrpc.client import MAXINT


def minCost(values):
    r"""
        This function accepts list
        It returns the result as cost.
    """
    if(len(values) == 3):
        # return reduce(lambda x,y:x*y, values)
        return values[0]*values[1]*values[2]

    # case1 = values[0]*values[1]*values[-1]
    # case2 = values[0]*values[1]*values[2]
    # case3 = values[0]*values[-1]*values[-2]

    # case1_arr = values[1:]
    # case2_arr = values[3:]
    # case3_arr = values[1:-2]

    # return min(case1 + minCost(case1_arr), case2 + minCost(case2_arr), case3 + minCost(case3_arr)) 
    temp_values = values[:] 
    temp_values.append(values[0])
    res = MAXINT 
    for i in range(len(values)):
        temp_cost = temp_values[i]*temp_values[i+1]*temp_values[i-1]
        res = min(res,temp_cost + minCost(values[0:i] + values[i+1:len(values)]))
        
    return res

if __name__ == "__main__":
    import argparse
    CLI=argparse.ArgumentParser()
    CLI.add_argument("--values",  nargs="*",  type=int, default=[1, 2, 3])
    args = CLI.parse_args()
    print("values: %r" % args.values)
    cost = minCost(args.values)
    print(cost)