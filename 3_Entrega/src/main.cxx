#include <iostream>

#include <GL/freeglut.h>
#include <GL/gl.h>
#include "track_lab.h"

int paused = 0;

GLfloat width;
GLfloat height;
GLfloat iteration;

GLdouble eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ;

GLdouble eye_1_X = 1461.0, eye_1_Y = -5000.0, eye_1_Z = 483.0;
GLdouble center_1_X = 1461, center_1_Y = 0, center_1_Z = 483;
GLdouble up_1_X = 0, up_1_Y = 0, up_1_Z = 1;

GLdouble eye_2_X = 5000, eye_2_Y = 800, eye_2_Z = 700;
GLdouble center_2_X = -224.5, center_2_Y = 800, center_2_Z = 700;
GLdouble up_2_X = 0, up_2_Y = 0, up_2_Z = 1;

GLdouble eye_3_X = 1461, eye_3_Y = 526, eye_3_Z = 5000;
GLdouble center_3_X = 1461, center_3_Y = 526, center_3_Z = 0;
GLdouble up_3_X = 0, up_3_Y = 1, up_3_Z = 0;

void init()
{
  iteration = 0;
  glClearColor( 1.0, 1.0, 1.0, 0.0 );
  width = 680;
  height = 480;
  glEnable( GL_DEPTH_TEST );

  eyeX = eye_1_X;
  eyeY = eye_1_Y;
  eyeZ = eye_1_Z;
  centerX = center_1_X;
  centerY = center_1_Y;
  centerZ = center_1_Z;
  upX = up_1_X;
  upY = up_1_Y;
  upZ = up_1_Z;
}

void display()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glLoadIdentity();

  gluLookAt( eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ );

  glPushMatrix();
  glColor3f( 0, 1, 1 );
  glBegin( GL_QUADS );
    glVertex3i( -475, 329, 5 );
    glVertex3i( -475, 949, 5 );
    glVertex3i( 3495, 949, 5 );
    glVertex3i( 3495, 329, 5 );
  glEnd();
  glPopMatrix();

  drawMarkers( iteration );
  drawConnectors( iteration );

  glPushMatrix();
  glRotatef( 90, 1, 0, 0 );
  draw_room( 1454, 2375, 490, 7900, 5250, 10000 );
  glPopMatrix();

  glutSwapBuffers();
}

void reshape(int n_width, int n_height)
{
  glViewport( 0.0, 0.0, width, height );
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();

  gluPerspective( 60.0f, ( GLfloat ) n_width / ( GLfloat ) n_height, 1.0f, 10000.0f );

  glMatrixMode( GL_MODELVIEW );

  width = n_width;
  height = n_height;
}

void timer( int value ) {
    if( paused != 0 ) {
        iteration += 1;
    }

    glutPostRedisplay( );
    glutTimerFunc( 1000.0/ 60.0, timer, 0 );
}

void keyboard( unsigned char key, int x, int y )
{
  switch(key)
  {
    case 'q': case 'Q': case 27:
      exit(0);
    break;
    case '1':
      eyeX = eye_1_X;
      eyeY = eye_1_Y;
      eyeZ = eye_1_Z;
      centerX = center_1_X;
      centerY = center_1_Y;
      centerZ = center_1_Z;
      upX = up_1_X;
      upY = up_1_Y;
      upZ = up_1_Z;
    break;
    case '2':
      eyeX = eye_2_X;
      eyeY = eye_2_Y;
      eyeZ = eye_2_Z;
      centerX = center_2_X;
      centerY = center_2_Y;
      centerZ = center_2_Z;
      upX = up_2_X;
      upY = up_2_Y;
      upZ = up_2_Z;
    break;
    case '3':
      eyeX = eye_3_X;
      eyeY = eye_3_Y;
      eyeZ = eye_3_Z;
      centerX = center_3_X;
      centerY = center_3_Y;
      centerZ = center_3_Z;
      upX = up_3_X;
      upY = up_3_Y;
      upZ = up_3_Z;
    break;
    case 'p': case 'P':
      paused = ( paused + 1 ) % 2;
    break;
    case 'r': case 'R':
        iteration = 0;
    break;
  }

  glutPostRedisplay();
}

int main( int argc, char* argv[] )
{
  glutInit( &argc, argv );

  if( argc != 2 ) {
      std::cout << "Error de ejecucion - Modo de uso: ./track_lab archivo_entrada" << std::endl;
      exit( 1 );
  }

  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowPosition( 100, 100 );
  glutInitWindowSize( 640, 480 );
  glutCreateWindow( "Track Lab" );
  loadFile( argv[ 1 ] );
  init();
  glutDisplayFunc( display );
  glutReshapeFunc( reshape );
  glutTimerFunc( 1000.0 / 60.0, timer, 0 );
  glutKeyboardFunc( keyboard );
  glutMainLoop();

  return 0;
}
