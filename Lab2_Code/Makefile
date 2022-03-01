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

# stats
hughesk_stats.o: hughesk_stats.cpp hughesk_stats.hpp
	$(CC) -c $^

# vector
hughesk_vector_ops.o: hughesk_vector_ops.cpp hughesk_vector_ops.hpp
	$(CC) -c $^

# pre-processing
hughesk_pre_processing.o: hughesk_pre_processing.cpp hughesk_pre_processing.hpp hughesk_stats.o hughesk_vector_ops.o
	$(CC) -o $@ $^

# clustering
hughesk_k_means.o: hughesk_k_means.cpp hughesk_k_means.hpp hughesk_stats.o
	$(CC) -o $@ $^

all: hughesk_pre_processing.o hughesk_k_means.o

clean:
	rm -f *.o
	rm -f *.gch