# 최장 공통 부분수열(Longest Common Subsequence)
- 연속적이지 않은 부분 문자열이다.
## 점화식
> if i == 0 or j == 0:
>
>    LCS[i][j] = 0
> elif string_A[i] == string_B[j]:
>     LCS[i][j] = LCS[i - 1][j - 1] + 1
> else:
>     LCS[i][j] = max[LCS[i - 1][j], LCS[i][j - 1])
