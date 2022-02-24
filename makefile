CC = g++
CFLAGS = -Wall -g

all: main

main: main.o cyrillicEncoder.o
	${CC} ${CFLAGS} -o encoder main.o cyrillicEncoder.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

cyrillicEncoder.o: cyrillicEncoder.cpp 
	$(CC) $(CFLAGS) -c cyrillicEncoder.cpp

clean:
	rm *.o encoder
