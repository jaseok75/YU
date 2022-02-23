"""
Project : Homework9.1
- NumPy의 normal(mu, sigma, size) 함수를 사용하여 정규분포 (normal distribution)의 난수를 10000개 생성하여 ndarry G 저장하라.
  이 배열 G에 포함된 배열 원소들의 통계 분석을 위하여 유니버설 함수인 mean(), var(), std()를 사용하고,
  그 결과를 normal() 함수의 난수 배열 생성에서 사용한 mu과 sigma의 갓ㅂ과 어떤 관계가 있는지 확인하라.
Author : Ha-Rim Kim
Date of last update : 2021.11.02.
"""

import numpy as np

mu, sigma = map(float, input("mu and sigma(in float) : ").split())
random_size = int(input("size of array : "))
sample_lines = 3
per_line = 10
random_mean = 0
random_var = 0.0
random_std = 0.0

print("mu = {:1.1f}, sigma = {:1.1f}" .format(mu, sigma))

rand_array = np.random.normal(loc = mu, scale = sigma, size = random_size)
print("Sample of G = np.random.normal ({:1.1f}, {:1.1f}, {}) = " .format(mu, sigma, random_size))

for i in range(sample_lines):
    for j in range(per_line):
        print("{:>8.2f}" .format(rand_array[(i * per_line) + j]), end = '')
    print()
print(". . . . .")
for i in range(sample_lines):
    for j in range(per_line):
        print("{:>8.2f}" .format(rand_array[len(rand_array) - (sample_lines * per_line) + (i * per_line) + j]), end = '')
    print()

random_mean = np.mean(rand_array)
random_var = np.var(rand_array)
random_std = np.std(rand_array)

print("mean of G =", random_mean)
print("var of G =", random_var)
print("std of G =", random_std)