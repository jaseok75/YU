"""
Project: Homework12.1
- LEDs On/Off control with push button
Author: Kim Ha Rim
Date of last update: 2021.11.30.
"""

import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

GPIO.setup(32, GPIO.IN)
GPIO.setup(36, GPIO.OUT)
GPIO.setup(38, GPIO.OUT)
GPIO.setup(40, GPIO.OUT)

def ledctrl(pin):
    GPIO.output(pin, True)
    time.sleep(1)

def ledctrl_down(pin):
    GPIO.output(pin, False)
    time.sleep(1)

try:
    while True:
        if (GPIO.input(32) == False):
            #print("asd")
            ledctrl(36)
            ledctrl(38)
            ledctrl(40)

            ledctrl_down(36)
            ledctrl_down(38)
            ledctrl_down(40)

        time.sleep(0.1)
except:
    GPIO.cleanup()