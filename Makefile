all:
	cd lib && make
	gcc *.c -c
	gcc *.o lib/*.o -o program
	rm *.o && rm lib/*.o 
