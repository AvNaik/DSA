$(CC) = gcc
CFLAGS = -I

all: insertion insertion_alternative delete search middle rotate segregate reverse

reverse: reverse.o
	$(CC) -o reverse reverse.o

segregate: segregate.o
	$(CC) -o segregate segregate.o

rotate: rotate.o
	$(CC) -o rotate rotate.o 
middle: middle.o
	$(CC) -o middle middle.o

search: search.o
	$(CC) -o search search.o

delete: delete.o
	$(CC) -o delete delete.o

insertion_alternative: insertion_alternative.o
	$(CC) -o insertion_alternative insertion_alternative.o

insertion: insertion.o
	$(CC) -o insertion insertion.o

reverse.o: reverse.c
	$(CC) -c reverse.c

segregate.o: segregate.c
	$(CC) -c segregate.c
rotate.o: rotate.c
	$(CC) -c rotate.c

middle.o: middle.c
	$(CC) -c middle.c

search.o: search.c
	$(CC) -c search.c

delete.o: delete.c
	$(CC) -c delete.c

insertion_alternative.o: insertion_alternative.c
	$(CC) -c insertion_alternative.c

insertion.o: insertion.c
	$(CC) -c insertion.c

clean:
	rm -rf *.o $(objects) insertion_alternative insertion delete search middle rotate segregate reverse
	

