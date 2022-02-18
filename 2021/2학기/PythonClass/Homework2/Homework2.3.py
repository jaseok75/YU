"""
Project : Homework2.3
- 표준입력장치 (키보드)로부터 원의 반지름 (radius)을 입력 받고, 그 원의 넓이 (area)와 원둘레 (circumference)를 출력
Author : Ha-Rim Kim
Date of last update : 2021.09.13.
"""

radius = float(input("radius of a circle (in float) = "))   # 반지름 입력
PI = 3.141592

while radius != -1:
    area = PI * (radius ** 2)   # 원 넓이 계산
    circumference = 2 * PI * radius # 원 둘레 계산

    print ("Circle of radius ({:.2f}) : area ({:.2f}), circumference ({:.2f})".format (radius, area, circumference))

    radius = float(input("radius of a circle (in float) = "))