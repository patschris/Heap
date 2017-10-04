CC		= gcc
CFLAGS	= -g3 -Wall
EXEC 	= HeapSimulation
OBJS 	= main.o heap.o
SRCS 	= main.c heap.c


.PHONY : all
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

heap.o: heap.c
	$(CC) $(CFLAGS) -c heap.c



.PHONY: clean
clean:
	rm -f $(OBJS) $(EXEC)



.PHONY: run
run:
	./$(EXEC)



.PHONY: check
check:
	valgrind --leak-check=full ./$(EXEC)
