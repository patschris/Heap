#ifndef __heap__
#define __heap__


#define LCHILD(x) 2*x+1 // left child of parent x
#define RCHILD(x) 2*x+2 // right child of parent x
#define PARENT(x) (x-1)/2 // parent of node x


/* Heap's node. Contains an identity number(id) and an amount of money(value) */
typedef struct node {
	char *id;    
	float value;
} node;


/* Max Heap */
typedef struct maxHeap {
    int size; /* size of heap (total amount of nodes) */
    node *elem; /* First element of the heap */
} maxHeap;


/* Heap's functions prototypes */
maxHeap initMaxHeap ();
int search (maxHeap *, char *);
void insertNode (maxHeap *, char *, float);
void swap(node *, node *);
void heapify (maxHeap *, int);
void deleteNode (maxHeap *);
void destroyHeap (maxHeap *);
void printLevelOrderTraversal (maxHeap *);

#endif
