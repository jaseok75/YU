"""
Project: 동빈나_정렬_두 배열의 원소 교체
Date: 2022.01.06.목
"""

N, K = map(int, input().split())
arr_A = list(map(int, input().split()))
arr_B = list(map(int, input().split()))
change_arr_A = []
change_arr_B = []
temp = 0

for i in range(K):
    max_a = max(arr_A)
    min_a = min(arr_A)
    max_b = max(arr_B)
    c_arr_a = arr_A
    c_arr_b = arr_B
    if max_a <= max_b:
        change_arr_A.append(max_b)
        change_arr_B.append(min_a)
        arr_A.remove(min_a)
        arr_B.remove(max_b)
    else:
        break

change_arr_A.extend(arr_A)

print(sum(change_arr_A))
