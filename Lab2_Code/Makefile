# Kelsey Hughes
# Lab 2 Makefile 

# Reminders for me
#   $@ - name of target 
#   $^ - list of dependencies 
#   $< - first dependencies 

# Variable definitions:
CC = g++
SHELL = /bin/bash 
CFLAGS = -fpic -g 
#CFLAGS = -

# code from lab 1 stats stuff
hughesk_stats.o: hughesk_stats.cpp hughesk_stats.hpp
	$(CC) -c $^

# code from lab 2 vector stuff
hughesk_vector_ops.o: hughesk_vector_ops.cpp hughesk_vector_ops.hpp
	$(CC) -c $^


hughesk_pre_processing.o: hughesk_pre_processing.cpp hughesk_pre_processing.hpp hughesk_stats.o hughesk_vector_ops.o
	$(CC) -o $@ $^

all: hughesk_pre_processing.o

clean:
	rm -f *.o
	rm -f *.gch