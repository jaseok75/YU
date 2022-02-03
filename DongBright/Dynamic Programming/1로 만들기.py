"""
Project: 동빈나_다이나믹 프로그래밍_1로 만들기
Date: 2022.01.10.월.
"""

def make_1(X):
    number = [0] * 30001

    for i in range(2, X + 1):
        number[i] = number[i - 1] + 1
        if i % 5 == 0:
            number[i] = min(number[i], number[i // 5] + 1)
        if i % 3 == 0:
            number[i] = min(number[i], number[i // 3] + 1)
        if i % 2 == 0:
            number[i] = min(number[i], number[i // 2] + 1)
    return number[X]

if __name__ == "__main__":
    X = int(input())

    count = make_1(X)
    print(count)
