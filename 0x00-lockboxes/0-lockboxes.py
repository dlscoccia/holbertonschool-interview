#!/usr/bin/python3
'''Python Module'''


def canUnlockAll(boxes):
    '''
    Script that checks if all boxes can be opened with given keys
    '''
    if len(boxes) == 0:
        return False
    open = [0, ]
    idx = 0
    for box in boxes:
        for key in box:
            if key <= len(boxes) - 1 and key != idx:
                if key not in open:
                    open.append(key)
        idx += 1
    return True if len(open) == len(boxes) else False
