# 최장 공통 부분수열(Longest Common Subsequence)
- 연속적이지 않은 부분 문자열이다.
## 점화식
``` py
if i == 0 or j == 0:
    LCS[i][j] = 0
```
