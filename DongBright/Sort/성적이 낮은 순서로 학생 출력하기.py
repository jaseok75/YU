"""
Project: 동빈나_정렬_성적이 낮은 순서로 학생 출력하기
Date: 2022.01.06.목
"""

N = int(input())
student = []

for i in range(N):
    name, score = input().split()
    student.append((name, int(score)))

sort_student = sorted(student, key = lambda x : -x[1])

for students in sort_student:
    print(students[0])
