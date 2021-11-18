#!/usr/bin/python3
'''Python Module'''


def minOperations(n):
    '''Script to calculate the minimun number of ops needed'''
    number_ops = 0
    idx = 2
    # We try to reduce n to 1
    while n > 1:
        if (n % idx == 0):
            # We acumulate the number of operations needed
            number_ops += idx
            # And reduce n
            n = n / idx
        else:
            idx += 1
    return number_ops
