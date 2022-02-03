
"""
Project: 동빈나_정렬_위에서 아래로
Date: 2022.01.06.목
"""
N = int(input())
sequence = []

def quick_sort(array):
    if len(array) <= 1:
        return array

    pivot = array[0]
    tail = array[1:]

    left_side = [x for x in tail if x <= pivot]
    right_side = [x for x in tail if x > pivot]

    return quick_sort(left_side) + [pivot] + quick_sort(right_side)

for i in range(N):
    number = int(input())
    sequence.append(number)

for i in range(N):
    max_number = sequence[i]
    max_number_index = i
    temp = 0
    for j in range(i + 1, N):
        if max_number < sequence[j]:
            max_number = sequence[j]
            max_number_index = j
    if max_number != sequence[i]:
        temp = sequence[i]
        sequence[i] = sequence[max_number_index]
        sequence[max_number_index] = temp

print(sequence)
