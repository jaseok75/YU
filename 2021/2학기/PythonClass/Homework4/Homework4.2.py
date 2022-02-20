"""
Project : Homework4.2
- 중복되지 않는 정수형 (int) 난수를 지정된 개수 (예: 10,000 ~ 1,000,000) 만큼 생성하는 함수 genBigRandList(L, n)을 구현 
  이 함수에는 리스트 L과 리스트에 포함될 중복되지 않는 난수의 개수 n이 전달된다.
  주어진 리스트의 첫 부분 2줄 (한 줄에 10개씩)과 마지막 2줄을 출력하는 함수 printListSample(L, per_line, sample_lines)를 구현하라.
  주어진 리스트의 원소들을 오름차순으로 병합정렬 구조로 정렬하는 함수 mergeSort(L) 함수를 구현하라.
  표준입력장치로 부터 100,000 이상 크기의 정수형 난수 개수 (n)를 입력 받은 후,
  genBigRandList() 함수를 사용하여 중복되지 않는 정수형 난수 리스트를 생성하고,
  이를 printListSample() 함수를 사용하여 출력하라. 이 정수형 난수 리스트를 mergeSort() 함수를 사용하여 정렬하고,
  정렬된 상태를 printListSample() 함수를 사용하여 출력
Author : Ha-Rim Kim
Date of last update : 2021.09.23.
"""

import random
import operator
import sys
import time

def genBigRandList(L, n):
    rand_list = [x for x in range (0, n)]
    random.shuffle (rand_list)
    return rand_list

def printListSample(L, per_line, sample_lines):
   for i in range(sample_lines):
       for j in range(per_line):
           print("{:>10}" .format(L[(i * per_line) + j]), end = ' ')
       print()

   print(" . . . . . ")

   for i in range(sample_lines):
       for j in range(per_line):
           print("{:>10}" .format(L[(len(L) - sample_lines * per_line) + (i * per_line) + j]), end = ' ')
       print()

def merge(arr_left, arr_right, compare):
   arr_result = []
   i, j = 0, 0
   while i < len(arr_left) and j < len(arr_right):
       if compare(arr_left[i], arr_right[j]):
           arr_result.append(arr_left[i])
           i += 1
       else:
           arr_result.append(arr_right[j])
           j += 1
   while (i < len(arr_left)):
       arr_result.append(arr_left[i])
       i += 1
   while (j < len(arr_right)):
       arr_result.append(arr_right[j])
       j += 1
   return arr_result

def mergeSort(arr, compare = operator.lt):
   if len(arr) < 2:
       return arr[:]
   else:
       middle = len(arr) // 2
       left = mergeSort(arr[:middle], compare)
       right = mergeSort(arr[middle:], compare)
       return merge(left, right, compare)


#########################################
# main
L = list()
n = int(input("Input size of random list L (-1 to quit) = "))

if n == -1:
   sys.exit()

L = genBigRandList(L, n)

print("\nBefore mergeSort of L :")
printListSample(L, 10, 2)

start = time.time()
L = mergeSort(L)
print("After mergesort of L :")
printListSample(L, 10, 2)
print("mergeSort() for list L (size = {}) took {} sec" .format(n, time.time() - start))