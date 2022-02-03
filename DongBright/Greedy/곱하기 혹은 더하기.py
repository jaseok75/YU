"""
Project: 동빈나_그리디_곱하기 혹은 더하기
Date: 2022.01.13.목.
"""

if __name__ == "__main__":
    numbers = input()
    result = int(numbers[0])

    for i in range(1, len(numbers)):
        number = int(numbers[i])
        if result == 0 or result == 1 or number == 0 or number == 1:
            result += number
        else:
            result *= number

    print(result)
