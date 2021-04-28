#!/usr/bin/python3
'''Python Module'''


def canUnlockAll(boxes):
    '''
    Script that checks if all boxes can be opened with given keys
    '''
    if len(boxes) == 0:
        return False
    open = []

    for box in boxes:
        if len(box) == 0:
            break
        for key in box:
            if key > 0 and key <= len(boxes) - 1:
                if key not in open:
                    open.append(key)

    return True if len(open) == len(boxes) - 1 else False
