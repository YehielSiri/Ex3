CC = gcc
RM = rm
FLAGS = -Wall -g

.PHONY: all clean

all: isort txtfind

isort: isort.o insertion_sort.o
	$(CC) $(FLAGS) -o isort isort.o insertion_sort.o
txtfind: txtfind.o findInText.o
	$(CC) $(FLAGS) -o txtfind txtfind.o findInText.o
insertion_sort.o: insertion_sort.c insertion_sort.h
	$(CC) $(FLAGS) -fPIC -c insertion_sort.c
findInText.o: findInText.c findInText.h
	$(CC) $(FLAGS) -fPIC -c findInText.c
isort.o: isort.c insertion_sort.h
	$(CC) $(FLAGS) -fPIC -c isort.c
txtfind.o: txtfind.c findInText.h
	$(CC) $(FLAGS) -fPIC -c txtfind.c


clean:
	$(RM) -f *.o isort txtfind
