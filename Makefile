# Цели проекта по умолчанию (собирает все программы)
all: project test_student1 test_student2 test_student3

# Очистка всех сгенерированных файлов
clean:
	rm -f *.o project test_student1 test_student2 test_student3

all_test: test1 test2 test3

# Основная программа проекта (объединяет три студенческих модуля)
project: main.o student1.o student2.o student3.o
	gcc -Wall -Wextra -std=c99 main.o student1.o student2.o student3.o -o project -lm

# Компиляция главного модуля
main.o: main.c student1.h student2.h student3.h
	gcc -Wall -Wextra -std=c99 -c main.c -o main.o

# Тестовая программа для student1  
test_student1: test_student1.o student1.o
	gcc -Wall -Wextra -std=c99 test_student1.o student1.o -o test_student1 -lm

# Компиляция модуля student1
student1.o: student1.c student1.h
	gcc -Wall -Wextra -std=c99 -c student1.c -o student1.o

# Компиляция тестов для student1
test_student1.o: test_student1.c student1.h
	gcc -Wall -Wextra -std=c99 -c test_student1.c -o test_student1.o

# Тестовая программа для student2  
test_student2: test_student2.o student2.o
	gcc -Wall -Wextra -std=c99 test_student2.o student2.o -o test_student2 -lm

# Компиляция модуля student2
student2.o: student2.c student2.h
	gcc -Wall -Wextra -std=c99 -c student2.c -o student2.o

# Компиляция тестов для student2
test_student2.o: test_student2.c student2.h
	gcc -Wall -Wextra -std=c99 -c test_student2.c -o test_student2.o

# Тестовая программа для student3
test_student3: test_student3.o student3.o
	gcc -Wall -Wextra -std=c99 test_student3.o student3.o -o test_student3 -lm

# Компиляция модуля student3
student3.o: student3.c student3.h
	gcc -Wall -Wextra -std=c99 -c student3.c -o student3.o

# Компиляция тестов для student3
test_student3.o: test_student3.c student3.h
	gcc -Wall -Wextra -std=c99 -c test_student3.c -o test_student3.o

# Запуск тестов для student1
test1: test_student1
	./test_student1

# Запуск тестов для student2
test2: test_student2
	./test_student2

# Запуск тестов для student3
test3: test_student3
	./test_student3