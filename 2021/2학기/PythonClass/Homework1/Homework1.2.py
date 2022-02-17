"""
Project : Homework1.2
- 10개의 데이터를 차례대로 입력받고, 입력 데이터 중 가장 큰 값, 가장 작은 값, 평균값, 분산 및 표준편차를 계산하는 알고리즘
Author : Ha-Rim Kim
Date of last update : 2021.09.02.
"""

import math

TARGET_NUM_DATA = 10
num_data = 0
L_data = [] #empty list
L_sum = 0
print("Input {} integer data." .format(TARGET_NUM_DATA))
while num_data < TARGET_NUM_DATA:
   data = int(input("data = "))
   num_data = num_data + 1
   L_data.append(data)
   L_sum = L_sum + data

avg = L_sum / num_data
dev_sq_sum = 0

for i in range(num_data):
   dev = avg - L_data[i]   #deviation from avg
   dev_sq_sum += dev * dev
var = dev_sq_sum / num_data
std = math.sqrt(var)

print("Input data list = ", L_data)
print("avg = {}, var = {}, std = {}" .format(avg, var, std))