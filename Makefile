all : BST.out BST2.out

BST.out : main.o
	g++ -ansi -Wall -g -o BST.out main.o

BST2.out : main2.o
	g++ -ansi -Wall -g -o BST2.out main2.o

main.o : main.cpp BinarySearchTree.cpp BinarySearchTree.h
	g++ -ansi -Wall -g -DNDEBUG -c main.cpp

main2.o : main.cpp BinarySearchTree.cpp BinarySearchTree.h
	g++ -ansi -Wall -g -c -o main2.o main.cpp

clean :
	rm -f BST.out BST2.out main.o main2.o
