$(CC) = gcc

all: linear binary sublist

linear: linear.o
	$(cc) -o linear linear.o

binary: binary.o
	$(CC) -o binary binary.o

sublist: sublist.o
	$(CC) -o sublist sublist.o

linear.o: linear.c
	$(CC) -c linear.c

binary.o: binary.c
	$(CC) -c binary.c

sublist.o: sublist.c
	$(CC) -c sublist.c
clean:
	rm -rf *.o $(objects) linear binary sublist
