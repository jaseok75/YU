"""
Project: 동빈나_최단 경로_미래 도시
Date: 2022.01.11.화.
"""

import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(X, graph):
    q = []
    heapq.heappush(q, (0, X))
    distance = [INF] * (N + 1)
    distance[X] = 0
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

def future(X, K, graph):
    arrive_K = dijkstra(1, graph)
    arrive_X = dijkstra(K, graph)
    print(arrive_K[K] + arrive_X[X])

if __name__ == "__main__":
    N, M = map(int, input().split())
    graph = [[] for i in range(N + 1)]
    print(graph)
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append((b, 1))
        graph[b].append((a, 1))
    X, K = map(int, input().split())

    future(X, K, graph)
