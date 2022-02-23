"""
Project : Homework9.2
- 직병렬 전자회로의 선형시스템 해(solution)를 NumPy 선형대수 유니버설함수 solve()를 사용하여 구하라.
Author : Ha-Rim Kim
Date of last update : 2021.11.02.
"""

import numpy as np
A=np.array(\
    [
        [10,10,0,0,0],
        [1,-1,-1,0,0],
        [0,0,1,-1,-1],
        [0,10,-5,-10,0],
        [0,0,0,10,-10]
    ])
B=np.array([100,0,0,0,0])
X = np.linalg.solve(A,B)
matmul=np.matmul(A,X)

print("A=\n", A)
print("B=", B)
print("X=",X)
print("np.matmul(A,X) =",matmul)