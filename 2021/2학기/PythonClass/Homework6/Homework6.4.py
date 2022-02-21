"""
Project : Homework6.4
- 시 (hour), 분 (min), 초 (sec)의 데이터 멤버를 가지는 class Time을 구현하라.
  class Time의 생성자 (initiator) 및 데이터 멤버에 대한 접근자 (accessor)와 변경자 (mutator)를 구현하라.
  변경자에서는 데이터 멤버의 값이 설정/변경될 때 정상적인 범위의 값으로 설정/변경되는지 확인하는 기능을 포함하도록 하고,
  생성자 __init__() 함수에서는 각 데이터 멤버의 변경자를 사용하여 초기값 설정을 하도록 하라.
  class Time 객체에 대하여 print() 함수로 출력할 때 사용되는 문자열을 제공하기 위한 __str__() 함수로 구현하라.
  10개의 class Time 인스탄스들을 임의로 생성하여 리스트에 포함시킨 후,
  이들을 오름차순으로 정렬하는 파이썬 프로그램을 작성하라.
  class Time을 사용하여 객체를 생성하고, 그 객체의 속성을 설정하며, 출력하는 시험 프로그램을 if __name__ == "__main__" 조건을 사용하여 실행하도록 구현하라.
Author : Ha-Rim Kim
Date of last update : 2021.10.07.
"""

class Time:
    def __init__(self, hr, mn, sec):
        self.setHour(hr)
        self.setMinute(mn)
        self.setSecond(sec)
    def __lt__(self, other):
        if (self.hr, self.mn, self.sec) < (other.hr, other.mn, other.sec):
            return True
        else:
            return False
    def __eq__(self, other):
        if self.hr != other.hr:
            return False
        elif self.mn != other.mn:
            return False
        elif self.sec != other.sec:
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
        return "({:2}:{:2}:{:2})" .format(self.hr, self.mn, self.sec)
    def getHour(self):
        return self.hr
    def getMinute(self):
        return self.mn
    def getSecond(self):
        return self.sec
    def setHour(self, hour):
        if 1 <= hour <= 24:
            self.hr = hour
        else:
            print("*** Error in setting time (hour: {})" .format(hour))
            self.hr = 1
    def setMinute(self, minute):
        if 0 <= minute <= 59:
            self.mn = minute
        else:
            print("*** Error in setting time (minute: {})" .format(minute))
            self.mn = 0
    def setSecond(self, second):
        if 0 <= second <= 60:
            self.sec = second
        else:
            print("*** Error in setting time (second: {})" .format(second))
            self.sec = 0

#   Application

times = [
    Time(23, 59, 59),
    Time(9, 0, 5),
    Time(13, 30, 0),
    Time(3, 59, 59),
    Time(0, 0, 0)
]

print("times before sorting : ")
for t in times:
    print(t)
#
times.sort()
print("\ntimes after sorting : ")
for t in times:
    print(t)