"""
Project : Homework7.3
- 행렬 (matrix)의 초기화 및 덧셈, 뺄셈, 곱셈 및 출력 기능을 메소드로 가지는 class Mtrx를 파이썬 프로그램으로 작성하고,
  이를 myClassMtrx.py에 저장하라.
Author : Ha-Rim Kim
Date of last update : 2021.10.22.
"""

class Mtrx(object):
    def __init__(self, name, num_rows, num_cols, list_data):
        self.name = name
        self.num_rows = num_rows
        self.num_cols = num_cols
        self.list_data = list_data
    def __str__(self):
        return "{}\n{}\n{}\n{}\n{}" .format(self.list_data[0], self.list_data[1], self.list_data[2], self.list_data[3], self.list_data[4])
    def __add__(self, other):
        result = list()
        for i in range(self.num_rows):
            middle_result = list()
            for j in range(self.num_cols):
                middle_result.append(self.list_data[i][j] + other.list_data[i][j])
            result.append(middle_result)
        return Mtrx("result", self.num_rows, self.num_cols, result)
    def __sub__(self, other):
        result = list()
        for i in range(self.num_rows):
            middle_result = list()
            for j in range(self.num_cols):
                middle_result.append(self.list_data[i][j] - other.list_data[i][j])
            result.append(middle_result)
        return Mtrx("result", self.num_rows, self.num_cols, result)
    def __mul__(self, other):
        result = [[0 for x in range(other.num_cols)] for y in range(self.num_rows)]
        for i in range(self.num_rows):
            for j in range(other.num_cols):
                for k in range(self.num_cols):
                    result[i][j] += (self.list_data[i][k] * other.list_data[k][j])
        return Mtrx("result", self.num_rows, self.num_cols, result)

if __name__ == "__main__":
    data_1 = [[1, 2, 3, 4, 5],\
                [6, 7, 8, 9, 10],\
                [11, 12, 13, 14, 15],\
                [16, 17, 18, 19, 20],\
                [21, 22, 23, 24, 25]]
    data_2 = [[1, 0, 0, 0, 0],\
                [0, 1, 0, 0, 0],\
                [0, 0, 1, 0, 0],\
                [0, 0, 0, 1, 0],\
                [0, 0, 0, 0, 1]]

    m1 = Mtrx("M1", 5, 5, data_1)
    print("m1 = \n", m1)

    m2 = Mtrx("M2", 5, 5, data_2)
    print("m2 = \n", m2)

    m3 = m1 + m2
    print("m3 = m1 + m2 = \n", m3)

    m4 = m1 - m2
    print("m4 = m1 - m2 = \n", m4)

    m5 = m1 * m2
    print("m5 = m1 * m2 = \n", m5)