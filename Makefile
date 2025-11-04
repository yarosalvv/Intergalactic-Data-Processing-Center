all: project test_program

clean:
	rm -f *.o project test_program

project: main.o student3.o
	gcc -Wall -Wextra -std=c99 main.o student3.o -o project -lm

test_program: tests.o student3.o
	gcc -Wall -Wextra -std=c99 tests.o student3.o -o test_program -lm

main.o: main.c student3.h
	gcc -Wall -Wextra -std=c99 -c main.c -o main.o

student3.o: student3.c student3.h
	gcc -Wall -Wextra -std=c99 -c student3.c -o student3.o

tests.o: tests.c student3.h
	gcc -Wall -Wextra -std=c99 -c tests.c -o tests.o
