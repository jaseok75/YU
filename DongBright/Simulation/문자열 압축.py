"""
Project: 동빈나_구현_문자열 압축
Date: 2022.01.14.금.
"""

def solution(s):
    answer = 0
    max_length = []
    output = ''

    if len(s) == 1:
        return 1

    for i in range(1, len(s) // 2 + 1):
        count_length = 1
        data_i = s[:i]
        for j in range(i, len(s), i):
            data = s[j:j+i]
            if data_i == data:
                count_length += 1
            else:
                if count_length == 1:
                    count_length = ''
                output += str(count_length) + data_i
                data_i = data
                count_length = 1
        if count_length == 1:
            count_length = ''
        output += str(count_length) + data_i
        max_length.append(len(output))
        output = ''

    answer = min(max_length)

    return answer

if __name__ == "__main__":
    s = "aabbaccc"

    answer = solution(s)
    print(answer)
