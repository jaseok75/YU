"""
Project: 동빈나_그래프 이론_도시 분할 계획
Date: 2022.01.12.수.
"""
import sys

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

if __name__ == "__main__":
    n, m = map(int, sys.stdin.readline().split())
    parent = [0] * (n + 1)
    edges = []
    total_cost = 0
    max_cost = 0

    for i in range(1, n + 1):
        parent[i] = i

    for _ in range(m):
        a, b, cost = map(int, sys.stdin.readline().split())
        edges.append((cost, a, b))

    edges.sort()

    for edge in edges:
        cost, a, b = edge
        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            total_cost += cost
            max_cost = cost

print(total_cost - max_cost)
