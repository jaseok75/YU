"""
Project: 동빈나_이진 탐색 문제_정렬된 배열에서 특정 수의 개수 구하기
Date: 2022.01.20.목.
Comment:
- bisect 모듈 사용해서 개수 구하기
- bisect 엄청난 모듈이다
- 이건 log(n) 복잡도를 가지게 구현
"""

import bisect

if __name__ == "__main__":
    n, x = map(int, input().split())
    numbers = list(map(int, input().split()))

    left_count = bisect.bisect_left(numbers, x)
    right_count = bisect.bisect_right(numbers, x)

    count = right_count - left_count

    if count == 0:
        print("-1")
    else:
        print(count)
