def canUnlockAll(boxes):
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