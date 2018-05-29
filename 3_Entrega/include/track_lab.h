#ifndef __TRACK_LAB_H__
#define __TRACK_LAB_H__

#include <cmath>

#include <GL/freeglut.h>
#include <GL/gl.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

const GLfloat white[3] = { 1.0, 1.0, 1.0 };
const GLfloat blue[3] = { 92.0 / 255.0, 118.0 / 255.0, 232.0 / 255.0 };
const GLfloat purple[3] = { 115.0 / 255.0, 6.0 / 255.0, 255.0 / 255.0 };
const GLfloat green[3] = { 17.0 / 255.0, 232.0 / 255.0, 136.0 / 255.0 };
const GLfloat white_blue[3] = { 6.0 / 255.0, 206.0 / 255.0, 255.0 / 255.0 };

void draw_room(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  );
void draw_walls(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  );
void draw_door(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
);
void draw_window(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  );
void drawLimb( float x, float y, float z, float angle, char axis, int base, int height );
void drawSphere( float x, float y, float z, int radius );
void draw_subject( float x, float y, float z );
void verifyMarkers( );
void drawMarkers( int actualIt );
void loadFile( char* filename );
void drawConnectors( int actualIt );

/**
    Render Cylinder Between Points Source
    https://github.com/curran/renderCyliner/blob/master/renderCylinder.c
*/
void renderCylinderDirector(float x1, float y1, float z1, float x2,float y2, float z2, float radius,int subdivisions);
void renderCylinder(float x1, float y1, float z1, float x2,float y2, float z2, float radius,int subdivisions,GLUquadricObj *quadric);

#endif
