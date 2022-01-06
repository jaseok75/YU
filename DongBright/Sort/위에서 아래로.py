"""
Project: 동빈나_정렬_위에서 아래로
Date: 2022.01.06.목
Content: 선택 정렬
"""
N = int(input())
sequence = []

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
