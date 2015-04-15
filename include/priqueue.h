//Chris Leete and Sam Goldberg
//priqueue.h

#ifndef PRIQUEUE_H

#define PRIQUEUE_H

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	mSurf *surfaces;
	int size;
	int initFlag;
} queue;

queue* queue_create(void);
void subdivision(queue *q);
void ordered_insert(mSurf surf, queue * q);
void replace_surface(int idx, mSurf surf1, mSurf surf2, mSurf surf3, mSurf surf4, queue *q);
void quickSort( queue *q, int l, int r);
int partition( queue *q, int l, int r);



#endif