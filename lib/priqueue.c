#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meshSurface.h"


int main(int argc, char *argv[]) 
{
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
}

queue* queue_create(){
  queue *q = (queue *) malloc(sizeof(queue));

}
void queue_init(queue q){
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

}

void ordered_insert(int number,int a[],int size){
 int i=0;
 int index;
 while(number>a[i]){
   i++;}

//push the rest to right by one
index=i;

i = size;
while ( i > index ) {
  a[i] = a[i-1];
  i--;
}
a[i] = number;
size++;

}

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
    // divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
    
}



int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
        
   while( 1)
   {
    do ++i; while( a[i] <= pivot && i <= r );
    do --j; while( a[j] > pivot );
    if( i >= j ) break;
    t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}
