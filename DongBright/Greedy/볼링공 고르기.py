"""
Project: 동빈나_그리디_볼링공 고르기
Date: 2022.01.13.목.
"""

if __name__ == "__main__":
    n, m = map(int, input().split())
    ball = list(map(int, input().split()))
    weight_ball = [0] * (m + 1)
    count_ball = weight_ball[1]

    for i in range(1, m + 1):
        weight_ball[i] = ball.count(i)

    for i in range(1, m):
        weight = weight_ball[1]
        del weight_ball[1]
        print(weight_ball)
        count_ball += sum(weight_ball) * weight

    print(count_ball)
