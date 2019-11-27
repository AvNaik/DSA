$(CC) = gcc
CFLAGS = -I

all: stack_array stack_ll parenthesis postfix

postfix: postfix.o
	$(CC) -o postfix postfix.o

parenthesis: parenthesis.o
	$(CC) -o parenthesis parenthesis.o

stack_ll: stack_ll.o
	$(CC) -o stack_ll stack_ll.o

stack_array: stack_a.o
	$(CC) -o stack_array stack_a.o

postfix.o: postfix.c
	$(CC) -c postfix.c

parenthesis.o: parenthesis.c
	$(CC) -c parenthesis.c

stack_ll.o: stack_ll.c
	$(CC) -c stack_ll.c

stack_a.o: stack_a.c
	$(CC) -c stack_a.c

clean:
	rm -rf *.o $(objects) stack_a stack_ll parenthesis postfix

