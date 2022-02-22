"""
Project : Homework8.2
- 터틀 그래픽의 마우스 이벤트를 사용하여 터틀 그래픽 스크린 내부의 위치에서 마우스 왼쪽 버튼 또는 오른쪽 버튼을 클릭하면
  그 위치의 좌표값과 눌려진 버튼의 종류를 출력하는 파이썬 프로그램을 작성하라.
  왼쪽 버튼이 눌려지면 붉은색 선이 그어지게 하며, 오른쪽 버튼이 눌려지면 푸른색 선이 그어지게 하라.
Author : Ha-Rim Kim
Date of last update : 2021.11.02.
"""

import turtle

board = turtle.Screen()
board.screensize(800, 600, 'light blue')

pointer = turtle.Turtle()
pointer.color('red')
pointer.pencolor('red')
pointer.ht()

def teleport_btn1(x, y):
    pointer.pencolor('red')
    pointer.goto(x, y)
    pointer.dot(10, "red")
    pointer.write(("btn_1", pointer.xcor(), pointer.ycor()))

def teleport_btn3(x, y):
    pointer.pencolor('blue')
    pointer.goto(x, y)
    pointer.dot(10, "blue")
    pointer.write(("btn_3", pointer.xcor(), pointer.ycor()))

def quitThis():
    board.bye()

pointer.dot(10, "red")
pointer.write((pointer.xcor(), pointer.ycor()))
board.onclick(teleport_btn1, btn = 1)
board.onclick(teleport_btn3, btn = 3)
board.onkey(quitThis, 'q')

board.listen()
board.mainloop()