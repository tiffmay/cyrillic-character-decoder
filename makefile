CC = g++
CFLAGS = -Wall -g

all: main

main: main.o cyrillicEncoder.o hashTable.o
	${CC} ${CFLAGS} -o encoder main.o cyrillicEncoder.o  hashTable.o

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp 

cyrillicEncoder.o: cyrillicEncoder.cpp 
	$(CC) $(CFLAGS) -c cyrillicEncoder.cpp

hashTable.o: hashTable.cpp 
	$(CC) $(CFLAGS) -c hashTable.cpp

clean:
	rm *.o encoder
