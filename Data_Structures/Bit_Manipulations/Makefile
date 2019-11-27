$(CC) = gcc
CFLAGS = -I

all: binary

binary: binary.o
	$(CC) -o binary binary.o

binary.o: binary.c
	$(CC) -c binary.c

clean:
	rm -rf *.o $(objects) binary
