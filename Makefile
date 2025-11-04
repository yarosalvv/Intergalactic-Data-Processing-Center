all: progect1

clean: 
	rm -f student2.o test_student2.o main.o progect1 test_student2

progect1: main.o student2.o
	gcc -Wall -Wextra -std=c99 main.o student2.o -o progect1 -lm

main.o: main.c
	gcc -Wall -Wextra -std=c99 -c main.c -o main.o

student2.o: student2.c
	gcc -Wall -Wextra -std=c99 -c student2.c -o student2.o

test_student2: test_student2.c student2.c
	gcc -Wall -Wextra -std=c99 test_student2.c student2.c -o test_student2 -lm

test2: test_student2
	./test_student2

