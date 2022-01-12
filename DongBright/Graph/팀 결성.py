"""
Project: 동빈나_그래프 이론_팀 결성
Date: 2022.01.12.수.
"""

if __name__ == "__main__":
    n, m = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    answer = []
    for i in range(m):
        cal, a, b = map(int, input().split())
        if cal == 0:
            graph[a].append(b)
            graph[b].append(a)
        elif cal == 1:
            if a in graph[b]:
                answer.append('YES')
            else:
                answer.append('NO')
    for one in answer:
        print(one)
