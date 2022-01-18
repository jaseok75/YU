"""
Project: 동빈나_정렬_국영수
Date: 2022.01.18.화.
Coment: 파이썬 내장 함수 sorted - lambda 사용
"""

if __name__ == "__main__":
    n = int(input())
    students = [list(map(str, input().split())) for _ in range(n)]

    students = sorted(students, key = lambda x : (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

    for student in students:
        print(student[0])
