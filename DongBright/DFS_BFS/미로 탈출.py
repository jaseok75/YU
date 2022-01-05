"""
Project: 동빈나_DFS/BFS_미로 탈출
### 귀신이 곡할 노릇
### 맞 왜 틀?
Date: 2022.01.05.수.
"""

N, M = map(int, input().split())
input_map = [input() for _ in range(N)]
rect_map = []

for i in range(N):
    rect_map.append(list(map(int, input_map[i])))

def isRange(x, y):
    if x < 0 or x >= N or y < 0 or y >= M:
        return False
    else:
        return True

def bfs(x, y):
    # 북, 동, 남, 서
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    tile = []
    tile.append((x, y))

    while len(tile) != 0:
        (x, y) = tile.pop(0)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < M:
                if rect_map[nx][ny] == 1:
                    rect_map[nx][ny] = rect_map[x][y] + 1
                    tile.append((nx, ny))

    return rect_map[N - 1][M - 1]

distance = bfs(0, 0)
print(distance)
