
from operator import mod


def add(arg1, arg2):
    r"""
        This function accepts two arguments - arg1 and arg2.
        It returns the result of the operation (arg1 + arg2).

        You are expected to think of corner cases,
        and appropriately raise Exception.
    """
    try:
        return arg1+arg2
    except:
        raise Exception("incompatibe for addition")


def subtract(arg1, arg2):
    r"""
        This function accepts two arguments - arg1 and arg2.
        It returns the result of the operation (arg1 - arg2).

        As the previous function, you are expected to think of corner cases,
        and appropriately raise Exception.
    """
    try:
        return arg1-arg2
    except:
        raise Exception("incompatibe for substraction")

def divide(arg1, arg2):
    r"""
        This function accepts two arguments - arg1 and arg2.
        It returns the result of the operation (arg1 / arg2).

        You are expected to think of corner cases, and appropriately raise Exception.
    """
    try: 
        return arg1/arg2
    except:
        raise Exception("incompatibe for division")


def str_left_rotate(arg1, arg2):
    r"""
        This function should left rotate a string by the specified amount.
        arg1 signifies the input string and arg2 signifies the amount of rotation.

        Example - 
        1. str_left_rotate("hello", 2) should return "llohe"
        2. str_left_rotate("hello", 1) should return "elloh"
        3. str_left_rotate("hello", 4) should return "ohell" and so on

        You are not to use any inbuilt string method, the implementation has to be
        done by you!!

        Again, you are expected to think of corner cases, and appropriately raise Exception.
    """
    try:
        r = arg2 % len(arg1)
        return arg1[r:] + arg1[0:r]
    except:
        raise Exception("provided arguments are not valid")

def apply(fn, args):
    r"""
        This is the API end-point available to the grader.
        The grader will supply the function pointer to this function,
        along with the arguments and expect the return value.

        Example - 
        1. apply(add, (2, 3)) will expect 5 as the answer.
        2. apply(subtract, (2, 3)) will expect -1 as the answer.
    """
    return (fn(args[0],args[1]))
