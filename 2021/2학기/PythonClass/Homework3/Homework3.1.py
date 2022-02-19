import sys
year, month, day = map (int, input ("Input year, month, day : ").split ())
month_1to12 = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
weekDay = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']

# 윤년인지 확인하는 함수
def isLeapYear(year):
    if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
        return True
    return False

# 날짜가 올바른 날짜인지 확인하는 함수
def isValidDate():
    if year <= 0 or month <= 0 or month > 12 or day <= 0 or day > month_1to12[month]:
        return False
    return True

while year != 0 and month != 0 and day != 0:
    total_date = 0
    weekday = 0
    if isLeapYear(year):
        month_1to12[2] = 29
    if isValidDate() == False:
        print ("Date is not valid !")
        sys.exit ()
    for i in range (1, year):
        if isLeapYear(i):
            total_date += 366
        else:
            total_date += 365
    for i in range (1, month):
        total_date += month_1to12[i]
    total_date += day
    weekday = total_date % 7
    print ("Day (year({}), month({}), dat({}) : Elapsed {} days from Jan01AD01".format(year, month, day, total_date))
    print ("week day = ", weekDay[weekday])
    year, month, day = map(int, input ("Input year, month, day : ").split())