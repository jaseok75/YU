"""
Project : Homework6.3
- 연 (year), 월 (month), 일 (day)의 데이터 멤버를 가지는 class Date를 구현하라.
  class Date의 생성자 (initiator) 및 데이터 멤버에 대한 접근자 (accessor)와 변경자 (mutator)를 구현하라.
  변경자에서는 데이터 멤버의 값이 설정/변경될 때 정상적인 범위의 값으로 설정/변경되는지 확인하는 기능을 포함하도록 하고, 
  생성자 __init__() 함수에서는 각 데이터 멤버의 변경자를 사용하여 초기값 설정을 하도록 하라.
  class Date 객체에 대하여 print() 함수로 출력할 때 사용되는 문자열을 제공하기 위한 __str__() 함수로 구현하라.
  10개의 class Date 인스탄스들을 임의로 생성하여 리스트에 포함시킨 후,
  이들을 오름차순으로 정렬하는 파이썬 프로그램을 작성하라.
  class Date를 사용하여 객체를 생성하고, 그 객체의 속성을 설정하며, 출력하는 시험 프로그램을 if __name__ == "__main__" 조건을 사용하여 실행하도록 구현하라.
Author : Ha-Rim Kim
Date of last update : 2021.10.07.
"""

class Date:
    def __init__(self, yr, mt, dy):
        self.setYear(yr)
        self.setMonth(mt)
        self.setDay(mt, dy, yr)
    def __lt__(self, other):
        if self.__eq__(other):
            return False
        elif (self.yr, self.mt, self.dy) < (other.yr, other.mt, other.dy):
            return True
        else:
            return False
    def __eq__(self, other):
        if self.yr != other.yr:
            return False
        elif self.mt != other.mt:
            return False
        elif self.dy != other.dy:
            return False
        else:
            return True
    def __le__(self, other):
        if self.__eq__(other):
            return True
        elif self.__lt__(other):
            return True
        else:
            return False
    def __str__(self):
        return "({:4}-{:2}-{:2})".format(self.yr, self.mt, self.dy)
    def getYear(self):
        return self.yr
    def getMonth(self):
        return self.mt
    def getDay(self):
        return self.dy
    def setYear(self, year):
        if 0 < year:
            self.yr = year
        else:
            print("*** Error in setting year (year: {})" .format(year))
            self.yr = 1
    def setMonth(self, month):
        if 1 <= month <= 12:
            self.mt = month
        else:
            print("*** Error in setting month (month: {})" .format(month))
            self.mt = 1
    def setDay(self, month, day, year):
        MONTH = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if 1 <= day <= MONTH[month]:
            self.dy = day
        elif (month == 2) and (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)) and (day == 29):
            self.dy = day
        else:
            print("*** Error in setting day (day: {})" .format(day))
            self.dy = 1

# Application

if __name__ == "__main__":
    dates = [
        Date(2020, 9, 24),
        Date(2000, 9, 15),
        Date(2020, 2, 29),
        Date(2020, 1, 31),
        Date(1997, 2, 20),
        Date(2001, 5, 2),
        Date(2001, 5, 1),
        Date(1999, 3, 1)
    ]
    print("dates before sorting : ")
    for d in dates:
        print(d)
    #
    dates.sort()
    print("\nstudents after sorting : ")
    for d in dates:
        print(d)