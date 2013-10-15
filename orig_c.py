"""
Implements a simple Python iteration dillema
"""
import numpy as np
import _funcs

def iterator_c_call(size, mult):
    arr = np.zeros((size, size))
    _funcs.iterator_c(arr, mult)
    return arr

#mycarr = iterator_c_call(1000, 4)

# if __name__ == '__main__':
#     import timeit
#     print(timeit.timeit("iterator_c_call(1000, 4)", 
#           setup="from __main__ import iterator_c_call"))
