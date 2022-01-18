"""
Project: 동빈나_정렬_카드 정렬하기
Date: 2022.01.18.화.
Coment: 
- 처음으로 동빈나씨 Chap2 하루만에 한 챕터 다 풀었다.
- heapq 모듈 써서 품
- heapq 쓰면 정렬된 상태로 queue 관리할 수 있음
"""
import sys
import heapq
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    cards = []
    count = 0

    for i in range(n):
        heapq.heappush(cards, int(input()))

    if n == 1:
        print("0")

    else:
        while len(cards) > 1:
            a = heapq.heappop(cards)
            b = heapq.heappop(cards)
            count += a + b
            heapq.heappush(cards, a + b)
        print(count)
