CC = gcc
CFLAGS = -Wall
DEPS = linked_list.h
OBJ = linked_list.o reverse_linked_list.o
SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c -o $@ $<

reverse_linked_list: $(OBJ)
		gcc $(CFLAGS) -o $@ $^
		rm *.o

clean: 
		rm -f $(PROGS)