$(CC) = gcc
CFLAGS = -I

all: insert

insert: insertion.o
	$(CC) -o insert insertion.o

insertion.o: insertion.c
	$(CC) -c insertion.c

clean:
	rm -rf *.o $(objects) insert
