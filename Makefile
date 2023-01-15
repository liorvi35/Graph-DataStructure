CC = gcc
FLAGS = -Wall -g

.PHONY: all clean

all: graph

graph: graph.o main.o
	$(CC) $(FLAGS) -o graph graph.o main.o

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c graph.h

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c graph.h

clean:
	rm -f *.o *.h.gch graph
