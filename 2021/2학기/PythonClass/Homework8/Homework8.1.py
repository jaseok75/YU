"""
Project : Homework8.1
- 다각형 외접원의 radius, 꼭잣점 수 (num_vertuces)와 중심 좌표 (center_x, center_y), 색상 정보를 튜플 (radius, num_vertices, center_x, center_y, color)로 정의하고,
  이 튜플을 리스트 L_polygons로 선언한 후, 터틀 객체의 circle() 함수를 사용하여 지정된 중심좌표에 원 및 다각형을 그리는 파이썬 프로그램을 작성하라.
Author : Ha-Rim Kim
Date of last update : 2021.11.02.
"""

import turtle

turtle.setup(600, 500)
turtle.mode("standard") #mode standard sets initial heading right
turtle.title("Drawing polygons with turtle.circle")
t = turtle.Turtle()
t.pensize(2)
t.up(); t.shape(name = 'classic'); t.down()
radius = 50

polygons = [(-225, 150, "red", 3), (-75, 150, "blue", 4), (75, 150, "green", 5),\
            (225, 150, "magenta", 6), (-225, -50, "brown", 7),\
            (-75, -50, "chocolate", 8), (75, -50, "black", 9),\
            (225, -50, "indigo", 0)]

for i in range(len(polygons)):
    (pos_x, pos_y, shape_color, num_vertices) = polygons[i]
    t.up(); t.goto(pos_x, pos_y - radius); t.down(); t.dot(10, "red"); t.write(t.pos())
    t.up(); t.goto(pos_x, pos_y); t.setheading(180); t.down()
    t.color(shape_color)
    if num_vertices > 2:
        t.circle(radius, steps = num_vertices)
    else:
        t.circle(radius)

turtle.done()