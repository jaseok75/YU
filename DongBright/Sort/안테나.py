"""
Project: 동빈나_정렬_안테나
Date: 2022.01.18.화.
Coment: quick sort 느낌으로 
"""

def distance(array, target):
    result = 0
    for house in array:
        result += abs(house - target)
    return result

def left_min(array, target, mid_distance):
    result = mid_distance
    while target >= 0:
        target -= 1
        cal_distance = distance(array, array[target])
        if result < cal_distance:
            return target + 1
        else:
            result = cal_distance
    return target

def right_min(array, target, mid_distance):
    result = mid_distance
    while target < len(array) - 1:
        target += 1
        cal_distance = distance(array, array[target])
        if result < cal_distance:
            return target - 1
        else:
            result = cal_distance
    return target

if __name__ == "__main__":
    n = int(input())
    houses = list(map(int, input().split()))
    houses.sort()

    mid = len(houses) // 2
    min_distance = distance(houses, houses[mid])

    left_min_distance = left_min(houses, mid, min_distance)
    right_min_distance = right_min(houses, mid, min_distance)

    if left_min_distance < right_min_distance:
        print(houses[left_min_distance])
    else:
        print(houses[right_min_distance])
