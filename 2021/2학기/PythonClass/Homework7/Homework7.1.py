"""
Project : Homework7.1
- 최소 10개 국가의 기본 정보 (국가 이름, 수도 이름, 인구수, 면적) 데이터를 텍스트 파일 (demography.txt)에 준비하고,
  이 파일의 국가 기본 정보를 읽어들인 후 순차적으로 화면에 출력하는 파이썬 프로그램을 작성하라.
  한 줄에 한 국가씩 출력할 것.
  데이터 파일로부터 읽어들인 국가들의 기본 정보에서 인구 수를 기준으로 내림차순 정렬을 하고,
  그 순서대로 국가 기본 정보를 출력하는 파이썬 프로그램을 작성하라.
Author : Ha-Rim Kim
Date of last update : 2021.10.22.
"""

import os
import os.path

PyTemp_dir = "F:\PyTemp"
file_1 = "F:\PyTemp\demography.txt"
if os.path.exists(PyTemp_dir) == False:
    print("Directory {} is not existing, so creating . . ." .format(PyTemp_dir))

if os.path.exists(file_1) == False:
    print("File {} is not existing, so creating . . ." .foramt(file_1))

data_country_name = []
data_cap_name = []
data_number = []
data_area = []

f1 = open(file_1, 'r')
for line in f1.readlines():
    country, cap, number, area = line.split()
    data_country_name.append(country)
    data_cap_name.append(cap)
    data_number.append(number)
    data_area.append(area)
f1.close()

country_data = list(zip(data_country_name, data_cap_name, data_number, data_area))
print("List of countries:")
for i in range(len(country_data)):
    print("Country[{:2}] : {}" .format(i, country_data[i]))

print("\nList of countries sorted by demography(number of people) :")
for i in range(0, len(country_data)):
    print("Country[{:2}] : {}" .format(i, country_data[i]))