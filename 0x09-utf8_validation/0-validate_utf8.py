#!/usr/bin/python3
'''Python Module'''


def validUTF8(data):
    '''Validator for UTF-8 encoding'''
    bytes = 0
    for int in data:
        int = bin(int).replace('0b', '').rjust(8, '0')
        if bytes != 0:
            bytes -= 1
            if not int.startswith('10'):
                return False
        elif int[0] == '1':
            bytes = len(int.split('0')[0]) - 1
    return True
