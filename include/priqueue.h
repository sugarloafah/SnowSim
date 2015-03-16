//Chris Leete and Sam Goldberg
//priqueue.h

#ifndef PRIQUEUE_H

#define PRIQUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	mSurf surfaces[150];
} queue;

queue* queue_create();
void queue_init(queue q); 
void ordered_insert(int number,int a[],int size);
void quickSort( int a[], int l, int r);
int partition( int a[], int l, int r);



#endif