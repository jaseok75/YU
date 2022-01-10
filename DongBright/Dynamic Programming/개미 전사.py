"""
Project: 동빈나_개미 전사
Date: 2022.01.10.월.
"""

def ant(N, K):
    attack = [0] * 100
    attack[0] = K[0]
    attack[1] = max(K[0], K[1])

    for i in range(2, N):
        attack[i] = max(attack[i - 1], attack[i - 2] + K[i])

    return attack[N - 1]

if __name__ == "__main__":
    N = int(input())
    K = list(map(int, input().split()))

    answer = ant(N, K)
    print(answer)
