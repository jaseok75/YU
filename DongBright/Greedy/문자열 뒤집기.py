"""
Project: 동빈나_그리디_문자열 뒤집기
Date: 2022.01.13.목.
"""

if __name__ == "__main__":
    numbers = input()
    count_min = [0] * 2
    change_num = int(numbers[0])
    count_min[change_num] += 1

    for i in range(1, len(numbers)):
        number = int(numbers[i])
        if change_num != number:
            change_num = number
            count_min[change_num] += 1

    print(min(count_min))
