#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meshSurface.h"


int main(int argc, char *argv[]) 
{
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
}

queue* queue_create(){
  queue *q = (queue *) malloc(sizeof(queue));
  q->surfaces = (mSurf) malloc(sizeof(mSurf)*150);
  q->size = 150;
  return q;

}
void queue_init(queue *q){
  Point a;
  Point b;
  Point c;
  Point d;
  point_set( &a, -1,-1,0);
  point_set( &b, -1,1,0);
  point_set( &c, 1,1,0);
  point_set( &d, 1, -1, 0);
  mSurf *lTri = mSurf_create(&a, &b, &d);
  mSurf *rTri = mSurf_create(&ab, &c, &d);
  ordered_insert(lTri, q);
  ordered_insert(rTri, q);

}

void ordered_insert(mSurf *surf,queue *q){
 int i=0;
 int index;
 while(surf->priVal > q->surfaces[i]){
   i++;}

//push the rest to right by one
index=i;

i = 150;
while ( i > index ) {
  a[i] = a[i-1];
  i--;
}
a[i] = number;
size++;

}

void quickSort( queue* q, int l, int r)
{
   int j;

   if( l < r ) 
   {
    // divide and conquer
        j = partition( q, l, r);
       quickSort( q, l, j-1);
       quickSort( q, j+1, r);
   }
    
}



int partition( queue* q, int l, int r) {
   int pivot, i, j, t;
   pivot = q->surfaces[l].priVal;
   i = l; j = r+1;
        
   while( 1)
   {
    do ++i; while( q->surfaces[i].priVal <= pivot && i <= r );
    do --j; while( q->surfaces[j].priVal > pivot );
    if( i >= j ) break;
    t = q->surfaces[i].priVal; q->surfaces[i].priVal = q->surfaces[j].priVal; q->surfaces[j].priVal = t;
   }
   t = q->surfaces[l].priVal; q->surfaces[l].priVal = q->surfaces[j].priVal; q->surfaces[j].priVal = t;
   return j;
}
