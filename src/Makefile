CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = scheduler

all: $(TARGET)

$(TARGET): main.o process.o scheduler.o
	$(CC) $(CFLAGS) main.o process.o scheduler.o -o $(TARGET)

main.o: main.c process.h scheduler.h
	$(CC) $(CFLAGS) -c main.c

process.o: process.c process.h
	$(CC) $(CFLAGS) -c process.c

scheduler.o: scheduler.c scheduler.h process.h
	$(CC) $(CFLAGS) -c scheduler.c

clean:
	rm -f *.o $(TARGET)
