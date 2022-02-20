"""
Project : Homework4.3
- 파이썬 터틀 그래픽 기능을 사용하여 지정된 위치에 지정된 크기 (한 변의 길이)의 다각형을 그리는 drawPolygon() 함수를 구현하라.
  이 함수에 전달되는 인수로는 중심 위치 (x좌표, y좌표), 다각형의 꼭지점 수, 다각형 한 변의 길이가 주어지도록 하라. 
  입력된 중심위치와 다각형의 시작 위치에 점 (dot)을 표시하고, 좌표값을 출력하라.
Author : Ha-Rim Kim
Date of last update : 2021.09.23.
"""

import turtle
import math

def drawPolygon(x, y, vertex_number, length):
   start_x = x - (length / 2)
   start_y = y - ((length / 2) / math.tan(math.radians((360 / vertex_number) / 2)))
   t.penup()
   t.setpos(x, y)
   t.dot(10, "blue")
   t.write(t.position())
   t.pen(pencolor = 'red', pensize = '3')
   t.setpos(start_x, start_y)
   t.dot(10, 'red')
   t.write(t.pos())
   t.pendown()

   for i in range(vertex_number):
       t.forward(length)
       #t.write(t.pos())
       #t.dot(10, "red")
       t.left(180 - ((180 * (vertex_number - 2)) / vertex_number))
   turtle.done()

#####################################
# main

x, y, vertex_number, length = map(int, input ("input center_x, center_y, num_vertices, and line_length : ").split ())
t = turtle.Turtle()

drawPolygon(x, y, vertex_number, length)