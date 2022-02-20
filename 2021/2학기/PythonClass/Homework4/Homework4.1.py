"""
Project : Homework4.1
- 학생 10명의 정보를 포함하는 튜플 (학생이름, 학과명, 학번, (연, 월, 일), 평균성적)들을 리스트에 포함시킨 후, 
  파이썬 내장함수 sum(), max(), min(), len()을 사용하여 학생들의 성적 분포 (최대, 최소, 평균)를 파악하여 출력하는 함수 statistics_student_GPA() 함수를 구현
Author : Ha-Rim Kim
Date of last update : 2021.09.23.
"""

# 학생 10명의 정보를 포함하는 튜플
student = [('Kim', 'EE', 12345, (2000, 12, 25), 4.0),\
           ('Lee', 'ME', 11234, (2019, 9, 1), 4.2),\
           ('Park', 'ICE', 10234, (2019, 3, 1), 4.3),\
           ('Hong', 'CE', 13123, (2021, 1, 1), 4.1),\
           ('Yoon', 'ICE', 11321, (2001, 8, 15), 4.2),\
           ('A', 'ICE', 12321, (2000, 7, 31), 4.2)]

# 학생들의 성적 분포를 파악하여 출력하는 함수
def statistics_student_GPA(student):
    l_gpas = list()
    num_students = len(student)

    for i in range(num_students):
        l_gpas.append(student[i][4])

    max_score = max(l_gpas)
    min_score = min(l_gpas)
    sum_score = sum(l_gpas)
    avg_score = sum_score / num_students

    print("students = ")
    for i in range(num_students):
        print(student[i])

    print("statistics_student_GPA ::")
    print(" - L_GPAs = ", l_gpas)
    print(" - num_students =", num_students)
    print(" - Statistics of GPAs : Max({}), Min({}), Avg ({})" .format(max_score, min_score, avg_score))

###########################
# main
statistics_student_GPA(student)