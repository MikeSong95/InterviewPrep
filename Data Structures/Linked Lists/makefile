CC = gcc
CFLAGS = -Wall -Wextra -g
DEPS = linked_list.c

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: reverse_linked_list remove_kth_node_from_end

reverse_linked_list: reverse_linked_list.o
		gcc $(CFLAGS) -g $@.c $(DEPS) -o $@ 
		rm -f *.o
		
remove_kth_node_from_end: remove_kth_node_from_end.o
		gcc $(CFLAGS) -g $@.c $(DEPS) -o $@ 
		rm -f *.o

clean: 
		rm -f $(PROGS)