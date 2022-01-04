"""
Project: 동빈나_그리디_큰 수의 법칙
Date: 2022.01.04.화.
"""

N, M, K = map (int, input().split())
number = [int(x) for x in input().split()]
big_number = 0
count = 0

number.sort(reverse=True)

# 덧셈의 과정을 M번 반복
for i in range(M):
    # 하나의 인덱스에서는 K번만 더할 수 있음
    if count == K:
        # 가장 큰 수가 아닌 다음 수를 더함
        big_number += number[1]
        # 다시 count를 0으로 만들어주어 다음 더할 때는 가장 큰 수를 더할 수 있게 함
        count = 0
        continue
    # list에서 가장 큰 수를 더함
    big_number += number[0]
    count += 1

print(big_number)
