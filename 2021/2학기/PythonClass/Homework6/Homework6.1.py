"""
Project : Homework6.1
- 문자열 자료형의 속성인 이름 (name), 정수형 속성인 주민등록번호 (reg_id)와 정수형 속성인 나이 (age)를 가지는 class Person을 구현하라.
  class Person의 생성자 (initiator), name, reg_id와 age의 접근자 (accessor) 및 변경자 (mutator)를 구현하라.
  변경자에서는 데이터 멤버의 값이 설정/변경될 때 정상적인 범위의 값으로 설정/변경되는지 확인하는 기능을 포함하도록 하고,
  생성자 __init__() 함수에서는 각 데이터 멤버의 변경자를 사용하여 초기값 설정을 하도록 하라.
  class Person 객체에 대하여 print() 함수로 출력할 때 사용되는 문자열을 제공하기 위한 __str__() 함수로 구현하라.
  class Person을 사용하여 객체를 생성하고, 그 객체의 속성을 설정하며, 
  출력하는 시험 프로그램을 if __name__ == "__main__" 조건을 사용하여 실행하도록 구현하라.
Author : Ha-Rim Kim
Date of last update : 2021.10.07.
"""

class Person:
    def __init__(self, name, birth, age):
        self.setName(name)
        self.setAge(age)
        self.setBirth(birth)
    def __new__(cls, *args, **kwargs):
        instance = object.__new__(cls)
        return instance
    def getName(self):
        return self.name
    def getAge(self):
        return self.age
    def getBirth(self):
        return self.birth
    def setBirth(self, bt):
        self.birth = bt
    def setName(self, nm):
        self.name = nm
    def setAge(self, ag):
        if 0 <= ag < 250:
            self.age = ag
        else:
            print("*** Error in setting age (name:{},  age:{})" .format(self.name, ag))
            self.age = 0
    def __str__(self):
        return "Person({}, {}, {})".format(self.name, self.birth, self.age)

def printPersonList(L_persons):
    for p in L_persons:
        print("   ", p)

#   Application

if __name__ == "__main__":
    persons = [
        Person("Kim", 990101, 21),
        Person("Lee", 980715, 22),
        Person("Park", 101221, 20),
        Person("Hong", 110315, 19),
        Person("Yoon", 971005, 23),
        Person("Wrong", 100000, 350)
    ]
    print("persons : ")
    printPersonList(persons)