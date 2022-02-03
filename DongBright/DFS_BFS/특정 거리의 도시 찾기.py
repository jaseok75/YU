"""
Project: 동빈나_구현_특정 거리의 도시 찾기
Date: 2022.01.14.금.
Coment:
- 결국 Dijkstra로 해결
"""

import sys
import heapq
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
    n, m, k, x = map(int, input().split())
    graph = [[] for i in range(n + 1)]
    flag = 0

    for _ in range(m):
        a, b = map(int , input().split())
        graph[a].append((b, 1))

    distance = dijkstra(x, graph)

    for i in range(1, n + 1):
        if distance[i] == k:
            print(i)
            flag = 1

    if flag == 0:
        print("-1")
