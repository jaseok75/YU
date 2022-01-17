"""
Project: 동빈나_구현_특정 거리의 도시 찾기
Date: 2022.01.14.금.
Coment: 
- DFS로 구현했지만 메모리 초과 젠장
- 모든 노드에 몇 번씩 반복하면서 들어가고 재귀로 하다보니 난장판이 난 것 같다.
- 코드는 굉장히 간단했지만,
- 내가 해결할 수 없다
- 결론: DFS는 방법이 될 수 없었다.
"""
import sys
sys.setrecursionlimit(10**6)

def dfs(idx, cost):
    for city in citys[idx]:
        if distance[city] == 0:
            distance[city] = cost + 1
        elif distance[city] != 0:
            distance[city] = min(cost + 1, distance[city])
        dfs(city, distance[city])
    return

if __name__ == "__main__":
    n, m, k, x = map(int, sys.stdin.readline().split())
    citys = [[] for i in range(n + 1)]
    distance = [0] * (n + 1)
    flag = 0

    for i in range(m):
        a, b = map(int, sys.stdin.readline().split())
        citys[a].append(b)
    dfs(x, 0)

    for i in range(n, 1, -1):
        if distance[i] == k:
            print(i)
            flag = 1

    if flag == 0:
        print("-1")
