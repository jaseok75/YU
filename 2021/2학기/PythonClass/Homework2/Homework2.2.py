"""
Project : Homework2.2
- 2 개의 정수형 데이터 a와 b를 입력받아 a+b, a-b, a*b, a/b, a//b, a%b를 각각 계산하여 출력하는 파이썬 프로그램을 작성하라.
Author : Ha-Rim Kim
Date of last update : 2021.09.13.
"""

a, b = input("input two integers : ").split()

while a != '0' and b != '0':
    a, b = int (a), int (b)

    # 입력된 a와 b를 가지고 연산하기
    result_sum = a + b
    result_sub = a - b
    result_mul = a * b
    result_div = a / b
    result_div_int = a // b
    result_mod = a % b

    # 연산 결과 출력하기
    print("{} + {} = {}".format(a, b, result_sum))
    print("{} - {} = {}".format(a, b, result_sub))
    print("{} * {} = {}".format(a, b, result_mul))
    print("{} / {} = {:.3f}".format(a, b, result_div))
    print("{} // {} = {}".format(a, b, result_div_int))
    print("{} % {} = {}".format(a, b, result_mod))
    a, b = input("input two integers : ").split()

print ("input data is 0 and 0")