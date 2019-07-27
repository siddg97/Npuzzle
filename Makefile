# Makefile for "a5" C++ application
# Created by Siddharth Gupta 15/07/2019

PROG = all
CC = g++
FLAGS = -g -Wall -c
OBJS = main.o modules.o h.o p.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) $(FLAGS) main.cpp

modules.o :
	$(CC) $(FLAGS) modules.cpp

h.o:
	$(CC) $(FLAGS) heuristics.cpp

p.o:
	$(CC) $(FLAGS) puzzle.cpp

clean :
	rm -f $(PROG) $(OBJS)