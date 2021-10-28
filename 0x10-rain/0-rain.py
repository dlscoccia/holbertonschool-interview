#!/usr/bin/python3
'''python module'''


def rain(walls):
    '''rain function'''
    rain_water = 0

    for i in range(1, len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]

        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        rain_water = rain_water + (min(left, right) - walls[i])
    return rain_water
