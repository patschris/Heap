#include <stdio.h>
#include "heap.h"


int main(void) {

    printf("Max heap simulation\n\n");
	maxHeap hp = initMaxHeap();

	insertNode (&hp, "012345678", 1000);
	printLevelOrderTraversal(&hp);

	insertNode (&hp, "123456789", 1050);
	printLevelOrderTraversal(&hp);
	
	insertNode (&hp, "485555551", 1112);
	printLevelOrderTraversal(&hp);

	insertNode (&hp, "123456789", 3322);
	printLevelOrderTraversal(&hp);	


	insertNode (&hp, "234567891", 3);
	printLevelOrderTraversal(&hp);	

	insertNode (&hp, "234567891", 5000);
	printLevelOrderTraversal(&hp);	

	destroyHeap(&hp);
	return 0;
}
