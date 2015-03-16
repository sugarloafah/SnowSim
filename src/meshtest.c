//Sam Goldberg and Chris Leete
//meshTest.c



#include <stdio.h>
#include "meshSurface.h"

int main(int argc, char *argv[]) {
	Point a;
	Point b;
	Point c;
	Point d;
	point_set( &a, 0,0,0);
	point_set( &b, 0,10,0);
	point_set( &c, 10,0,0);
	point_set( &d, 10, 10, 0);
	mSurf *test = mSurf_create(&a, &b, &c);
	mSurf *test1 = mSurf_create(&d, &b, &c);
	printf("check c's x (should equal 5) = %f \n", test->vertex[2].val[0]);
	printf("size of surface is %f \n", test->size);
	mSurf_updatePriority(test);
	printf("priVal = %f \n", test->priVal);
	mSurf_appendParticles(test, 5);
	mSurf_updatePriority(test);
	printf("priVal After shooting particles = %f \n", test->priVal);
	mSurf queue[50];
	ordered_insert(test->priVal, test, 0);
	return 0;
}