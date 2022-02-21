CC = g++
SHELL = /bin/bash
CFLAGS = -fpic -g
LIBS = -lm #math library

#compile vector_ops
hughesk_vector_ops.o: hughesk_vector_ops.cpp hughesk_vector_ops.hpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

vectorlib: hughesk_vector_ops.cpp hughes_vector_ops.hpp
	$(CC) -L./ $^ -o $@ -lvect -Wl,-rpath=./

vect.so: hughesk_vector_ops.cpp hughesk_vector_ops.hpp 
	$(CC) -shared $^ -o $@

#compiles stats code
hughesk_stats.o: hughesk_stats.cpp hughesk_stats.hpp 
	#$(CC) $(CFLAGS) -o -I$(INCDIR) $@ $< $(LIBDIR) 
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)  

statslib: hughesk_stats.cpp hughesk_stats.hpp
	$(CC) -L./ $^ -o $@ -lstats -Wl,-rpath=./

stats.so: hughesk_stats.cpp hughesk_stats.hpp
	$(CC) -shared $^ -o $@