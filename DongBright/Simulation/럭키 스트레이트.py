"""
Project: 동빈나_구현_럭키 스트레이트
Date: 2022.01.14.금.
"""

if __name__ == "__main__":
    n = input()
    left_number = n[:len(n) // 2]
    right_number = n[len(n) // 2:]
    str_left = list(left_number)
    int_left = list(map(int, str_left))
    str_right = list(right_number)
    int_right = list(map(int, str_right))

    if (sum(int_left) == sum(int_right)):
        print("LUCKY")
    else:
        print("READY")
