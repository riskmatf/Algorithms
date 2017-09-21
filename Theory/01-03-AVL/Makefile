.PHONY : clean


avl: main.o avl.o util.o
	gcc -o avl  main.o avl.o util.o

main.o: main.c
	gcc -c -o main.o main.c

avl.o: avl.c 
	gcc -c -o avl.o avl.c

util.o: ../util.c ../util.h
	gcc -c -o util.o ../util.c


clean:
	rm -f *~
	rm -f *.o
	rm -f avl
