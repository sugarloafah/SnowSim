#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

/* Implementation and functions based off of resources found 
/ at http://ksolek.fm.interiowo.pl/Blender/
*/
GLuint *vbo;
GLuint *indices;

void InitMesh() {

  vbo = (GLuint *)malloc(OBJECTS_COUNT * sizeof(GLuint));
  indices = (GLuint *)malloc(OBJECTS_COUNT * sizeof(GLuint));

  glGenBuffers(OBJECTS_COUNT, vbo);
  int i;
  for (i=0; i<OBJECTS_COUNT; i++) {	
	  glBindBuffer(GL_ARRAY_BUFFER, vbo[i]);
	  glBufferData(GL_ARRAY_BUFFER, sizeof (struct vertex_struct) * vertex_count[i], &vertices[vertex_offset_table[i]], GL_STATIC_DRAW);
	  glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

  glGenBuffers(OBJECTS_COUNT, indices);
  for (i=0; i<OBJECTS_COUNT; i++) {	
	  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices[i]);
	  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (indexes[0]) * faces_count[i] * 3, &indexes[indices_offset_table[i]], GL_STATIC_DRAW);
	  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  }
}

#define BUFFER_OFFSET(x)((char *)NULL+(x))

void DrawMesh(int index, int apply_transformations) {
	if (apply_transformations) {
	  glPushMatrix();
		glMultMatrixf(transformations[index]);
	}
	glBindBuffer(GL_ARRAY_BUFFER, vbo[index]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices[index]);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(0));
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, sizeof (struct vertex_struct), BUFFER_OFFSET(3 * sizeof(float)));
	glDrawElements(GL_TRIANGLES, faces_count[index] * 3, INX_TYPE, BUFFER_OFFSET(0));
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	if (apply_transformations)
		glPopMatrix();
}

void DrawMeshes()
{
	unsigned int i;
	for (i=0; i<2500; i++) { //num verticies, hardcoded for HAT
		//Torus
		if (i==0 || i==1 || i==22 || i==23 || i== 27 || i== 28 || i== 32 || i== 33 || i== 37 || i== 38){
		glColor3f(0.3,0.3,0.3);
		}
		//Cube
		if (i==2 || i== 4 || i== 5 || i== 6 || i== 7 || i== 8 || i== 9 || i== 10 || i== 11 || i== 12 || i== 13 || i== 15 || i== 20 || i== 25 || i== 30 || i== 35){
		  glColor3f(0.3,0.3,0.3);
		}
		//Cone
		if (i==3 || i== 19 || i== 24 || i== 29 || i== 34){
		  glColor3f(0.3,0.3,0.3);
		}
		//Sphere
		if (i==14 || i== 21 || i== 26 || i== 31 || i== 36){
		  glColor3f(0.3,0.3,0.3);
		}
		//Cylinder
		if (i== 16){
		  glColor3f(0.1,0.9,0.1);
		}
		if (i== 17){
		  glColor3f(0.1,0.1,0.9);
		}
		if (i==18){
		  glColor3f(0.1,0.9,0.1);
		}

		DrawMesh(i, 1);
	}
}

