"""
Project: DongBright_다이나믹 프로그래밍_퇴사
Date: 2022.01.25.화.
Comment:
- 금광 문제랑 비슷
"""

def max_tri(triangle):
    tri_map = [[0] * n for _ in range(n)]
    tri_map[0][0] = triangle[0][0]
    idx = 1
    for i in range(1, n):
        idx += 1
        for j in range(idx):
            if j == 0:
                left = 0
            else:
                left = tri_map[i - 1][j - 1]
            if j == idx - 1:
                up = 0
            else:
                up = tri_map[i - 1][j]
            tri_map[i][j] = max(left, up) + triangle[i][j]
    result = max(tri_map[n - 1])
    return result

if __name__ == "__main__":
    n = int(input())
    triangle = [list(map(int, input().split())) for _ in range(n)]
    print(max_tri(triangle))
