"""
Project : Homework8.3
- 거리를 나타내는 단위인 Km와 mile의 양방향 변환 계산기를 구현하라.
  이 변환기에는 Km 단위 거리와 Mile 단위 거리를 입력할 수 있는 entry가 있으며,
  Km와 Mile을 나타내는 lable이 표시되고, "Km->Mile" 버튼과 "Km<-Mile" 버튼이 표시된다.
Author : Ha-Rim Kim
Date of last update : 2021.11.02.
"""

from tkinter import*

class Km_to_Mile:
    def __init__(self, master):
        frame=Frame(master)
        frame.pack()
        Label(frame, text='km').grid(row=0, column=1)
        self.km_var=DoubleVar()
        Entry(frame, textvariable=self.km_var).grid(row=0, column=0)
        Label(frame, text='mile').grid(row=0, column=3)
        self.mile_var=DoubleVar()
        self.mile_var.set(0.0)
        Entry(frame, textvariable=self.mile_var).grid(row=0, column=2)
        button_km_to_mile=Button(frame, text='Km -> Mile', command=self.convert_km_to_mile)
        button_km_to_mile.grid(row=1, column=0)
        button_mile_to_km=Button(frame, text='Mile -> Km', command=self.convert_mile_to_km)
        button_mile_to_km.grid(row=1, column=2)

    def convert_km_to_mile(self):
        km=self.km_var.get()
        self.mile_var.set(km/1.60934)

    def convert_mile_to_km(self):
        mile=self.mile_var.get()
        self.km_var.set(mile*1.60934)



window=Tk()
window.wm_title('Km < - > Mile Converter')
km_to_mile=Km_to_Mile(window)
window.mainloop()