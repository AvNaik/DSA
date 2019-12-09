$(CC) = gcc
CFLAGS = -I

all: insert delete

delete: delete.o
	$(CC) -o delete delete.o

insert: insert.o
	$(CC) -o insert insert.o

delete.o: delete.c
	$(CC) -c delete.c

insert.o: insert.c
	$(CC) -c insert.c

clean:
	rm -rf *.o $(objects) insert delete
