"""
Project: 동빈나_구현_왕실의 나이트
Date: 2022.01.04.화.
"""

pos = input()
pos_row = pos[1]
pos_col = pos[0]
row = 0
col = 0
count = 0

move_row = [-2, -1, 1, 2, 2, 1, -1, -2]
move_col = [1, 2, 2, 1, -1, -2, -2, -1]

for i in range (8):
    row = ord(pos_row) + move_row[i]
    col = ord(pos_col) + move_col[i]
    if row >= ord('1') and row <= ord('8') and col >= ord('a') and col <= ord('h'):
        count += 1

print (count)
