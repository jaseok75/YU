"""
Project : Homework3.2
- 시간을 나타내는 시(hour), 분(minute), 초(second)의 3개 정수를 입력 받고, 오늘 자정 (24:00:00)까지 몇 초가 남았는지 계산하여 출력
Author : Ha-Rim Kim
Date of last update : 2021.09.22.
"""
import sys

hour, minute, second = map(int, input("Input hour min sec : ").split())

def isValidTime():
   if hour < 0 or hour > 24 or minute < 0 or minute > 60 or second < 0 or second > 60:
       return False
   return True

while hour != 0 or minute != 0 or second != 0:
    total_time = 0
    Midnight_second = 24 * 3600
    diff_time = 0

    if isValidTime() == False:
        print("Time is not valid !")
        sys.exit()

    total_time += hour * 3600
    total_time += minute * 60
    total_time += second

    diff_time = Midnight_second - total_time

    print ("Input time : hour({}), minute({}), second({})".format(hour, minute, second))
    print ("Elapsed seconds from last midnight =", total_time)
    print ("Remaining seconds to next-midnight =", diff_time)

    hour, minute, second = map(int, input("Input hour min sec : ").split())