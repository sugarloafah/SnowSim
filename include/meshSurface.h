//Chris Leete and Sam Goldberg
//meshSurface.h

#ifndef MESHSURFACE_H

#define MESHSURFACE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double val[3];
} Point;


typedef struct {
	Point vertex[3];
	int countParticlesShot;
	double size;
	float priVal;
	int count;
} mSurf;


//mSurf (mesh Surface)
mSurf * mSurf_create(Point *a, Point *b, Point *c);
void mSurf_appendParticles(mSurf * surf, int numParticles);
void mSurf_updateNeighbors(mSurf *surf);
void mSurf_updateSize(mSurf *surf);
void mSurf_updatePriority(mSurf *surf);

//Point
void point_set(Point *p, double x, double y, double z);
void point_copy(Point *to, Point *from);


#endif