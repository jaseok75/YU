"""
Project : Homework4.4
- Fibonacci 수열을 신속하게 계산할 수 있도록 memo 기능을 포함하는 재귀함수 dynFibo(n)를 구성하고, 
  시작 (start), 끝 (end), 간격 (stride)의 정수를 입력 받은 후 해당 순서의 피보나치 수열을 출력하는 프로그램을 작성하라. 
  각 단계별 피보나치 수열 계산에서 이미 메모에 포함된 피보나치 수열 값은 별도로 계산하지 않고 메모의 내용을 사용하며, 
  이전에 계산된 적이 없은 피보나치 수열 값은 재귀함수를 사용하여 계산한 후, 이를 메모에 기록하여 두고, 
  계산된 결과값을 반환하는 동적 프로그래밍 구조를 사용하도록 하라.
Author : Ha-Rim Kim
Date of last update : 2021.09.23.
"""

import time

start, end, stride = map(int, input("input start, stop, step of fibonacci series : ").split())
memo = dict()

def dynFibo(n):
   if n in memo:
       return memo[n]
   elif n <= 1:
       memo[n] = n
       return n
   else:
       fibo_n = dynFibo(n - 1) + dynFibo(n - 2)
       memo[n] = fibo_n
       return fibo_n

for i in range(start, end + 1, stride):
   start = time.time()
   fibo = dynFibo(i)
   print("dynfibo({:>5}) = {:>30}, took {:>10}[milli-sec]" .format(i, fibo, (time.time() - start) * 1000))