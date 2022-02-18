"""
Project : Homework2.4 (int)
- 직육면체의 가로 (width), 세로 (length), 높이 (height)를 정수 자료형으로 입력받아, 표면적 (surface area)과 체적/부피 (volume)를 계산하여 출력
Author : Ha-Rim Kim
Date of last update : 2021.09.13.
"""

width, length, height = map(int, input("width, length, height (in int) = ").split())  # 가로, 세로, 높이 값 입력

while width != 0 and length != 0 and height != 0:
    surface_area = 2 * ((width * length) + (length * height) + (width * height))    # 표면적 계산
    volume = width * length * height    # 부피 계산

    print ("Hexahedron of width ({:.3f}), length ({:.3f}) and height ({:.3f}) : ".format (width, length, height))
    print ("surface_area ({:.3f}), volume ({:.3f})".format (surface_area, volume))

    width, length, height = map(int, input("width, length, height (in int) = ").split())