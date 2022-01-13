"""
Project: 동빈나_그리디_모험가 길드
Date: 2022.01.13.목.
"""

if __name__ == "__main__":
    n = int(input())
    traveler = list(map(int, input().split()))
    traveler.sort(reverse=True)
    count_team = 0

    while traveler:
        leader = traveler.pop(0)
        count_team += 1
        for i in range(1, leader):
            traveler.pop(0)
    print(count_team)
