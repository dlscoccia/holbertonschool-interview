#!/usr/bin/python3
'''Python Module'''


def minOperations(n):
    '''Script to calculate the minimun number of ops needed'''
    # Smallest divisible number for given n
    min_chunk = [2, 3, 5, 7]
    # Num of operations needed
    min_ops = 0
    # We calculate how many chunks we need to reduce n to 1
    if (n == 1):
        min_ops = 1
    elif (n >= 2):
        while n != 1:
            for num in min_chunk:
                # if it is divisible, we add the chunk and reduce n
                if (n % num == 0):
                    min_ops += num
                    n = n/num
    return min_ops
