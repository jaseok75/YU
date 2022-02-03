"""
Project: 동빈나_DFS/BFS_음료수 얼려 먹기
Date: 2022.01.05.수.
"""
N, M = map(int, input().split())
ice = [list(map(int, input().split())) for _ in range(N)]
visited = [[0 for x in range(M)] for _ in range(N)]
count_ice = 0

def isRange(x, y):
    if x < 0 or x >= N or y < 0 or y >= M:
        return False
    else:
        return True

def dfs(x, y):
    global visited, ice

    # 서, 남, 동, 북
    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]

    visited[x][y] = 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        c_ice = ice
        c_visited = visited
        if isRange(nx, ny) == True and visited[nx][ny] != 1 and ice[nx][ny] == 0:
            count_dfs = 0
            dfs(nx, ny)
    return

for i in range(N):
    for j in range(M):
        if visited[i][j] != 1 and ice[i][j] == 0:
            count_ice += 1
            dfs(i, j)

print(count_ice)
