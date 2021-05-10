#!/usr/bin/python3
'''Python Module'''


def minOperations(n):
    '''Script to calculate the minimun number of ops needed'''
    number_ops = 0
    # We try to reduce n to 1
    while n != 1:
        for num in range(2, n+1):
            # If n can be divisible we take account of that op and reduce n
            if (n % num == 0):
                # We acumulate the number of operations needed
                number_ops += num
                # And reduce n
                n = n // num
    return number_ops
