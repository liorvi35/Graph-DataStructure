# This file contains the `make` for graph program
# authors: Lior Vinman & Yoad Tamar


CC = gcc
CFLAGS = -Wall -g
TARGETS = graph

.PHONY: default all clean

default: all

all: $(TARGETS)

graph: graph.o main.o
	$(CC) $(CFLAGS) -o $@ $^

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c $^

main.o: main.c graph.h
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o *.h.gch $(TARGETS)
	
