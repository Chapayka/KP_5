all: PR3_array.o PR3_matrix.o lib1.so lib2.so load.o load.so PR3_main.o PR3_main

PR3_array.o: PR3_array.c
	gcc -c -o PR3_array.o -fPIC PR3_array.c

PR3_matrix.o: PR3_matrix.c
	gcc -c -o PR3_matrix.o -fPIC PR3_matrix.c

lib1.so: PR3_array.o
	gcc -shared -o lib1.so PR3_array.o

lib2.so: PR3_matrix.o
	gcc -shared -o lib2.so PR3_matrix.o

load.o: load.c
	gcc -c -fPIC load.c

load.so: load.o
	gcc -shared -o load.so load.o

PR3_main.o: PR3_main.c
	gcc -c -fPIC PR3_main.c

PR3_main: PR3_main.o
	gcc -o PR3_main PR3_main.o -L./ -lload -ldl

clean:
	rm -f *.o *.so PR3_main