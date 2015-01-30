#############################################
# 
# Simple makefile for timekeeper
#
CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = timekeeper.o  

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: timekeeper

timekeeper: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

cleanall:
	rm -f timekeeper *.o *~ core  

clean:
	rm -f *.o *~ core  
