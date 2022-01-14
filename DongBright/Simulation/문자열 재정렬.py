"""
Project: 동빈나_구현_문자열 재정렬
Date: 2022.01.14.금.
"""

import re

if __name__ == "__main__":
    str_input = input()
    numbers = re.sub(r'[^0-9]', '', str_input)
    str_input = re.sub(r'[0-9]+', '', str_input)
    print(numbers)
    print(str_input)
    sum_numbers = str(sum([int(i) for i in numbers]))
    str_input = ''.join(sorted(str_input))
    print(str_input + sum_numbers)
