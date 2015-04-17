#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meshSurface.h"
#include "priqueue.h"
#include "hat.h"

static Point hat_points[12]; //IN this order (cminX, cmaxX, cminY, cmaxY, cminZ, cmaxZ, tminX, tmaxX, tminY, tmaxY, tminZ, tmaxZ)


queue* queue_create(){
  queue *q = (queue *) malloc(sizeof(queue));
  q->size = 0;
  Point a;
  Point b;
  Point c;
  Point d;
  point_set( &a, 0,0,0);
  point_set( &b, 0,1,0);
  point_set( &c, 1,1,0);
  point_set( &d, 1, 0, 0);
  q->initFlag = 0;
  mSurf *lTri = mSurf_create(&b, &a, &d); //Start from top left vertex, rotate clockwise
  mSurf *rTri = mSurf_create(&b, &c, &d);
  q->surfaces = (mSurf *) malloc(sizeof(mSurf)*150);
  ordered_insert(*lTri, q);
  q->initFlag = 1;
  ordered_insert(*rTri, q);
  q->size = 2;
 
  return q;
}

void subdivision(queue * q){
  Point a;
  Point b;
  Point c;
  Point d;
  Point e;
  Point f;
  point_copy(&a, &q->surfaces[0].vertex[0]);
  point_copy(&c, &q->surfaces[0].vertex[1]);
  point_copy(&e, &q->surfaces[0].vertex[2]);
  mSurf *Tri0;
  mSurf *Tri1;
  mSurf *Tri2;
  mSurf *Tri3;
  if( a.val[0] == e.val[0]){ //(left right tri) 
    b.val[0] = (a.val[0] + c.val[0]) /2.0;
    b.val[1] = (a.val[1] + c.val[1]) /2.0;
    d.val[1] = e.val[1] ;
    d.val[0] = (a.val[0] + c.val[0]) /2.0;
    f.val[0] = a.val[0];
    f.val[1] = (a.val[1] + e.val[1]) /2.0;
    Tri0 = mSurf_create(&a, &b, &f);
    Tri1 = mSurf_create(&b, &c, &d);
    Tri2 = mSurf_create(&f, &d, &e);
    Tri3 = mSurf_create(&f, &b, &d);
  }
  else{ //(right right tri)
    b.val[1] = a.val[1];
    b.val[0] = (a.val[0] + c.val[0]) /2.0;
    d.val[1] = (c.val[1] + e.val[1]) /2.0;
    d.val[0] = c.val[0];
    f.val[1] = (a.val[1] + e.val[1]) /2.0;
    f.val[0] = (a.val[0] + e.val[0]) /2.0;
    Tri0 = mSurf_create(&a, &b, &f);
    Tri1 = mSurf_create(&b, &c, &d);
    Tri2 = mSurf_create(&f, &d, &e);
    Tri3 = mSurf_create(&b, &d, &f);
  }
  replace_surface(0, *Tri0, *Tri1, *Tri2, *Tri3, q);
}

void replace_surface(int idx, mSurf surf1, mSurf surf2, mSurf surf3, mSurf surf4, queue *q){
  while ( idx < q->size ) {
    q->surfaces[idx] = q->surfaces[idx+1];
    idx++;
  }
  q->size--;
  ordered_insert(surf1, q);
  ordered_insert(surf2, q);
  ordered_insert(surf3, q);
  ordered_insert(surf4, q);
}


void ordered_insert(mSurf surf,queue *q){
 int i=0;
 int index;
 if (q->size == 0){
  q->surfaces[0] = surf;
  q->size = 1;
 }
 else{
   if (q->initFlag == 1){
      while(surf.priVal > q->surfaces[i].priVal){
        i++;}
    }

  //push the rest to right by one
  index=i;

  i = q->size;
  while ( i > index ) {
    q->surfaces[i] = q->surfaces[i+1];
    i--;
  }
  q->surfaces[i] = surf;
  q->size++;
  }
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

void createBoundingBox_Hat(){
  float cminX, cmaxX, cminY, cmaxY, cminZ, cmaxZ, tminX, tmaxX, tminY, tmaxY, tminZ, tmaxZ;
  cminX = 1.0;
  cminY = 1.0;
  cminZ = 1.0;
  tminX = 1.0;
  tminY = 1.0;
  tminZ = 1.0;
  cmaxX = 0.0;
  cmaxY = 0.0;
  cmaxZ = 0.0;
  tmaxX = 0.0;
  tmaxY = 0.0;
  tmaxZ = 0.0;
  for (i=0; i<2500; i++) { //num verticies, Hardcoded for HAT
    if (i = vertex_offset_table[1]){ //cylander
      if(verticies[i].x > cmaxX){
        cmaxX = verticies[i].x;
      }
      if(verticies[i].x < cminX){
        cminX = verticies[i].x;
      }
      if(verticies[i].y > cmaxY){
        cmaxY = verticies[i].y;
      }
      if(verticies[i].y < cminY){
        cminY = verticies[i].y;
      }
      if(verticies[i].z > cmaxZ){
        cmaxZ = verticies[i].z;
      }
      if(verticies[i].z < cminZ){
        cminZ = verticies[i].z;
      }
    }
    if (i = vertex_offset_table[2]){ //torus
      if(verticies[i].x > tmaxX){
        tmaxX = verticies[i].x;
      }
      if(verticies[i].x < tminX){
        tminX = verticies[i].x;
      }
      if(verticies[i].y > tmaxY){
        tmaxY = verticies[i].y;
      }
      if(verticies[i].y < tminY){
        tminY = verticies[i].y;
      }
      if(verticies[i].z > tmaxZ){
        tmaxZ = verticies[i].z;
      }
      if(verticies[i].z < tminZ){
        tminZ = verticies[i].z;
      }
    }
  }

}