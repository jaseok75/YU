"""
Project : Homework8.4
- Start, Pause, Reset 메뉴를 가지는 스톱워치를 tkinter GUI 프로그램으로 구현하라.
  이 스톱워치는 소수점 이하 3자리를 사용하여 milli-second 단위 표시의 경과 시간을 알려 준다.
Author : Ha-Rim Kim
Date of last update : 2021.11.02.
"""

import time
from tkinter import *

def runTimer():
    global start_time, elapsed_time, prev_elapsed_time
    if (running):
        cur_time = time.time()
        time_diff = cur_time - start_time
        elapsed_time = time_diff + prev_elapsed_time
        timeText.configure(text = "{:7.3f}" .format(elapsed_time))
    window.after(10, runTimer)
def start():
    global running, start_time, elapsed_time, prev_elapsed_time
    if (running != True):
        running = True
        start_time = time.time()
        prev_elapsed_time = elapsed_time
def stop():
    global running, prev_elapsed_time, elapsed_time
    running = False
    prev_elapsed_time = elapsed_time
def reset():
    global running, elapsed_time, prev_elapsed_time
    running = False
    elapsed_time = 0.0
    prev_elapsed_time = 0.0
    timeText.configure(text = str(elapsed_time))

running = False

window = Tk()
timer = 0
start_time = time.time()
stop_time = time.time()
elapsed_time = 0.0
prev_elasped_time = 0.0

window.title("My Simple Stop Watch")
timeText = Label(window, height = 5, text = "0", font = ("Arial 40 bold"))
timeText.pack(side = TOP)
startButton = Button(window, width = 10, text = "Start", bg = "green", command = start)
startButton.pack(side = LEFT)
stopButton = Button(window, width = 10, text = "Pause", bg = "red", command = stop)
stopButton.pack(side = LEFT)
resetButton = Button(window, width = 10, text = "Reset", bg = "yellow", command = reset)
resetButton.pack(side = LEFT)

if __name__ == '__main__':
    runTimer()
    window.mainloop()