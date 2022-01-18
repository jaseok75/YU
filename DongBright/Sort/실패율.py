"""
Project: 동빈나_정렬_실패율
Date: 2022.01.18.화.
Comment: 내 실력 점점 활개를 칠 준비 중
"""

def solution(N, stages):
    stages.sort(reverse=True)
    failure_list = []
    for i in range(1, N + 1):
        total_player = 0
        for stage in stages:
            if stage >= i:
                total_player += 1
            else:
                break
        current_player = stages.count(i)
        if total_player == 0:
            failure = 0
        else:
            failure = current_player / total_player
        failure_list.append([failure, i])
    failure_list = sorted(failure_list, key = lambda x : (-x[0], x[1]))
    player_list = []
    for player in failure_list:
        player_list.append(player[1])
    return player_list

if __name__ == "__main__":
    n = 5
    stages = [2, 1, 2, 6, 2, 4, 3, 3]
    result = solution(n, stages)
    print(result)

    n = 4
    stages = [4, 4, 4, 4, 4]
    result = solution(n, stages)
    print(result)
