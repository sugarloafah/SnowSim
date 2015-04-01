//Sam Goldberg and Chris Leete
//queueTest.c



#include <stdio.h>
#include "meshSurface.h"
#include "priqueue.h"

int main(int argc, char *argv[]) {
	queue * q = queue_create();
	printf("this should equal 2 = %f \n", q->size );
	subdivision(q);
	printf("this should equal 5 = %f \n", q->size );
  	
  	printf("%f \n", q->size);
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
