# Makefile for "a5" C++ application
# Created by Siddharth Gupta 15/07/2019

CC = g++
FLAGS = -g -Wall -c

p15.o:
	$(CC) $(FLAGS) 15p.cpp

p25.o:
	$(CC) $(FLAGS) 25.cpp

clean :
	rm -f $(PROG) $(OBJS)