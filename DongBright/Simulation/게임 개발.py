"""
Project: 동빈나_구현_개임 개발
Date: 2022.01.04.화.
"""

N, M = map(int, input().split())
A, B, d = map(int, input().split())
# d = 0 (북), d = 1 (동), d = 2 (남), d = 3 (서)
map = [list(map(int, input().split())) for _ in range(N)]
count_tile = 1
count_not_move = 0

while True:
    if count_not_move == 4:
        if d == 0:
            if map[A + 1][B] == 1:
                break
            A += 1
            count_tile += 1
            count_not_move = 0
        elif d == 1:
            if map[A][B - 1] == 1:
                break
            B -= 1
            count_tile += 1
            count_not_move = 0
        elif d == 2:
            if map[A - 1][B] == 1:
                break
            A -= 1
            count_tile += 1
            count_not_move = 0
        elif d == 3:
            if map[A][B + 1] == 1:
                break
            B += 1
            count_tile += 1
            count_not_move = 0
        continue
    d = (d + 3) % 4
    map[A][B] = 1
    if d == 0:
        if map[A - 1][B] != 1:
            A -= 1
            count_tile += 1
            count_not_move = 0
        else:
            count_not_move += 1
    elif d == 1:
        if map[A][B + 1] != 1:
            count_tile += 1
            count_not_move = 0
            B += 1
        else:
            count_not_move += 1
    elif d == 2:
        if map[A + 1][B] != 1:
            count_tile += 1
            count_not_move = 0
            A += 1
        else:
            count_not_move += 1
    elif d == 3:
        if map[A][B - 1] != 1:
            count_tile += 1
            count_not_move = 0
            B -= 1
        else:
            count_not_move += 1

print (count_tile)
