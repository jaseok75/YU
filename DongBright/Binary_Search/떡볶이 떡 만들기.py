"""
Project: 동빈나_이진 탐색_떡볶이 떡 만들기
Date: 2022.01.06.목
"""

import sys

N, M = map(int, sys.stdin.readline().split())
length = list(map(int, sys.stdin.readline().split()))
answer = 0

length.sort()
start = 0
end = length[-1]

while start <= end:
    mid = (start + end) // 2
    after_length = 0
    for i in length:
        if i > mid:
            after_length += (i - mid)
    if after_length < M:
        end = mid - 1
    else:
        answer = mid
        start = mid + 1

print(answer)
