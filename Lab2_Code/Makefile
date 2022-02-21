CC = g++
SHELL = /bin/bash
CFLAGS = -fpic -g
LIBS = -lm #math library



#compiles stats code
hughesk_stats.o: hughesk_stats.cpp hughesk_stats.hpp 
	$(CC) $(CFLAGS) -o $@ $< $(LIBS) 
	 

statslib: hughesk_stats.cpp hughesk_stats.hpp
	$(CC) -L./ $^ -o $@ -lvect -Wl,-rpath=./

stats.so: hughesk_stats.cpp hughesk_stats.hpp
	$(CC) -shared $^ -o $@

#compile vector_ops
hughesk_vector_ops.o: hughesk_vector_ops.cpp hughesk_vector_ops.hpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS) 

vectorlib: hughesk_vector_ops.cpp hughes_vector_ops.hpp
	$(CC) -L./ $^ -o $@ -lvect -Wl,-rpath=./

vect.so: hughesk_vector_ops.cpp hughesk_vector_ops.hpp 
	$(CC) -shared $^ -o $@
#compiles processing code
hughesk_processing.o: hughesk_pre_processing.cpp hughesk_pre_processing.hpp 
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)  

processinglib: hughesk_pre_processing.cpp hughesk_pre_processing.hpp
	$(CC) -L./ $^ -o $@ -lvect -Wl,-rpath=./

processing.so: hughesk_pre_processing.cpp hughesk_pre_processing.hpp
	$(CC) -shared $^ -o $@


# new target to make all targets
makeall: hughesk_vectors_ops.o vectorlib vect.so hughesk_stats.o statslib stats.so hughesk_processing.o processinglib processing.so  

# clean directory from .o files 
clean: hughesk_stats.o hughesk_processing.o hughesk_vector_ops.o vect.so processing.so stats.so 
	rm *.o 
	rm *.so 
