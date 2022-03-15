# 최장 증가 부분 수열 (Longest Increasing Subsequence)
- 원소가 n 개인 배열의 일부 원수를 골라내서 만든 부분 수열 중, 각 원소가 이전 원소보다 크다는 조건을 만족하고, 길이가 최대인 부분 수열
- Dynamic Programming을 사용해서 해결할 수 있다.
```c
for (int k = 0; k < n; k++) {
    length[k] = 1;
    for (int i = 0; i < k; i++) {
        if (arr[i] < arr[k]) {
            length[k] = max(length[k], length[i] + 1);
        }
    }
}
```
> LIS의 길이를 구하기 위해 이분 탐색을 활용할 수 있다.\n
> 이분 탐색 시 Lower Bound를 사용할 수 있다.
## Lower Bound
- 경계값을 찾는 함수이다. 정렬된 상태에서 사용할 수 있다.
- 찾는 값이 처음으로 나오는 인덱스를 찾는 것이기 때문에 right = mid를 사용했다.
- 응용해서 left = mid를 사용하면 찾는 값이 마지막으로 나오는 인덱스를 찾을 수 있다.
```py
def lower_bound(left, right, k):
    while left <= right:
        mid = (left + right) // 2
        if my_list[mid] < k:
            left = mid + 1
        elif my_list[mid] > k:
            right = mid - 1
        elif my_list[mid] == k:
            if right == mid:
                break
    if my_list[mid] == k:
        return mid
    else:
        return -1
```
