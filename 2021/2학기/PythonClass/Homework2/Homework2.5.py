"""
Project : Homework2.5
- 4개의 꼭지점의 좌표를 튜플 리스트로 설정한 직사각형을 파이썬 터틀 그래픽으로 그리는 프로그램이다.
Author : Ha-Rim Kim
Date of last update : 2021.09.13.
"""

import turtle

coordinates = [(-100, -100), (100, -100), (100, 100), (-100, 100)]  # 4개의 꼭지점
t = turtle.Turtle ()

t.shape ('turtle')
t.pencolor ('red')
t.width (5)
t.penup ()
t.setpos(coordinates[0][0], coordinates[0][1])  # 펜을 사각형의 첫 번째 위치로 이동
t.write (t.position ())
t.pendown ()

# 펜을 4개의 꼭짓점을 차례로 이동하면서 사각형 그리기
for i in range (1, 4):
    t.setpos (coordinates[i][0], coordinates[i][1])
    t.write (t.position ())

# 펜을 다시 사각형의 첫 번째 위치로 이동시킴
t.setpos(coordinates[0][0], coordinates[0][1])

# 사각형을 다 그린 후 펜을 원점으로 이동시킴
t.penup ()
t.setpos (0, 0)
t.pendown ()

print ("123")