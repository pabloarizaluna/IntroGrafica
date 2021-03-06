#include "track_lab.h"

void draw_room(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  )
{

  glPushMatrix();
  glColor3fv( white );

  glTranslatef( x, y, z );
  glScalef( width, height, depth );
  glutSolidCube( 1.0 );
  glPopMatrix();

  glPushMatrix();
  glColor3f( 0.0, 0.0, 0.0 );

  glTranslatef( x, y, z );
  glScalef( width - width * 0.01 , height - height * 0.01, depth - depth * 0.01 );
  glutWireCube( 1.0 );
  glPopMatrix();

  glPushMatrix();
  glColor3fv( blue );

  glTranslatef( x - width * 0.25, y - height * 0.5, z );
  glScalef( width * 0.2, 100.0, depth * 0.75 );
  glutSolidCube( 1.0 );
  glPopMatrix();

  //left
  draw_walls(
    x - width * 0.5, y, z - height * 0.25, 800.0, height, depth * 0.25
  );

  draw_walls(
    x - width * 0.5, y, z + height * 0.25, 800.0, height, depth * 0.25
  );

  //rigth
  draw_walls(
    x + width * 0.5, y, z + height * 0.25, 800.0, height, depth * 0.25
  );

  draw_walls(
    x + width * 0.5, y, z - height * 0.25, 800.0, height, depth * 0.25
  );

  draw_door(
    x - width * 0.20, y - height * 0.35, z + depth * 0.5, width * 0.2, height,
    depth * 0.05
    );
  draw_window(
    x + width * 0.20, y, z + depth * 0.5, width * 0.5, height * 0.4, depth * 0.05
    );

  //back
  draw_walls(
    x, y, z - depth * 0.5, width * 0.25, height, 800.0
  );

  draw_walls(
    x + width * 0.3, y, z - depth * 0.5, width * 0.25, height, 800.0
  );

  draw_walls(
    x - width * 0.3, y, z - depth * 0.5, width * 0.25, height, 800.0
  );

  glPushMatrix();
  glColor3fv( white );

  glTranslatef( x, y + height * 0.55, z );
  glScalef( width * 0.1, height * 0.09, depth * 0.1 );
  glRotatef( 90.0, 1, 0, 0 );

  GLUquadricObj *focus = gluNewQuadric();
  gluQuadricDrawStyle( focus, GLU_FILL );
  gluCylinder( focus, 1.0, 1.0, 1.0, 5, 5 );
  glPopMatrix();

  glPushMatrix();
  glColor3f( 0.0, 0.0, 0.0 );

  glTranslatef( x, y + height * 0.55, z );
  glScalef( width * 0.112, height * 0.091, depth * 0.112 );
  glRotatef( 90.0, 1, 0, 0 );

  gluQuadricDrawStyle( focus, GLU_FILL );
  gluCylinder( focus, 1.0, 1.0, 1.0, 5, 5 );
  glPopMatrix();
}

void draw_walls(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  )
{
  glPushMatrix();
  glColor3fv( blue );

  glTranslatef( x, y, z );
  glScalef( width, height, depth );
  glutSolidCube( 1.0 );
  glPopMatrix();
}

void draw_door(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  )
{
  glPushMatrix();
  glColor3f( 0.0, 0.0, 0.0 );

  glTranslatef( x, y, z );
  glScalef( width, height, depth );
  glutSolidCube( 1.0 );
  glPopMatrix();

}

void draw_window(
  GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height, GLfloat depth
  )
{
  glPushMatrix();
  glColor3fv( white_blue );

  glTranslatef( x, y, z );
  glScalef( width, height, depth );
  glutSolidCube( 1.0 );
  glPopMatrix();
}

