all:
	gcc lib/*.c -c
	gcc *.c -c
	gcc lib/*.o *.o -o program
	rm lib/*.o
	rm *.o
	./program