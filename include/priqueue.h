//Chris Leete and Sam Goldberg
//priqueue.h

#ifndef PRIQUEUE_H

#define PRIQUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	mSurf surfaces[150];
	int size;
	int initFlag;
} queue;

queue* queue_create();
void queue_init(queue *q); 
void ordered_insert(mSurf * surf, queue * q);
void quickSort( queue *q, int l, int r);
int partition( queue *q, int l, int r);



#endif