$(CC) = gcc
CFLAGS = _I

all: a_q c_q q_ll p_q

p_q: p_queue.o
	$(CC) -o p_q p_queue.o

q_ll: q_ll.o
	$(CC) -o q_ll q_ll.o

c_q: circularq_array.o
	$(CC) -o c_q circularq_array.o

a_q: q_array.o
	$(CC) -o a_q q_array.o

p_queue.o: p_queue.c
	$(CC) -c p_queue.c

q_ll.o: q_ll.c
	$(CC) -c q_ll.c

circularq_array.o: circularq_array.c
	$(CC) -c circularq_array.c

q_array.o: q_array.c
	$(CC) -c q_array.c

clean:
	rm -rf *.o $(objects) a_q c_q q_ll p_q
