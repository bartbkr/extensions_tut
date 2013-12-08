"C:\Program Files (x86)\CodeBlocks\MinGW\bin\gcc.exe" -mdll -O -Wall -IC:\python27\lib\site-packages\numpy\core\include\numpy -IC:\python27\include -IC:\python27\PC -c funcs.c -o funcs.o
"C:\Program Files (x86)\CodeBlocks\MinGW\bin\gcc.exe" -shared -s funcs.o -LC:\python27\libs -LC:\python27\PCbuild -lpython27 -lmsvcr90 -o _funcs.pyd
