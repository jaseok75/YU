"""
Project : Homework4.5
- 행렬을 표현하는 2차원 리스트 2개와 이 행렬의 행 및 열의 크기를 지정하는 정수 2개를 전달받아 행렬의 덧셈을 계산하여 결과를 반환하는 함수 
  matrixAdd(A, B, n_row, n_col)와 뺄셈을 계산하여 결과를 반환하는 함수 matrixSub(A, B, n_row, n_col)을 작성하고, 
  이를 호출하여 기능을 시험하는 파이썬 프로그램을 작성하라.
Author : Ha-Rim Kim
Date of last update : 2021.09.23.
"""

matrix_A = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
matrix_B = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
matrix_C = list()
matrix_D = list()

def matrixAdd(A, B, n_row, n_col):
   for i in range(n_row):
       matrix_add = list()
       for j in range(n_col):
           matrix_add.append(matrix_A[i][j] + matrix_B[i][j])
       matrix_C.append(matrix_add)

def matrixSub(A, B, n_row, n_col):
   for i in range(n_row):
       matrix_sub = list()
       for j in range(n_col):
           matrix_sub.append(matrix_A[i][j] - matrix_B[i][j])
       matrix_D.append(matrix_sub)

print("A : ", matrix_A)
print("B : ", matrix_B)
matrixAdd(matrix_A, matrix_B, 4, 4)
print("C = matrixAdd(A, B, len(A), len(A[0]))")
print("  = ", matrix_C)
matrixSub(matrix_A, matrix_B, 4, 4)
print("D = matrixSub(A, B, len(A), len(A[0]))")
print("  = ", matrix_D)