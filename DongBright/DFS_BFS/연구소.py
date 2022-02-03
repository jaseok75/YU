"""
Project: 동빈나_DFS/BFS_연구소
Date: 2022.01.17.월.
Comment:
- 완벽 성공
- 시간은 좀 오래걸렸는데 성공했다.
"""

import sys
import itertools
import copy
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def isRange(x, y):
    if 0 <= x < n and 0 <= y < m:
        return True
    else:
        return False

def dfs(x, y):
    visited[x][y] = False
    new_map[x][y] = 2

    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if isRange(nx, ny) and visited[nx][ny] and new_map[nx][ny] == 0:
            dfs(nx, ny)
    return

if __name__ == "__main__":
    n, m = map(int, input().split())
    input_map = [list(map(int, input().split())) for _ in range(n)]
    index_map = []
    new_map = []
    max_safety_area = 0

    for i in range(n):
        for j in range(m):
            if input_map[i][j] != 2 and input_map[i][j] != 1:
                index_map.append((i, j))

    beouk = list(itertools.combinations(index_map, 3))

    for idx in beouk:
        visited = [[True] * m for _ in range(n)]
        safety_area = 0
        new_map = copy.deepcopy(input_map)
        new_map[idx[0][0]][idx[0][1]] = 1
        new_map[idx[1][0]][idx[1][1]] = 1
        new_map[idx[2][0]][idx[2][1]] = 1

        for i in range(n):
            for j in range(m):
                if visited[i][j] and new_map[i][j] == 2:
                    dfs(i, j)

        for i in range(n):
            for j in range(m):
                if new_map[i][j] == 0:
                    safety_area += 1
        max_safety_area = max(safety_area, max_safety_area)

    print(max_safety_area)
