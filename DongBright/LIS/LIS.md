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
- LIS의 길이를 구하기 위해 이분 탐색을 활용할 수 있다.
