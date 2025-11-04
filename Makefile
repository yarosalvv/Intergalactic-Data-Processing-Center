# Цели проекта по умолчанию (собирает все программы)
all: project test_program test_student2

# Очистка всех сгенерированных файлов
clean:
	rm -f *.o project test_program test_student2

# Основная программа проекта (объединяет оба студенческих модуля)
project: main.o student2.o student3.o
	gcc -Wall -Wextra -std=c99 main.o student2.o student3.o -o project -lm

# Тестовая программа для student3
test_program: tests.o student3.o
	gcc -Wall -Wextra -std=c99 tests.o student3.o -o test_program -lm

# Тестовая программа для student2  
test_student2: test_student2.o student2.o
	gcc -Wall -Wextra -std=c99 test_student2.o student2.o -o test_student2 -lm

# Компиляция основного файла (зависит от обоих заголовочных файлов)
main.o: main.c student2.h student3.h
	gcc -Wall -Wextra -std=c99 -c main.c -o main.o

# Компиляция модуля student2
student2.o: student2.c student2.h
	gcc -Wall -Wextra -std=c99 -c student2.c -o student2.o

# Компиляция модуля student3
student3.o: student3.c student3.h
	gcc -Wall -Wextra -std=c99 -c student3.c -o student3.o

# Компиляция тестов для student3
tests.o: tests.c student3.h
	gcc -Wall -Wextra -std=c99 -c tests.c -o tests.o

# Компиляция тестов для student2
test_student2.o: test_student2.c student2.h
	gcc -Wall -Wextra -std=c99 -c test_student2.c -o test_student2.o

# Запуск тестов для student2
test2: test_student2
	./test_student2

# Запуск тестов для student3
test3: test_program
	./test_program
