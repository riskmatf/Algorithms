.PHONY : clean
BST: main.o bst.o
	gcc -o BST main.o bst.o

bst.o: bst.c
	gcc -c bst.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f ~*
	rm -f *.o
	rm -f BST
