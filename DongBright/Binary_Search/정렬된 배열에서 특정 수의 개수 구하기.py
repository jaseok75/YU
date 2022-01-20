"""
Project: 동빈나_이진 탐색 문제_정렬된 배열에서 특정 수의 개수 구하기
Date: 2022.01.20.목.
Coment:
- 난이도 2가 이렇게나 쉬울 일?
- 무난하게 시작한다잉
"""

if __name__ == "__main__":
    n, x = map(int, input().split())
    numbers = list(map(int, input().split()))

    number_count = numbers.count(x)

    if number_count == 0:
        print("-1")
    else:
        print(number_count)
