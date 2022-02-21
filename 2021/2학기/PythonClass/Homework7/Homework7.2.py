"""
Project : Homework7.2
- 최소 10명의 학생 정보인 (학생 이름, 학번, 국어점수, 영어점수, 수학점수, 과학점수) 데이터를 텍스트 파일 student_records.txt에 준비하고,
이 파일을 읽어들인 후, 각 학생의 평균점수를 계산하여 학생 정보에 추가하고,
각 과목별로 학생들의 성적을 종합하여 평균 점수를 계산한 후,
결과를 output.txt 텍스트 파일에 출력하는 파이썬 프로그램을 작성하라.
Author : Ha-Rim Kim
Date of last update : 2021.10.22.
"""

import os
import os.path

PyTemp_dir = "F:\PyTemp"
file_1 = "F:\PyTemp\student_records.txt"
if os.path.exists(PyTemp_dir) == False:
    print("Directory {} is not existing, so creating . . ." .format(PyTemp_dir))
if os.path.exists(file_1) == False:
    print("File {} is not existing, so creating . . ." .format(file_1))

data_name = []
data_kor = []
data_eng = []
data_math = []
data_sci = []
kor_avg = 0
eng_avg = 0
math_avg = 0
sci_avg = 0

f1 = open(file_1, 'r')
for line in f1.readlines():
    name, kor, eng, math, sci = line.split()
    data_name.append(name)
    data_kor.append(int(kor))
    data_eng.append(int(eng))
    data_math.append(int(math))
    data_sci.append(int(sci))
    kor_avg += int(kor)
    eng_avg += int(eng)
    math_avg += int(math)
    sci_avg += int(sci)
    print("['{}', {}, {}, {}, {}]" .format(name, kor, eng, math, sci))
f1.close()

sum_data = [0] * len(data_name)
avg_data = []
kor_avg /= len(data_name)
eng_avg /= len(data_name)
math_avg /= len(data_name)
sci_avg /= len(data_name)

for i in range(len(data_name)):
    sum_data[i] += (data_kor[i] + data_eng[i] + data_math[i] + data_sci[i])
    avg_data.append(sum_data[i] / 4)

student_data = list(zip(data_name, data_kor, data_eng, data_math, data_sci, sum_data, avg_data))

print ("    name,      kor,      eng,     math,      sci,  sum,    avg")
print ("--------------------------------------------------------------")
for i in range (len (student_data)):
    print("{0:<8}, ".format(student_data[i][0]), end = '')
    print("{0:>8}, ".format(student_data[i][1]), end = '')
    print("{0:>8}, ".format(student_data[i][2]), end = '')
    print("{0:>8}, ".format(student_data[i][3]), end = '')
    print("{0:>8}, ".format(student_data[i][4]), end = '')
    print("{0:4d}, ".format(student_data[i][5]), end = '')
    print("{0:6.2f}".format(student_data[i][6]))

print("Average score of each class :")
print("Kor_avg  = ", kor_avg)
print("Eng_avg  = ", eng_avg)
print("Math_avg = ", math_avg)
print("Sci_avg  = ", sci_avg)

f_st_name = "output.txt"
f_st = open(f_st_name, 'w')

f_st.write("    name,      kor,      eng,     math,      sci,  sum,    avg\n")
f_st.write("--------------------------------------------------------------\n")
for i in range(len(student_data)):
    s = "{0:<8}, " .format(student_data[i][0])
    s += "{0:>8}, " .format(student_data[i][1])
    s += "{0:>8}, " .format(student_data[i][2])
    s += "{0:>8}, " .format(student_data[i][3])
    s += "{0:>8}, " .format(student_data[i][4])
    s += "{0:4d}, " .format(student_data[i][5])
    s += "{0:6.2f}" .format(student_data[i][6])
    s += '\n'
    f_st.write(s)
f_st.close()