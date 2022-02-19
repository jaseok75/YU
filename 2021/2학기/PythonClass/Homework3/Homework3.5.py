"""
Project : Homework3.5
- 영어 단어 (어휘)를 key로 하고, 그 단어의 유의어 (thesaurus)들의 튜플을 값(value)으로 하는 아이템(item)들을 가지는 딕셔너리 (dict) Thesaurus_Dict를 구성하라.
  이 Thresaurus_Dict의 기본 key들은 어휘 리스트 List_Voca =[mean, resume, gentle, unique, evaluate, eligible, present, apparent,compromise, deteriorate]를 사용하도록 하며, 
  이 단어들의 유의어를 차례로 입력받아 튜플로 구성하여 Thesaurus_Dict에 추가하도록 하고, 
  완성된 Thesaurus_Dict를 사용하여 유의어를 검색할 수 있도록 keyword를 입력받은 후, 
  그 keyword에 해당하는 유의어들을 출력하여 주도록 파이썬 프로그램을 구현하라.
Author : Ha-Rim Kim
Date of last update : 2021.09.22.
"""
Thesaurus_Dict = dict()
key_words = ['mean', 'resume', 'gentle', 'unique', 'evaluate', 'eligible', 'present', 'apparent', 'compromise', 'deteriorate']

for key in key_words:
    thesaurus = list(map(str, input("input thesaurus of {} : ".format(key)).split()))
    Thesaurus_Dict[key] = thesaurus
    print (Thesaurus_Dict)

keyword = input("input keyword to search for thesaurus : ")

while keyword != '.':
    if keyword in Thesaurus_Dict:
        print ("Thesaurus of {} = {}".format(keyword, Thesaurus_Dict[keyword]))
    else:
        print ("keyword is not in Thesaurus_Dict!")
    keyword = input("input keyword to search for thesaurus : ")