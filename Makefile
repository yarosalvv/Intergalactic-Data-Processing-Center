

# Clearing all generated files
clean:
	rm -f *.o test_student1 test_student2 test_student3

# Running all the tests
all_test: test1 test2 test3

# Test program for student1 
test_student1: test_student1.o student1.o
	gcc -Wall -Wextra -std=c99 test_student1.o student1.o -o test_student1 -lm

# Compilation of the student1 module
student1.o: student1.c student1.h
	gcc -Wall -Wextra -std=c99 -c student1.c -o student1.o

# Compilation of tests for student1
test_student1.o: test_student1.c student1.h
	gcc -Wall -Wextra -std=c99 -c test_student1.c -o test_student1.o

# Test program for student2  
test_student2: test_student2.o student2.o
	gcc -Wall -Wextra -std=c99 test_student2.o student2.o -o test_student2 -lm

# Compilation of the student2 module
student2.o: student2.c student2.h
	gcc -Wall -Wextra -std=c99 -c student2.c -o student2.o

# Compilation of tests for student2
test_student2.o: test_student2.c student2.h
	gcc -Wall -Wextra -std=c99 -c test_student2.c -o test_student2.o

# Test program for student3
test_student3: test_student3.o student3.o
	gcc -Wall -Wextra -std=c99 test_student3.o student3.o -o test_student3 -lm

# Compilation of the student3 module
student3.o: student3.c student3.h
	gcc -Wall -Wextra -std=c99 -c student3.c -o student3.o

# Compilation of tests for student3
test_student3.o: test_student3.c student3.h
	gcc -Wall -Wextra -std=c99 -c test_student3.c -o test_student3.o

# Running tests for student1
test1: test_student1
	./test_student1

# Running tests for student2
test2: test_student2
	./test_student2

# Running tests for student3
test3: test_student3
	./test_student3