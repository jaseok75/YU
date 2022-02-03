"""
Project: 동빈나_그리디_1이 될 때까지
Date: 2022.01.04.화.
"""

N, K = map(int, input().split())
after_cal = N
count_cal = 0

while after_cal != 1:
    if after_cal % K == 0:
        after_cal /= K
        count_cal += 1
    else:
        after_cal -= 1
        count_cal += 1

print (count_cal)
