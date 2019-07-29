# Makefile for "a5" C++ application
# Created by Siddharth Gupta 15/07/2019

PROG = all
CC = g++
FLAGS = -g -Wall -c
OBJS = main.o modules.o heuristics.o problem.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o :
	$(CC) $(FLAGS) main.cpp

modules.o :
	$(CC) $(FLAGS) modules.cpp

heuristics.o:
	$(CC) $(FLAGS) heuristics.cpp

problem.o:
	$(CC) $(FLAGS) problem.cpp

clean :
	rm -f $(PROG) $(OBJS)