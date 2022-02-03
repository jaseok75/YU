"""
Project: 동빈나_이진 탐색_부품 찾기
Date: 2022.01.06.목
"""

N = int(input())
store = list(map(int, input().split()))
M = int(input())
order = list(map(int, input().split()))

def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return True
        elif array[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return False

store.sort()

for i in range(M):
    exist = binary_search(store, order[i], 0, N - 1)
    if exist:
        print("yes")
    else:
        print("no")