void drawLimb( float x, float y, float z, float angle, char axis, int base, int height, bool needsMarker ) {
    glPushMatrix( );

    glTranslatef( x, y, z );
    if( needsMarker == true ) {
        glColor3f( 0.0f, 1.0f, 0.0f );
        glutWireSphere( 50, 10, 10 );
    }

    if( axis == 'x' ) {
        glRotatef( angle, 1.0f, 0.0f, 0.0f );
    }
    else if( axis == 'y' ) {
        glRotatef( angle, 0.0f, 1.0f, 0.0f );
    }
    else if( axis == 'z' ) {
        glRotatef( angle, 0.0f, 0.0f, 1.0f );
    }

    glRotatef( 90.0, 0.0, 1.0, 0.0 );

    glColor3f( 1.0f, 0.0f, 0.0f );
    glutWireCone( base, height/3, 20, 20 );

    glRotatef( 180.0, 0.0f, 1.0f, 0.0f );

    glutWireCone( base, 2*(height/3), 20, 20 );

    glPopMatrix( );
}

void drawSphere( float x, float y, float z, int radius ) {
    glColor3f( 1.0, 1.0, 0.0 );
    glPushMatrix( );

    glTranslatef( x, y, z );

    glutWireSphere( radius, 10, 10 );

    glPopMatrix( );
}

void draw_subject( float x, float y, float z ) {
    // Head
    drawLimb( 0.0 + x, 500.0 + y, 0.0 + z, 90.0, 'z', 250, 750, false );
    drawSphere( 0.0 + x, 0.0 + y, 0.0 + z, 50 );

    // Right Arm
    drawLimb( -288.0 + x, -167.0 + y, 0.0 + z, 30.0, 'z', 100, 1000, false );
    drawSphere( -866.0 + x, -500.0 + y, 0.0 + z, 50 );
    drawLimb( -866.0 + x, -750.0 + y, 0.0 + z, 90.0, 'z', 100, 750, false );
    drawSphere( -866.0 + x, -1250.0 + y, 0.0 + z, 50 );

    // Left Arm
    drawLimb( 288.0 + x, -167.0 + y, 0.0 + z, 150.0, 'z', 100, 1000, false );
    drawSphere( 866.0 + x, -500.0 + y, 0.0 + z, 50 );
    drawLimb( 866.0 + x, -750.0 + y, 0.0 + z, 90.0, 'z', 100, 750, false );
    drawSphere( 866 + x, -1250.0 + y, 0.0 + z, 50 );

    // Chest
    drawLimb( 0.0 + x, -500.0 + y, 0.0 + z, 90.0, 'z', 300, 1500, false );
    drawSphere( 0.0 + x, -1500.0 + y, 0.0 + z, 50 );

    // Pelvis
    drawSphere( -100.0 + x, -1400.0 + y, 50.0 + z, 50 );
    drawSphere( 100.0 + x, -1400.0 + y, 50.0 + z, 50 );
    drawSphere( -250.0 + x, -1600.0 + y, -50.0 + z, 50 );
    drawSphere( 250.0 + x, -1600.0 + y, -50.0 + z, 50 );

    // Right Leg
    drawLimb( -239.0 + x, -1842.0 + y, 0.0 + z, 55.0, 'z', 175, 1250, true );
    drawSphere( -717.0 + x, -2524.0 + y, 0.0 + z, 50 );
    drawLimb( -717.0 + x, -2857.0 + y, 0.0 + z, 90.0, 'z', 125, 1000, true );
    drawSphere( -717.0 + x, -3524.0 + y, 0.0 + z, 50 );
    drawLimb( -717.0 + x, -3524.0 + y, -133.0 + z, 270.0, 'y', 75, 400, true );

    // Left Leg
    drawLimb( 239.0 + x, -1842.0 + y, 0.0, 125.0 + z, 'z', 175, 1250, true );
    drawSphere( 717.0 + x, -2524.0 + y, 0.0 + z, 50 );
    drawLimb( 717.0 + x, -2857.0 + y, 0.0 + z, 90.0, 'z', 125, 1000, true );
    drawSphere( 717.0 + x, -3524.0 + y, 0.0 + z, 50 );
    drawLimb( 717.0 + x, -3524.0 + y, -133.0 + z, 270.0, 'y', 75, 400, true );
}
