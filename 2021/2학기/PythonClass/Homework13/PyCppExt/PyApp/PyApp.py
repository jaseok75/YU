"""
Project: Homework13.1
- Expanding Python with C/C++ Modules for MergeSorting
Author: Kim Ha Rim
Date of last update: 2021.12.08.
"""

#import math
#import PyCppExt

#print ("Testing PyCppExt on Visual Studio 2019")
#print ("math.pi = ", math.pi)

#probe_result = PyCppExt.probe ()
#print ("Result of PyCppExt.probe () = ", probe_result)

import math
import PyCppExt
import numpy as np
import sys
myPyPackage_dir = "F:/"
sys.path.append (myPyPackage_dir)
from MyPyPackage.myModules import MyList

print ("Testing PyCppExt on Visual Studio 2019")
#print ("math.pi = ", math.pi)

probe_result = PyCppExt.probe()
print("Result of PyCppExt.probe() = ", probe_result)
#add_result = PyCppExt.add(3, 5)
#print("PyCppExt.add(3, 5) = ", add_result)

#mul_result = PyCppExt.mul(3.1, 5.2)
#print ("PyCppExt.mul(3.1, 5.2) = ", mul_result)

#A = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
#B = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
#C = PyCppExt.add_arrays(A, B)
#print("A = ", A)
#print("B = ", B)
#print ("PyCppExt.add_arrays(A, B) = ", C)
#sorted_B = PyCppExt.sort_array(B)
#print ("Sorted_B = ", sorted_B)

#A = np.arange (0.1, 10.0, 1.1)
#B = np.arange (9.9, 0.0, -1.1)
#C = PyCppExt.add_arrays (A, B)
#print("A = ", A)
#print("B = ", B)
#print ("PyCppExt.add_arrays(A, B) = ", C)
#sorted_B = PyCppExt.sort_array(B)
#print ("Sorted_B = ", sorted_B)

L = []
n = 1000000
MyList.genRandList(L, n)
print ("Before sorting (n = {}) . . .".format(n))
MyList.printListSample(L, n, 10, 5)
sorted_L = PyCppExt.merge_sort(L, 0, n - 1)
print ("\nAfter sorting (n = {}) . . .".format(n))
MyList.printListSample(sorted_L, n, 10, 5)

L = []
n = 10000000
MyList.genRandList(L, n)
print ("Before sorting (n = {}) . . .".format (n))
MyList.printListSample (L, n, 10, 5)
sorted_L = PyCppExt.merge_sort(L, 0, n - 1)
print ("\nAfter sorting (n = {}) . . .".format (n))
MyList.printListSample(sorted_L, n, 10, 5)