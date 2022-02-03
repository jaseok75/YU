"""
Project: DongBright_최단 경로 문제_플로이드
Date: 2022.01.26.수.
Comment:
- 제출하니까 플로이드 방식으로 한 게 더 시간이 적게 걸렸다.
"""

import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(x, graph):
    q = []
    heapq.heappush(q, (0, x))
    distance = [INF] * (n + 1)
    distance[x] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance

if __name__ == "__main__":
    n = int(input())
    m = int(input())
    graph = [[] for i in range(n + 1)]

    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a].append((b, c))

    for j in range(1, n + 1):
        result = dijkstra(j, graph)
        result = result[1:]
        for idx in result:
            if idx == INF:
                print("0", end=" ")
            else:
                print(idx, end=" ")
        print()
