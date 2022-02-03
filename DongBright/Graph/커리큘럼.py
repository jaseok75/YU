"""
Project: 동빈나_그래프 이론_커리큘럼
Date: 2022.01.12.수.
Content: 아직 성공 못한 코드임
"""

from collections import deque

def topology_sort():
    q = deque()

    for i in range(1, n + 1):
        if indegree[i] == 0:
            q.append(i)

    while q:
        now = q.popleft()
        print(graph[now])
        for i in graph[now][1]:
            indegree[i] -= 1
            if class_time[i] < graph[now][0]:
                class_time[i] = graph[now][0]
            if indegree[i] == 0:
                q.append(i)
    print(class_time)

if __name__ == "__main__":
    n = int(input())
    indegree = [0] * (n + 1)
    graph = []
    graph.append((0, []))
    class_time = [0] * (n + 1)

    for i in range(1, n + 1):
        study = list(map(int, input().split()))
        
        graph.append((study[0], study[1:-1]))
        indegree[i] += len(graph[i][1])
    print(graph)
    print(indegree)
    topology_sort()
