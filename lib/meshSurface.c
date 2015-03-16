//Chris Leete & Sam Goldberg
//meshSurface.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "meshSurface.h"

//mSurf (mesh Surface)
mSurf * mSurf_create(Point *a, Point *b, Point *c){
	mSurf *surf = (mSurf *) malloc(sizeof(mSurf));
	point_copy( &(surf->vertex[0]), a);
	point_copy( &(surf->vertex[1]), b);
	point_copy( &(surf->vertex[2]), c);
	mSurf_updateSize(surf);
	surf->count=0;
	return surf;
}
void mSurf_appendParticles(mSurf *surf, int numParticles){
	surf->count = surf->count+1;
	return;

}
void mSurf_updateNeighbors(mSurf *surf){
	return;

}

void mSurf_updatePriority(mSurf *surf){
	float val = surf->count + (100 - surf->size);
	surf->priVal = val;
	return;

}

void mSurf_updateSize(mSurf *surf){
	Point a;
	Point b;
	Point c;
	point_copy( &a, &(surf->vertex[0]));
	point_copy( &b, &(surf->vertex[1]));
	point_copy( &c, &(surf->vertex[2]));
	double area2 = (a.val[0]*(b.val[1]-c.val[1])) + (b.val[0]*(c.val[1]-a.val[1])) + (c.val[0]*(a.val[1]-b.val[1]));
	double area = abs(area2/2);
	surf->size = area;

}

//Point
void point_set(Point * p, double x, double y, double z){
	p->val[0]=x;
	p->val[1]=y;
	p->val[2]=z;
}

void point_copy(Point *to, Point *from){
	to->val[0] = from->val[0];
	to->val[1] = from->val[1];
	to->val[2] = from->val[2];
}
