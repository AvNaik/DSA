$(CC) = gcc

all: insertion_sort merge_sort quick_sort

insertion_sort: insertion_sort.o
	$(CC) -o insertion_sort insertion_sort.o

merge_sort: merge_sort.o
	$(CC) -o merge_sort merge_sort.o

quick_sort: quick_sort.o
	$(CC) -o quick_sort quick_sort.o

quick_sort.o: quick_sort.c
	$(CC) -c quick_sort.c

merge_sort.o: merge_sort.c
	$(CC) -c merge_sort.c

insertion_sort.o: insertion_sort.c
	$(CC) -c insertion_sort.c

clean:
	rm -rf *.o $(objects) insertion_sort merge_sort quick_sort
