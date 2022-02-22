"""
Project : Homework8.5
- 600 x 400 픽셀 크기의 테이블 위에서 공이 벽면에 반사되며 이동하는 시뮬레이션 기능을 파이썬 tkinter 그래픽 프로그램으로 구현하라.
  공의 크기는 지름 80 픽셀로 하며, 공의 색깔은 붉은 색으로 할 것.
Author : Ha-Rim Kim
Date of last update : 2021.11.02.
"""

import tkinter
from tkinter import *
from tkinter import messagebox

def ask_stop():
    result = messagebox.askquestion("Message", "Quit?")
    if result == "yes":
        window.destroy()

def changedr_key(event):
    global DX, DY

    if event.keysym == "Left":
        DX = -STEP
        DY = 0
    elif event.keysym == "Right":
        DX = STEP
        DY = 0
    elif event.keysym == "Up":
        DX = 0
        DY = -STEP
    elif event.keysym == "Down":
        DX = 0
        DY = STEP
    elif event.keysym == "Escape":
        DX = STEP
        DY = STEP
    elif event.keysym == "7":
        DX = -STEP
        DY = -STEP 
    else:
        DX= STEP 
        DY = STEP 

def init():
    global window, canvas, DX, DY, STEP
    window = Tk()
    window.title("Bouncing ball")
    canvas = Canvas(window, width=600, height = 400)
    canvas.pack(expand=YES, fill = BOTH) 
    canvas.create_oval(310, 310, 390, 390, fill='red', tag = 'ball')
    STEP = 1
    DX = STEP
    DY = STEP
    window.protocol("WM_DELETE_WINDOW", ask_stop)
    window.bind("<KeyPress-Left>", changedr_key)
    window.bind("<KeyPress-Right>", changedr_key)
    window.bind("<KeyPress-Up>", changedr_key)
    window.bind("<KeyPress-Down>", changedr_key)
    window.bind("<KeyPress-Escape>", changedr_key)
    window.bind("<KeyPress-7>", changedr_key)

def animate():
    global DX, DY
    pos = []
    Delay = 1 # in millisecond
    canvas.move("ball", DX, DY) # move Ball in DX, DY from current position
    pos = canvas.coords("ball")
    x_pos = (pos[0] + pos[2])/2
    y_pos = (pos[1] + pos[3])/2
    print("{}, {}".format(x_pos, y_pos))
    pos = canvas.coords("ball")
    if pos[0] <= 0 or pos[2] >= canvas.winfo_width():
        DX *= -1
        print("벽에 부딪혔습니다.")
    if pos[1] < 0 or pos[3] > canvas.winfo_height():
        DY *= -1
        print("벽에 부딪혔습니다.")
    canvas.update_idletasks()
    canvas.update()
    canvas.after(Delay, animate)
if __name__ == '__main__':
    init()
    animate()
    mainloop()