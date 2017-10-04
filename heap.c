#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"


/* Creates a new empty MaxHeap */
maxHeap initMaxHeap () {
    maxHeap hp;
    hp.size = 0;
    hp.elem = NULL;
    return hp;
}


/*  Returns the position of the node that contains the customer with id equal to str.
    If there is no node with such phone number, returns -1. */
int search (maxHeap *hp, char *str) {
	int i, pos;
	pos = -1;
    for(i = 0; i < hp->size; i++) {
		if (strcmp(hp->elem[i].id,str) == 0) return i;
    }
	return pos;
}


/*  Trying to insert a new node. 
    If the given ID belongs to an existing customer, we add the given money to the total amount of money
    If the given ID is the ID of a new customer, create and add the new node, place the node at the end of the heap and then find his proper position   */
void insertNode (maxHeap *hp, char *str, float val) {
	int i, pos;
	node nd;
	pos = search (hp, str);
	if (pos != -1) {
        printf("ID %s belongs to an existing customer\nI am going to add %.2f euros in the total amount of money\n", str, val);
		hp->elem[pos].value = hp->elem[pos].value + val;		
		while(pos && hp->elem[pos].value > hp->elem[PARENT(pos)].value) {
			swap(&(hp->elem[pos]), &(hp->elem[PARENT(pos)]));
			pos = PARENT(pos);
    	}
	}
    else {
        printf("I am going to add a new node with ID: %s and amount of money: %.2f\n", str, val);
        if(hp->size) 
            hp->elem = realloc(hp->elem, (hp->size + 1) * sizeof(node)); // allocating space
	    else 
            hp->elem = malloc(sizeof(node));
	    hp->size++;
        // initializing the node
        nd.value = val;
	    nd.id = (char *) malloc ((strlen(str)+1)*sizeof(char));
	    strcpy(nd.id,str);
        // Find the proper position of the node
        i = hp->size - 1;
	    while(i && nd.value > hp->elem[PARENT(i)].value) {
            hp->elem[i] = hp->elem[PARENT(i)];
            i = PARENT(i);
        }
        hp->elem[i] = nd;
    }
}


/* Swap to nodes */
void swap (node *n1, node *n2) {
    node temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}


/* Is called recursively to make sure that heap property is satisfied */
void heapify (maxHeap *hp, int i) {
    int largest = (LCHILD(i) < hp->size && hp->elem[LCHILD(i)].value > hp->elem[i].value) ? LCHILD(i) : i ;
    if(RCHILD(i) < hp->size && hp->elem[RCHILD(i)].value > hp->elem[largest].value) {
        largest = RCHILD(i);
    }
    if(largest != i) {
        swap(&(hp->elem[i]), &(hp->elem[largest]));
        heapify(hp, largest);
    }
}


/* Deletes the first node, places last node in the first position, decreases by one the size of the heap and reduces the allocated mempry by one node. Calls heapify to make sure that heap property is satisfied. */
void deleteNode (maxHeap *hp) {
    if(hp->size) {
		free(hp->elem[0].id);        
		hp->size --;
		hp->elem[0] = hp->elem[hp->size];
        hp->elem = realloc(hp->elem, hp->size * sizeof(node));
        heapify(hp, 0);
    } 
}


/* Deletes first node until there is no node in the heap */
void destroyHeap (maxHeap *hp) {
    while (hp->size) deleteNode(hp);
}


/* Prints the heap level by level */
void printLevelOrderTraversal(maxHeap *hp) {
    int i;
    printf("Heap's state\n");    
    for(i = 0; i < hp->size; i++) {
        printf("%s : %.2f\n", hp->elem[i].id, hp->elem[i].value);
    }
	printf("\n\n");
}
