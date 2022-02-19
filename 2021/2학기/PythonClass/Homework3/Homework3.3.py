"""
Project : Homework3.3
- 튜플 (year, month, day)로 표현되는 날짜 (date)을 표준 입력장치로부터 10개 입력하여 날짜 튜플 리스트 (list of date-tuples)에 포함시킨 후, 이 날짜들을 오름차순으로 정렬
Author : Ha-Rim Kim
Date of last update : 2021.09.22.
"""

import sys

listOfDate_tuples = list()
yr_mn_dy_strings = list()
date_tuples = tuple()
TOTAL_NUM_DATA = 10
month_1to12 = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def isLeapYear(year):
    if year % 4 == 0 and year % 100  != 0 or year % 400 == 0:
        return True
    return False

def isValidDate(year, month, day):
    if isLeapYear(year):
        month_1to12[2] = 29
    if year <= 0 or month <= 0 or month > 12 or day <= 0 or day > month_1to12[month]:
        return False
    return True

for i in range(TOTAL_NUM_DATA):
    date_tuples = tuple(map(int, input("Input year month date : ").split()))
    (year, month, day) = date_tuples
    if isValidDate(year, month, day) == False:
        print("Date is not valid !")
        sys.exit()
    listOfDate_tuples.append(date_tuples)
    print ("Input yr_mn_dy_strings :", listOfDate_tuples[i])

print ("List of dates :", listOfDate_tuples)
listOfDate_tuples.sort()
print ("Sorted list of dates :", listOfDate_tuples)