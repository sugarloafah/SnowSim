//Sam Goldberg and Chris Leete
//queueTest.c



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "meshSurface.h"
#include "priqueue.h"

int main(int argc, char *argv[]) {
	queue * q = queue_create();
	printf("size should equal 2 = %u \n", q->size );
    printf("First element prival = %f \n", q->surfaces[0].priVal );
	subdivision(q);
	printf("size post subdivision should equal 5 = %u \n", q->size );
    printf("First element prival after subdivision = %f \n", q->surfaces[0].priVal );
  	
  	printf("%u \n", q->size);
	return 0;
}

//int main(int argc, char *argv[]) 
    /*
    int a[] = { 7, 12, 1, -2, 0, 15, 4, 11, 9};

    int i;
    printf("\n\nUnsorted array is:  ");
    for(i = 0; i < 9; ++i){
        printf(" %d ", a[i]);
    }
    quickSort( a, 0, 8);

    printf("\n\nSorted array is:  ");
    for(i = 0; i < 9; ++i){
        printf(" %d ", a[i]);
    }
    ordered_insert(3, a, 9);

    printf("\n\nSorted array is:  ");
    for(i = 0; i < 9; ++i){
        printf(" %d ", a[i]);
    }
    */
