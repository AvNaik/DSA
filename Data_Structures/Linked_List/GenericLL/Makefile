$(CC) = gcc
CFLAGS = -I

all: insertion middle search reverse rotate represent

represent: represent.o
	$(CC) -o represent represent.o -lm

rotate: rotate.o
	$(CC) -o rotate rotate.c

reverse: reverse.o
	$(CC) -o reverse reverse.o

search: search.o
	$(CC) -o search search.o

insertion: insertion.o
	$(CC) -o insertion insertion.o

middle: middle.o
	$(CC) -o middle middle.o 

insertion.o: insertion.c
	$(CC) -c insertion.c

middle.o: middle.c 
	$(CC) -c middle.c

search.o: search.c
	$(CC) -c search.c

reverse.o: reverse.c
	$(CC) -c reverse.c

rotate.o: rotate.c
	$(CC) -c rotate.c

represent.o: represent.c
	$(CC) -c represent.c

clean:
	rm -rf *.o $(objects) insertion middle search reverse rotate represent
	

