"""
Project: 동빈나_그리디_숫자 카드 게임
Date: 2022.01.04.화.
"""

N, M = map(int, input().split())
list_card = [list(map(int, input().split())) for _ in range(N)]
first_select = []

for i in range (N):
    # 각 행의 가장 작은 수와 그 위치 저장
    min_list_card = min(list_card[i])
    first_select.append((i, min_list_card))

sort_card = sorted(first_select, key = lambda x : -x[1])

print (sort_card[0][1])
