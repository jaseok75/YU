"""
Project: DongBright_다이나믹 프로그래밍_금광
Date: 2022.01.25.화.
Comment:
- 역시 다이나믹 프로그래밍
- index를 잘 봐야할 것 같다.
"""

def max_gold(gold):
    gold_table = [[0] * m for _ in range(n)]
    gold_table[0][0] = gold[0][0]
    gold_table[1][0] = gold[1][0]
    gold_table[2][0] = gold[2][0]
    for j in range(1, m):
        for i in range(n):
            if i == 0:
                up = 0
            else:
                up = gold_table[i - 1][j - 1]
            if i == n - 1:
                down = 0
            else:
                down = gold_table[i + 1][j - 1]
            middle = gold_table[i][j - 1]
            gold_table[i][j] = max(up, down, middle) + gold[i][j]
    result = 0
    for i in range(n):
        result = max(result, gold_table[i][m - 1])
    return result

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n, m = map(int, input().split())
        gold = list(map(int, input().split()))
        gold = [gold[j * m:(j + 1) * m] for j in range(n)]
        print(max_gold(gold))
