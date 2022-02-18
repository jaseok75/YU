"""
Project : Homework2.1
- 0 ~ 255의 값을 10진수, 16진수, 8진수, 2진수로 각각 출력
Author : Ha-Rim Kim
Date of last update : 2021.09.13.
"""

for i in range (256):
    print ("{: >3} = {: >4} = {: >5} = {: >10}".format (i, hex(i), oct(i), bin(i)))