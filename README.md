# Heap
Max heap simulation (see [source](http://robin-thomas.github.io/max-heap/)).<br/>
The nodes of the heap contains the id and the amount of money of a bank's customer. Every time a customer deposits money, we insert a new node in the heap, if he is a new customer, or we update an existing node in the heap by adding the money in the total of amount of money, if he is an existing customer.<br/>

Written in C, Ubuntu 16.04.3 LTS

## Makefile
 - `make` to compile
 - `make clean` to delete the object files and the executable
 - `make run` to execute the program
 - `make check` to run valgrind to check for memory leaks.
