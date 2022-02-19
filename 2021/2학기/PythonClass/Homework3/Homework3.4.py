"""
Project : Homework3.4
- 국가 (country)의 기본정보를 (국가이름, 인구수, 수도 도시 이름, 사용 언어, 대륙/지역)의 튜플로 표현하고, 10개의 국가 기본 정보 튜플들을 포함하는
국가 튜플 리스트를 준비한 후, 인구수가 지정된 규모보다 더 큰 국가들만 골라 출력
Author : Ha-Rim Kim
Date of last update : 2021.09.22.
"""
countries = [('Korea', 56000000, 'Seoul', 'Korean', 'Asia'),\
             ('Japan', 120000000, 'Tokyo', 'Japanese', 'Asia'),\
             ('China', 1300000000, 'Beijing', 'Chinese', 'Asia'),\
             ('USA', 170000000, 'Washington DC', 'English', 'North America'),\
             ('Canada', 30000000, 'Ottawa', 'English', 'North America'),\
             ('UK', 50000000, 'London', 'English', 'Europe'),\
             ('France', 65273511, 'Paris', 'French', 'Europe'),\
             ('Mexico', 126200200, 'Mexicocity', 'Spanish', 'North America'),\
             ('Germany', 83783941, 'Berlin', 'Germany', 'Europe'),\
             ('India', 1379619774, 'New Delhi', 'Kindu', 'Asia')]
idx = 0

for country in countries:
    print ("countries[{}] : name({:^10}), population({:>15}), capital({:<15}), language({:<10}), continent({:<15})".format(idx, country[0], country[1], country[2], country[3], country[4]))
    idx += 1

population = int(input ("\nInput threshold of population = "))

i = 0
for idx in range(10):
    if countries[i][1] < population:
        countries.remove(countries[i])
    else:
        i += 1

idx = 0
print ("\nCountries whose population is greater than {}".format(population))
for country in countries:
    print ("countries[{}] : name({:^10}), population({:>15}), capital({:<15}), language({:<10}), continent({:<15})".format(idx, country[0], country[1], country[2], country[3], country[4]))
    idx += 1