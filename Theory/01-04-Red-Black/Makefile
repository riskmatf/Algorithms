.PHONY : clean
red-black: main.o rb.o
	gcc -o red-black main.o rb.o

main.o: main.c
	gcc -c -o main.o main.c

rb.o: rb.c
	gcc -c -o rb.o rb.c

clean:
	rm -f ~*
	rm -f *.o
	rm -f red-black
