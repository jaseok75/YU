"""
Project : Homework6.2
- 문제 6.1에서 구현한 class Person을 상속받는 class Student를 구현하라. 
  class Student는 추가적인 속성으로 정수형의 학번 (student_id), 문자열의 전공명 (major), 실수형 (float)의 평균성적 (GPA)를 가진다.
  class Student의 생성자 (initiator) 및 student_id, major, GPA의 접근자 (accessor)와 변경자 (mutator)를 구현하라.
  변경자에서는 데이터 멤버의 값이 설정/변경될 때 정상적인 범위의 값으로 설정/변경되는지 확인하는 기능을 포함하도록 하고,
  생성자 __init__() 함수에서는 각 데이터 멤버의 변경자를 사용하여 초기값을 설정을 하도록 하라.
  class Student 객체에 대하여 print() 함수로 출력할 때 사용되는 문자열을 변경자를 사용하여 초기값 설정을 하도록 하라.
  class Student 객체에 대하여 print() 함수로 출력할 때 사용되는 문자열을 제공하기 위한 __str__() 함수로 구현하라.
  10명의 학생 정보를 class Student로 생성하여 리스트에 포함시키고, 
  이 학생들을 이름 순, 학번 순, 성적 순으로 정렬하여 출력하는 시험 프로그램을 if __name__ == "__main__" 조건을 사용하여 실행하도록 구현하라.
Author : Ha-Rim Kim
Date of last update : 2021.10.07.
"""

class Person:
    def __init__(self, name, birth, st_id, age):
        self.setName(name)
        self.setAge(age)
        self.setSt_ID(st_id)
        self.setBirth(birth)
    def __new__(cls, *args, **kwargs):
        instance = object.__new__(cls)
        return instance
    def getName(self):
        return self.name
    def getAge(self):
        return self.age
    def getSt_ID(self):
        return self.st_id
    def setSt_ID(self, st):
        self.st_id = st
    def setName(self, nm):
        self.name = nm
    def setBirth(self, bt):
        if bt % 100 == 0 or bt % 10000 < 100:
            print("*** Error in setting birth (name:{}, age:{})" .format(self.name, self.age))
            self.birth = bt
        else:
            self.birth = bt
    def setAge(self, ag):
        if 0 <= ag < 250:
            self.age = ag
        else:
            print("*** Error in setting age (name:{},  age:{})" .format(self.name, ag))
            self.age = 0
    def __str__(self):
        return "Person({}, {}, {})".format(self.name, self.st_id, self.age)

class Student(Person):
    def __init__(self, name, birth, age, st_id, major, gpa):
        Person.__init__(self, name, birth, st_id, age)
        self.major = major
        self.gpa = gpa
    def __str__(self):
        return "Student({}, {}, {}, {}, {}, {})".format(self.name, self.birth, self.age, self.st_id, self.major, self.gpa)

def compareStudent(st1, st2, compare):
    if compare == "st_id":
        if st1.st_id < st2.st_id:
            return True
        else:
            return False
    elif compare == "name":
        if st1.name < st2.name:
            return True
        else:
            return False
    elif compare == "GPA":
        if st1.gpa > st2.gpa:
            return True
        else:
            return False

def sortStudent(L_st, compare):
    for i in range(0, len(L_st)):
        min_idx = i
        for j in range(i + 1, len(L_st)):
            if compareStudent(L_st[j], L_st[min_idx], compare):
                min_idx = j
        if min_idx != i:
            L_st[i], L_st[min_idx] = L_st[min_idx], L_st[i]

def printStudents(L_st):
    for s in range(len(L_st)):
        print(L_st[s])

#   Application

if __name__ == "__main__":
    students = [
        Student("Kim", 990101, 21, 12345, "EE", 4.0),
        Student("Lee", 980715, 22, 11234, "ME", 4.2),
        Student("Park", 101225, 20, 10234, "ICE", 4.3),
        Student("Hong", 110315, 19, 13123, "CE", 4.1),
        Student("Yoon", 971005, 23, 11321, "ICE", 4.2),
        Student("Wrong", 100000, 23, 15321, None, 3.2)
    ]
    print("students before sorting : ")
    printStudents(students)
    #
    sortStudent(students, "name")
    print("\nstudents after sorting by name : ")
    printStudents(students)
    #
    sortStudent(students, "st_id")
    print("\nstudents after sorting by student_id : ")
    printStudents(students)
    #
    sortStudent(students, "GPA")
    print("\nstudents after sorting by GPA in decreasing order : ")
    printStudents(students)