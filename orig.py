"""
Implements a simple Python iteration dillema
"""
import numpy as np

def iterator(size, mult):
    arr = np.ndarray((size, size), dtype=np.float64)
    x = 0
    it = 0
    for ix in np.nditer(arr, op_flags=['readwrite']):
        ix[...] = x
        x += it * mult
        it += 1
    return arr

#myarr = iterator(1000, 4)

# if __name__ == '__main__':
#     import timeit
#     print(timeit.timeit("iterator(1000, 4)", 
#           setup="from __main__ import iterator"))
