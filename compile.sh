gcc -pthread -fno-strict-aliasing -g -O0 -Wall -Wstrict-prototypes -fPIC -I/usr/local/lib/python2.7/dist-packages/numpy/core/include/numpy -I/usr/include/python2.7_d  -c funcs.c -o funcs.o
gcc -pthread -shared -Wl,-O1 -Wl,-Bsymbolic-functions -Wl,-Bsymbolic-functions -Wl,-z,relro funcs.o -o _funcs_d.so


