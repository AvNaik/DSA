$(CC) = gcc

all: strcpy pangram reverse search

search: search.o
	$(CC) -o search search.o

strcpy: strcpy.o
	$(CC) -o strcpy strcpy.o

pangram: pangram.o
	$(CC) -o pangram pangram.o

reverse: reverse.o
	$(CC) -o reverse reverse.o

search.o: search.c
	$(CC) -c search.c

strcpy.o: strcpy.c
	$(CC) -c strcpy.c

pangram.o: pangram.c
	$(CC) -c pangram.c

reverse.o: reverse.c
	$(CC) -c reverse.c

clean:
	rm -rf *.o $(OBJECTS) strcpy pangram reverse search
